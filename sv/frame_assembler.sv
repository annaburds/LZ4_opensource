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
`include "tb_fsm.sv"

// TODO: implement a function/task to calculate checksum values for header, block, and content
// TODO: add parameters or inputs to set optional flags

module new_frame_assembler (
    input  logic                     clk_i,
    input  logic                     rst_ni,
    input  logic [`RAW_WORD_LEN-1:0] data_i,
    output new_frame_struct_t        new_frame_o,
    output logic                     new_frame_ready_o
);
    // TO DO: IMPLEMENT THE ASSEMBLY OF A NEW FRAME, WHICH CONSISTS OF THE RAW DATA WORD
    // New frame format, containing the hash and counter values

    initial begin
        new_frame_o = '{
            MagicNumber: 32'h184D_2204,           
            FrameDescriptor: '{
                FLG: '{
                    VERSION_MSB: 1'b0,                // version is hardcoded to 01
                    VERSION_LSB: 1'b1,
                    BLOCK_INDEPENDENCE_FLAG: 1'b1,    // necessary for multithreading
                    BLOCK_CHECKSUM_FLAG: 1'b0,        // optional
                    CONTENT_SIZE_FLAG: 1'b0,          // optional
                    CONTENT_CHECKSUM_FLAG: 1'b0,      // optional
                    DICTID_FLAG: 1'b0                 // optional
                },
                BD: '{
                    RESERVED_BIT_7: 1'b0,
                    DATA_MAXSIZE_6: 1'b1,           // 4 --> 64 KB, 5 --> 256 KB, 6 --> 1 MB, 7 --> 4 MB
                    DATA_MAXSIZE_5: 1'b0,
                    DATA_MAXSIZE_4: 1'b0,
                    RESERVED_BIT_3: 1'b0,
                    RESERVED_BIT_2: 1'b0,
                    RESERVED_BIT_1: 1'b0,
                    RESERVED_BIT_0: 1'b0
                },
                HC: 8'hFF                            // TODO: replace placeholder value for header checksum
            },
            DataBlock: '{
                DataSize: RAW_WORD_LEN, 
                RawData: data_i
            },
            EndMark: 32'h0000_0000,              
            ContentChecksum: 32'hFFFF_FFFF           // TODO: replace placeholder value
        };
    end

    // TODO: include optional fields as desired (block checksum, content checksum, dict id, content size)    
    assign new_frame_ready_o = 1'b1; 

endmodule : new_frame_assembler

module seen_frame_assembler (
    input  logic                            clk_i,
    input  logic                            rst_ni,
    input  logic [`HASH_LEN-1:0]            hash_i,
    input  logic [`REPEAT_COUNTER_LEN-1:0]  counter_i, // for the number of times we've seen this hash before
    output seen_frame_struct_t              seen_frame_o,
    output logic                            seen_frame_ready_o
);

    // Seen frame format, containing the hash and counter values

    initial begin
        seen_frame_o = '{
            MagicNumber: 32'h184D_2204,           
            FrameDescriptor: '{
                FLG: '{
                    VERSION_MSB: 1'b0,                // version is hardcoded to 01
                    VERSION_LSB: 1'b1,
                    BLOCK_INDEPENDENCE_FLAG: 1'b1,    // necessary for multithreading
                    BLOCK_CHECKSUM_FLAG: 1'b0,        // optional
                    CONTENT_SIZE_FLAG: 1'b0,          // optional
                    CONTENT_CHECKSUM_FLAG: 1'b0,      // optional
                    DICTID_FLAG: 1'b0                 // optional
                },
                BD: '{
                    RESERVED_BIT_7: 1'b0,
                    DATA_MAXSIZE_6: 1'b1,           // 4 --> 64 KB, 5 --> 256 KB, 6 --> 1 MB, 7 --> 4 MB
                    DATA_MAXSIZE_5: 1'b0,
                    DATA_MAXSIZE_4: 1'b0,
                    RESERVED_BIT_3: 1'b0,
                    RESERVED_BIT_2: 1'b0,
                    RESERVED_BIT_1: 1'b0,
                    RESERVED_BIT_0: 1'b0
                },
                HC: 8'hFF                            // TODO: replace placeholder value for header checksum
            },
            DataBlock: '{
                DataSize: `HASH_LEN + `REPEAT_COUNTER_LEN, 
                Hash: hash_i,
                RepeatCounter: counter_i
            },
            EndMark: 32'h0000_0000,              
            ContentChecksum: 32'hFFFF_FFFF           // TODO: replace placeholder value
        };
    end

    // TODO: include optional fields as desired (block checksum, content checksum, dict id, content size)
    // TODO: will need to differentiate the frame format for seen vs new frames, maybe use the FLG byte in the frame descriptor to indicate this?

    assign seen_frame_ready_o = 1'b1; 

endmodule : seen_frame_assembler
