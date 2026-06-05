`default_nettype none
import frame_pkg::*;

`define NUM_TESTS           10
`define HASH_LEN            32'd5
`define REPEAT_COUNTER_LEN  32'd4
`define RAW_WORD_LEN        32'd32

module tb_process_frame_top();
    logic                       clk_i;
    logic                       rst_ni;
    logic [`RAW_WORD_LEN-1:0]   data_i;
    generic_frame_struct_t      frame_o;
    logic                       ready_for_new_data;
    logic                       data_valid_i;
    logic                       send_frame_o;
    logic                       frame_received_i;
    logic                       repeat_variable;
    logic [30:0]                unused_bits;
    logic [3:0]                 loop_count;

    process_frame_top #(.InpWidth(`RAW_WORD_LEN), .HashWidth(`HASH_LEN), .RepeatCounterWidth(`REPEAT_COUNTER_LEN))
                    DUT
                    (.clk_i(clk_i), .rst_ni(rst_ni), .data_i(data_i), .frame_o(frame_o),
                     .ready_for_new_data_o(ready_for_new_data), .data_valid_i(data_valid_i),
                     .send_frame_o(send_frame_o), .frame_received_i(frame_received_i));

    // Tasks for sending input data and receiving frames, to be used in the initial block for testing
    task send_input_data(input logic [`RAW_WORD_LEN-1:0] current_word);
        data_i <= current_word;
        data_valid_i <= 1;
        @(posedge clk_i);
        @(posedge clk_i iff (ready_for_new_data)); // wait for the frame to be ready before sending the next word
        data_valid_i <= 0;
    endtask

    task receive_frame();
        @(posedge clk_i iff (send_frame_o != 0)); // wait for a frame to be output
        $display("data word 0x%h --> frame 0x%h \
        --------- message received ---------\
        \
        ", data_i, frame_o);
        frame_received_i = 1; // signal that frame is successfully received
        @(posedge clk_i);
        frame_received_i = 0;
    endtask

    // Clock generation and reset, test sequence
    initial begin
        // verilator
        $dumpfile("wave.vcd");
        $dumpvars(0, tb_process_frame_top);

        // monitor + print outputs
        $monitor($time,,
            "data = %h, data_valid = %b, hash = %b \
            reg_data = %h, reg_hash = %h, fsm_counter = %d \
            s = %s, ns = %s, \
            hash_match(seen) = %b, save_hash_to_table = %b \
            \
            ",
            data_i, data_valid_i, DUT.hash,
            DUT.HASH_REGISTER.data_o, DUT.HASH_REGISTER.hash_o, DUT.counter,
            // ready_for_new_data, send_frame_o, frame_received_i, 
            DUT.FSM.current_state.name, DUT.FSM.next_state.name,
            DUT.hash_match,
            DUT.save_hash_to_table);

        // reset
        clk_i <= 0;
        rst_ni <= 0;
        forever #1 clk_i = ~clk_i;
    end

    initial begin
        // clock generation
        #2 rst_ni <= 1;

        // some simple edge cases
        data_i = 32'h0;
        send_input_data(data_i);
        receive_frame();

        data_i = 32'h0;
        send_input_data(data_i);
        receive_frame();

        data_i = 32'hFFFF_FFFF;
        send_input_data(data_i);
        receive_frame();

        data_i = 32'hDEAD_BEEF;
        send_input_data(data_i);
        receive_frame();

        // simulate some random streamed inputs
        repeat (`NUM_TESTS) begin
            data_i = $urandom_range(32'h0, 32'hFFFF_FFFF);
            send_input_data(data_i);
            receive_frame();

            // A random boolean to decide whether the next word is the same or not, and send again if so
            // To test counter
            loop_count = 0;
            {unused_bits, repeat_variable} = $urandom();
            while (repeat_variable && loop_count < 4) begin 
                $display("--------- repeating data ---------");
                send_input_data(data_i);
                receive_frame();
                loop_count = loop_count + 1;
            end 
        end

        #10;
        $finish;
    end

endmodule : tb_process_frame_top
