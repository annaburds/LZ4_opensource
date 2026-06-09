`default_nettype none

module frame_register #(
    parameter int unsigned Width = 64
) (
    input  logic clk_i,
    input  logic rst_ni,
    input  logic load_i,

    input  logic [Width-1:0] data_i,
    output logic [Width-1:0] data_o
);

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            data_o <= '0;
        end 
        else if (load_i) begin
            data_o <= data_i;
        end
     end

endmodule : frame_register
