`default_nettype none

module tb_sub_per_hash #(
    parameter int unsigned InpWidth   = 32'd32,
    parameter int unsigned HashWidth  = 32'd5
) ();
    logic [InpWidth-1:0]    data_i;
    logic [HashWidth-1:0]   hash_o;

    sub_per_hash    #(.InpWidth(InpWidth), .HashWidth(HashWidth)) 
                    DUT
                    (.data_i(data_i), .hash_o(hash_o), .hash_onehot_o());

    initial begin
        // verilator
        $dumpfile("wave.vcd");
        $dumpvars(0, tb_sub_per_hash);

        // some simple edge cases
        data_i = 32'h0;
        #1;
        $display("data word 0x%h --> hash 0x%h", data_i, hash_o);

        data_i = 32'hFFFF_FFFF;
        #1;
        $display("data word 0x%h --> hash 0x%h", data_i, hash_o);

        // non edge case, could make this a loop with random inputs
        data_i = 32'hDEAD_BEEF;
        #1;
        $display("data word 0x%h --> hash 0x%h", data_i, hash_o);

        $finish;
    end

endmodule : tb_sub_per_hash


