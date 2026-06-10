`default_nettype none
import frame_pkg::*;

module hash_table #(
    parameter int unsigned HashLen    = 5,
    parameter int unsigned RawWordLen = 32,
    parameter int unsigned NumEntries = 128,
    parameter int unsigned PositionLen = 16
) (
    input  logic clk_i,
    input  logic rst_ni,

    input  logic                    insert_i,
    input  logic [HashLen-1:0]      hash_i,
    input  logic [PositionLen-1:0]  position_i,

    output logic                    hash_match_o, // hash was alr in the table
    output logic [PositionLen-1:0]  position_o,
    output logic                    table_full_o
);

    typedef struct packed {
        logic [HashLen-1:0]     Hash;
        logic [PositionLen-1:0] Position;
        logic                   Reused;
        logic                   Valid;
    } hash_table_entry_t;

    typedef struct packed {
        hash_table_entry_t [NumEntries-1:0]     HashContents;
        logic [$clog2(NumEntries):0]            NextFree; // one extra bit to detect full
    } hash_table_t;

    hash_table_t hash_table;

    // combinational logic to check if the hash is already in the table
    always_comb begin
        hash_match_o = 1'b0;
        position_o   = '0;

        for (int i = 0; i < NumEntries; i++) begin
            if (hash_table.HashContents[i].Valid &&
                hash_table.HashContents[i].Hash == hash_i) begin

                hash_match_o = 1'b1;
                position_o   = hash_table.HashContents[i].Position;
            end
        end
    end

    assign table_full_o = (hash_table.NextFree == ($clog2(NumEntries)+1)'(NumEntries));

    // reset and insert: combined into one always_ff to avoid MULTIDRIVEN
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            hash_table.NextFree <= 0;
            for (int i = 0; i < NumEntries; i++) begin
                hash_table.HashContents[i].Valid  <= 0;
                hash_table.HashContents[i].Reused <= 0; // TODO SET TO 1 SOMETIMES
            end
        end else if (insert_i && !hash_match_o && !table_full_o) begin
            hash_table.HashContents[hash_table.NextFree].Hash       <= hash_i;
            hash_table.HashContents[hash_table.NextFree].Position   <= position_i;
            hash_table.HashContents[hash_table.NextFree].Valid      <= 1'b1;
            hash_table.NextFree <= hash_table.NextFree + 1;
        end
    end

endmodule : hash_table
