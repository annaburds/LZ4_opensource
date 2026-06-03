`default_nettype none
`define NUM_ENTRIES 128
import frame_pkg::*;

typedef struct packed {
    logic [`HASH_LEN-1:0]       Hash;
    logic [`RAW_WORD_LEN-1:0]   Data;
    logic                      Valid;
} hash_table_entry_t;

typedef struct packed {
    logic                                           HashFull;
    hash_table_entry_t  [`NUM_ENTRIES-1:0]           HashContents;
    logic               [$clog2(`NUM_ENTRIES)-1:0]   NextFree;
} hash_table_t;

module hash_table (
    input  logic clk_i,
    input  logic rst_ni,

    input  logic                         insert_i,
    input  logic [`HASH_LEN-1:0]          hash_i,
    input  logic [`RAW_WORD_LEN-1:0]      data_i,

    output logic                         hash_match_o, // hash was alr in the table
    output logic                         hash_saved_o, // hash was added to table successfully
    output logic [`RAW_WORD_LEN-1:0]      data_o,
    output logic                         table_full_o
);

    hash_table_t hash_table;

    // reset hash table to all invalid, reset metadata to zeros
    always_ff @(negedge rst_ni) begin
        if (!rst_ni) begin
            hash_table.NextFree <= 0;
            hash_table.HashFull <= 0;
            for (int i = 0; i < `NUM_ENTRIES; i++) begin
                hash_table.HashContents[i].Valid <= 0;
            end
        end
    end

    // combinational logic to check if the hash is already in the table 
    // and to output the corresponding data
    // but the match isn't being saved????

    always_comb begin
        hash_match_o = 1'b0;
        data_o       = '0;

        for (int i = 0; i < `NUM_ENTRIES; i++) begin
            if (hash_table.HashContents[i].Valid &&
                hash_table.HashContents[i].Hash == hash_i) begin

                hash_match_o = 1'b1;
                data_o       = hash_table.HashContents[i].Data;
            end
        end
    end

    assign table_full_o = (hash_table.NextFree == `NUM_ENTRIES);
    assign hash_table.HashFull = table_full_o;

    // sequential logic to insert a new hash and data into the table
    always_ff @(posedge clk_i) begin
        if (insert_i &&
            !hash_saved_o &&
            !table_full_o) begin

            hash_table.HashContents[hash_table.NextFree].Hash  <= hash_i;
            hash_table.HashContents[hash_table.NextFree].Data  <= data_i;
            hash_table.HashContents[hash_table.NextFree].Valid <= 1'b1;

            hash_table.NextFree <= hash_table.NextFree + 1;
        end
    end

endmodule : hash_table