`default_nettype none
import frame_pkg::*;

`define NUM_TESTS           10
`define HASH_LEN            8
`define REPEAT_COUNTER_LEN  8
`define RAW_WORD_LEN        64
`define DATA_STREAM_LEN     2048ontr

module tb_process_frame_top();
    logic                       clk_i;
    logic                       rst_ni;
    logic [`RAW_WORD_LEN-1:0]   data_i;
    logic [`DATA_STREAM_LEN-1:0]  data_stream_i;
    generic_frame_struct_t      frame_o;
    logic                       ready_for_new_data;
    logic                       data_valid_i;
    logic                       send_frame_o;
    logic                       frame_received_i;
    logic                       repeat_variable;
    logic [30:0]                unused_bits;
    logic [3:0]                 loop_count;
    logic [`RAW_WORD_LEN-1:0]   receive_count;
    logic [`RAW_WORD_LEN-1:0]   send_count;

    process_frame_top #(.WordLen(`RAW_WORD_LEN), .StreamLen(`DATA_STREAM_LEN), .HashWidth(`HASH_LEN), .RepeatCounterWidth(`REPEAT_COUNTER_LEN))
                    DUT
                    (.clk_i(clk_i), .rst_ni(rst_ni), .data_stream_i(data_stream_i), .frame_o(frame_o),
                     .ready_for_new_data_o(ready_for_new_data), .data_valid_i(data_valid_i),
                     .send_frame_o(send_frame_o), .frame_received_i(frame_received_i));

    // Tasks for sending input data and receiving frames, to be used in the initial block for testing
    task add_input_data(input logic [`RAW_WORD_LEN-1:0] current_word);
        if (`RAW_WORD_LEN * (send_count + 1) < `DATA_STREAM_LEN) begin 
            data_i <= current_word;
            data_stream_i [$bits(`DATA_STREAM_LEN)'(send_count * `RAW_WORD_LEN) +: `RAW_WORD_LEN] = current_word;
            $display("adding %h at index %d\ ", current_word, send_count);
            send_count = send_count + 1;
        end 
    endtask

    task send_input_data();
        data_valid_i <= 1;
        @(posedge clk_i);
        // @(posedge clk_i iff (ready_for_new_data)); // wait for the frame to be ready before sending the next word
        // data_valid_i <= 0;
    endtask

    task receive_frame(input logic [`RAW_WORD_LEN-1:0] index);
        @(posedge clk_i iff (send_frame_o != 0)); // wait for a frame to be output

        $display("reg_data = %h, reg_hash = %h, fsm_counter = %d \
            s = %s, ns = %s, \
            hash_match(seen) = %b, save_hash_to_table = %b \
            frame = %h \
            \
            ",
            DUT.HASH_REGISTER.data_o, DUT.HASH_REGISTER.hash_o, DUT.counter,
            // ready_for_new_data, send_frame_o, frame_received_i, 
            DUT.FSM.current_state.name, DUT.FSM.next_state.name,
            DUT.hash_match,
            DUT.save_hash_to_table, 
            frame_o);
        
        @(posedge clk_i);
        frame_received_i = 1; // signal that frame is successfully received
        receive_count = receive_count + 1;
        @(posedge clk_i);
        frame_received_i = 0;
    endtask

    // Random number generator that works for bit width > 32
    function automatic logic [`RAW_WORD_LEN-1:0] rand_word();
        logic [`RAW_WORD_LEN-1:0] result;
        for (int i = 0; i < (`RAW_WORD_LEN + 31) / 32; i++)
            result[i*32 +: 32] = $urandom();  // fill 32 bits at a time
        return result;
    endfunction

    // Clock generation and reset, test sequence
    initial begin
        // verilator
        $dumpfile("wave.vcd");
        $dumpvars(0, tb_process_frame_top);

        // reset
        clk_i <= 0;
        rst_ni <= 0;
        send_count = 0;
        receive_count = 0;
        forever #1 clk_i = ~clk_i;
    end

    initial begin
        // clock generation
        #2 rst_ni <= 1;

        // some simple edge cases
        data_i = `RAW_WORD_LEN'h0;
        add_input_data(data_i);

        data_i = `RAW_WORD_LEN'h0;
        add_input_data(data_i);

        data_i = `RAW_WORD_LEN'hFFFF_FFFF;
        add_input_data(data_i);

        data_i = `RAW_WORD_LEN'hDEAD_BEEF;
        add_input_data(data_i);

        // simulate some random streamed inputs
        repeat (`NUM_TESTS) begin
            // data_i = $urandom();
            data_i = rand_word();
            add_input_data(data_i);

            // A random boolean to decide whether the next word is the same or not, and send again if so
            // To test counter
            loop_count = 0;
            {unused_bits, repeat_variable} = $urandom();
            while (repeat_variable && loop_count < 4) begin 
                add_input_data(data_i);
                loop_count = loop_count + 1;
            end 
        end

        $display("data_stream is %h\ ", data_stream_i);

        send_input_data();

        while (receive_count < (`NUM_TESTS * 4)) begin
            receive_frame(receive_count);
            receive_count = receive_count + 1;
        end

        #10;
        $finish;
    end

endmodule : tb_process_frame_top
