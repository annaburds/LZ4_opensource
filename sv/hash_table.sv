`default_nettype none

module hash_table #(
    parameter int HASH_LEN      = 16,
    parameter int RAW_WORD_LEN  = 32,
    parameter int NUM_ENTRIES   = 256
)(
    input  logic clk_i,
    input  logic rst_ni,

    input  logic                         insert_i,
    input  logic [HASH_LEN-1:0]          hash_i,
    input  logic [RAW_WORD_LEN-1:0]      data_i,

    output logic                         hash_saved_o,
    output logic [RAW_WORD_LEN-1:0]      data_o,
    output logic                         table_full_o
);

    typedef struct packed {
        logic [HASH_LEN-1:0]       Hash;
        logic [RAW_WORD_LEN-1:0]   Data;
        logic                      Valid;
    } hash_table_entry_t;

    hash_table_entry_t table [NUM_ENTRIES];

    logic [$clog2(NUM_ENTRIES):0] next_free;

    // combinational logic to check if the hash is already in the table 
    // and to output the corresponding data
    always_comb begin
        hash_saved_o = 1'b0;
        data_o       = '0;

        for (int i = 0; i < NUM_ENTRIES; i++) begin
            if (table[i].Valid &&
                table[i].Hash == hash_i) begin

                hash_saved_o = 1'b1;
                data_o       = table[i].Data;
            end
        end
    end

    assign table_full_o = (next_free == NUM_ENTRIES);

    // sequential logic to insert a new hash and data into the table
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            next_free <= '0;

            for (int i = 0; i < NUM_ENTRIES; i++)
                table[i].Valid <= 1'b0;

        end else begin

            if (insert_i &&
                !hash_saved_o &&
                !table_full_o) begin

                table[next_free].Hash  <= hash_i;
                table[next_free].Data  <= data_i;
                table[next_free].Valid <= 1'b1;

                next_free <= next_free + 1;
            end
        end
    end

endmodule : hash_table