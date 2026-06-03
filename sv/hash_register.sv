`default_nettype none

module hash_register #(
    parameter int unsigned Width = `HASH_LEN
) (
    input  logic clk_i,
    input  logic rst_ni,
    input  logic [Width-1:0] data_i,
    input  logic en_i,
    input  logic reset_i,
    output logic [Width-1:0] q_o,
    output logic saved_o
);
    logic [Width-1:0] hash_reg;

    assign hash_reg_next = reset_i ? '0 : (en_i ? data_i : hash_reg);
    assign q_o = hash_reg;

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            hash_reg <= '0;
        end else begin
            hash_reg <= hash_reg_next;
        end
     end

     // TODO implement saved_o signal if necessary for timing

endmodule : hash_register