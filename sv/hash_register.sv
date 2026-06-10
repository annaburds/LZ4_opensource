`default_nettype none

module hash_register #(
    parameter int unsigned HashWidth    = 5,
    parameter int unsigned DataWidth    = 32,
    parameter int unsigned PositionLen  = 16
) (
    input  logic clk_i,
    input  logic rst_ni,
    input  logic load_i,

    input  logic [DataWidth-1:0]    data_i,
    input  logic [HashWidth-1:0]    hash_i,
    input  logic [PositionLen-1:0]  position_i,

    output logic [DataWidth-1:0]    data_o,
    output logic [HashWidth-1:0]    hash_o,
    output logic [PositionLen-1:0]  position_o
);
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            hash_o      <= '0;
            data_o      <= '0;
            position_o  <= '0;
        end 
        else if (load_i) begin
            hash_o      <= hash_i;
            data_o      <= data_i;
            position_o  <= position_i;
        end
     end

endmodule : hash_register
