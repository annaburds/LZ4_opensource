`default_nettype none

module tb_fsm#(
    parameter int unsigned FrameWidth = 32'd32
    parameter int unsigned InpWidth   = 32'd32,
    parameter int unsigned HashWidth  = 32'd5
) ();
    logic clk_i;
    logic rst_ni;
    logic [InpWidth-1:0] data_i;
    logic [FrameWidth-1:0] frame_o;
    logic ready_for_new_data;
    logic data_valid_i;

    process_frame_top #(.InpWidth(InpWidth), .HashWidth(HashWidth)) 
                    DUT
                    (.clk_i(clk_i), .rst_ni(rst_ni), .data_i(data_i), .frame_o(frame_o), 
                     .ready_for_new_data_o(ready_for_new_data), .data_valid_i(data_valid_i));

    // Tasks for sending input data and receiving frames, to be used in the initial block for testing
    task send_input_data(input logic [InpWidth-1:0] current_word); //, input logic [InpWidth-1:0] next_word);
        data_i <= current_word;
        // data_i_next <= next_word; 
        // TODO: I'm confused about the parallelism of it all, the reading next, how is it all available at the same time?
        data_valid_i <= 1;
        @(posedge clk_i iff (ready_for_new_data)); // wait for the frame to be ready before sending the next word
        data_valid_i <= 0;
    endtask

    task receive_frame();
        @(posedge clk_i iff (send_frame_o != 0)); // wait for a frame to be output
        $display("data word 0x%h --> frame 0x%h", data_i, frame_o);
        frame_received_i <= 1; // signal that frame is successfully received
        @(posedge clk_i);
        frame_received_i <= 0;
    endtask

    // Clock generation and reset, test sequence
    initial begin
        // verilator
        $dumpfile("wave.vcd");
        $dumpvars(0, tb_fsm);

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
        #10;
        $display("data word 0x%h --> frame 0x%h", data_i, frame_o);

        data_i = 32'hFFFF_FFFF;
        #10;
        $display("data word 0x%h --> frame 0x%h", data_i, frame_o); 

        data_i = 32'hDEAD_BEEF;
        #10;
        $display("data word 0x%h --> frame 0x%h", data_i, frame_o);

        // simulate some random streamed inputs
        int unsigned NUM_TESTS = 10;
        repeat (NUM_TESTS) begin
            data_i = $urandom_range(32'h0, 32'hFFFF_FFFF);
            send_input_data(data_i);
            // TODO: add a random boolean to decide whether the next word is the same or not, and send again if so
            receive_frame();
        end

        #10;
        $finish;
    end

endmodule : tb_fsm