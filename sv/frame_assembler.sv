/*
 * frame_assembler.sv
 *
 * Module to assemble new and seen frames based on the LZ4 frame format specification.
 * This module takes in raw data for new frames and hash/counter values for seen frames,
 * and outputs the corresponding frame structures ready for transmission or storage.
 *
 * Author: Adriana Holtzman
 *
 */

`default_nettype none
import frame_pkg::*;

// TODO: implement a function/task to calculate checksum values for header, block, and content
// TODO: add parameters or inputs to set optional flags

module new_frame_assembler #(
    parameter int unsigned RawWordLen       = 32
) (
    input  logic                       clk_i,
    input  logic                       rst_ni,
    input  logic [RawWordLen-1:0]      data_i,
    output generic_frame_struct_t      new_frame_o,
    output logic                       new_frame_ready_o
);
    // TO DO: IMPLEMENT THE ASSEMBLY OF A NEW FRAME, WHICH CONSISTS OF THE RAW DATA WORD
    // New frame format, containing the hash and counter values

    always_comb begin
        new_frame_o = '{
            MagicNumber: 32'h184D_2204,
            FrameDescriptor: '{
                FLG: {
                    1'b0,   // VERSION_MSB [7]:              version is hardcoded to 01
                    1'b1,   // VERSION_LSB [6]
                    1'b1,   // BLOCK_INDEPENDENCE_FLAG [5]:  necessary for multithreading
                    1'b0,   // BLOCK_CHECKSUM_FLAG [4]:      optional
                    1'b0,   // CONTENT_SIZE_FLAG [3]:        optional
                    1'b0,   // CONTENT_CHECKSUM_FLAG [2]:    optional
                    1'b0,   // reserved [1]
                    1'b0    // DICTID_FLAG [0]:              optional
                },
                BD: {
                    1'b0,   // RESERVED_BIT_7 [7]
                    1'b1,   // DATA_MAXSIZE_6 [6]:  4->64KB, 5->256KB, 6->1MB, 7->4MB
                    1'b0,   // DATA_MAXSIZE_5 [5]
                    1'b0,   // DATA_MAXSIZE_4 [4]
                    1'b0,   // RESERVED_BIT_3 [3]
                    1'b0,   // RESERVED_BIT_2 [2]
                    1'b0,   // RESERVED_BIT_1 [1]
                    1'b0    // RESERVED_BIT_0 [0]
                },
                CONTENT_SIZE: 64'h0,
                DICT_ID:      32'h0,
                HC:           8'hFF     // TODO: replace placeholder header checksum
            },
            DataBlock: '{
                RawData: data_i
            },
            EndMark:         32'h0000_0000,
            ContentChecksum: 32'hFFFF_FFFF  // TODO: replace placeholder
        };
    end

    // TODO: include optional fields as desired (block checksum, content checksum, dict id, content size)
    assign new_frame_ready_o = 1'b1;

endmodule : new_frame_assembler

module seen_frame_assembler #(
    parameter int unsigned RawWordLen       = 32,
    parameter int unsigned PositionLen      = 16,
    parameter int unsigned RepeatCounterLen = 4
) (
    input  logic                            clk_i,
    input  logic                            rst_ni,
    input  logic [PositionLen-1:0]              position_i,
    input  logic [RepeatCounterLen-1:0]     counter_i, // for the number of times we've seen this hash before
    output generic_frame_struct_t           seen_frame_o,
    output logic                            seen_frame_ready_o
);

    // Seen frame format: hash and counter packed into RawData field
    always_comb begin
        seen_frame_o = '{
            MagicNumber: 32'h184D_2204,
            FrameDescriptor: '{
                FLG: {
                    1'b0,   // VERSION_MSB [7]:              version is hardcoded to 01
                    1'b1,   // VERSION_LSB [6]
                    1'b1,   // BLOCK_INDEPENDENCE_FLAG [5]:  necessary for multithreading
                    1'b0,   // BLOCK_CHECKSUM_FLAG [4]:      optional
                    1'b0,   // CONTENT_SIZE_FLAG [3]:        optional
                    1'b0,   // CONTENT_CHECKSUM_FLAG [2]:    optional
                    1'b0,   // reserved [1]
                    1'b0    // DICTID_FLAG [0]:              optional
                },
                BD: {
                    1'b0,   // RESERVED_BIT_7 [7]
                    1'b1,   // DATA_MAXSIZE_6 [6]:  4->64KB, 5->256KB, 6->1MB, 7->4MB
                    1'b0,   // DATA_MAXSIZE_5 [5]
                    1'b0,   // DATA_MAXSIZE_4 [4]
                    1'b0,   // RESERVED_BIT_3 [3]
                    1'b0,   // RESERVED_BIT_2 [2]
                    1'b0,   // RESERVED_BIT_1 [1]
                    1'b0    // RESERVED_BIT_0 [0]
                },
                CONTENT_SIZE: 64'h0,
                DICT_ID:      32'h0,
                HC:           8'hFF     // TODO: replace placeholder header checksum
            },
            DataBlock: '{
                RawData: RawWordLen'({position_i, counter_i})
            },
            EndMark:         32'h0000_0000,
            ContentChecksum: 32'hFFFF_FFFF  // TODO: replace placeholder
        };
    end

    // TODO: include optional fields as desired (block checksum, content checksum, dict id, content size)
    // TODO: will need to differentiate the frame format for seen vs new frames

    assign seen_frame_ready_o = 1'b1;

endmodule : seen_frame_assembler
