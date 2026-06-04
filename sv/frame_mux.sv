`default_nettype none

module frame_mux #(
    parameter int unsigned Width = 5
) (
    input  logic [Width-1:0] a,
    input  logic [Width-1:0] b,
    input  logic             sel,
    output logic [Width-1:0] o
);
    assign o = sel ? a : b;

endmodule : frame_mux
