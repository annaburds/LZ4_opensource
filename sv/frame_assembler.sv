`default_nettype none

module new_frame_assembler #(
    parameter int unsigned InpWidth   = RAW_WORD_LEN,
    parameter int unsigned HashWidth  = HASH_LEN
) (
    input logic clk_i,
    input logic rst_ni,
    input logic [InpWidth-1:0] data_i,
    output logic [FrameWidth-1:0] new_frame_o,
    output logic new_frame_ready_o
);
    // TO DO: IMPLEMENT THE ASSEMBLY OF A NEW FRAME, WHICH CONSISTS OF THE RAW DATA WORD
    // New frame format, containing the hash and counter values
    new_frame_o = new_frame_struct_t'(0);                              // initialize the frame to all 0s
    new_frame_o.RawData = data_i;                                      // assign the raw data to the appropriate field
    new_frame_o.DataBlock.DataSize = RAW_WORD_LEN;                     // the size of the data block is the size of the raw data
    new_frame_o.FrameDescriptor.BD.DATA_MAXSIZE = 3'b100;              // 4 --> 64 KB max uncompressed data size
    new_frame_o.FrameDescriptor.HC = 8'hFF;                            // TODO: replace placeholder value for header checksum

    // The following values are hardcoded. They should not change.
    new_frame_o.MagicNumber = 32'h184D2204;           
    new_frame_o.FrameDescriptor.FLG.VERSION = 2'b01; 
    new_frame_o.FrameDescriptor.FLG.BLOCK_INDEPENDENCE_FLAG = 1'b1;    // necessary for multithreading

    // TODO: include optional fields as desired (block checksum, content checksum, dict id, content size)    new_frame_ready_o <= 1'b1; 

endmodule : new_frame_assembler

module seen_frame_assembler #(
    parameter int unsigned InpWidth   = RAW_WORD_LEN,
    parameter int unsigned HashWidth  = HASH_LEN
) (
    input logic clk_i,
    input logic rst_ni,
    input logic [HashWidth-1:0] hash_i,
    input logic [3:0] counter_i, // for the number of times we've seen this hash before
    output logic [FrameWidth-1:0] seen_frame_o,
    output logic seen_frame_ready_o
);

    // Seen frame format, containing the hash and counter values
    seen_frame_o = seen_frame_struct_t'(0);                             // initialize the frame to all 0s
    seen_frame_o.DataBlock.Hash = hash_i;                               // assign the hash to the appropriate field
    seen_frame_o.DataBlock.RepeatCounter = counter_i;                   // assign the counter to the appropriate field
    seen_frame_o.DataBlock.DataSize = HASH_LEN + REPEAT_COUNTER_LEN;    // the size of the data block is the size of the hash and counter
    seen_frame_o.FrameDescriptor.BD.DATA_MAXSIZE = 3'b100;              // 4 --> 64 KB max uncompressed data size
    seen_frame_o.FrameDescriptor.HC = 8'hFF;                            // TODO: replace placeholder value for header checksum

    // The following values are hardcoded. They should not change.
    seen_frame_o.MagicNumber = 32'h184D2204;           
    seen_frame_o.FrameDescriptor.FLG.VERSION = 2'b01; 
    seen_frame_o.FrameDescriptor.FLG.BLOCK_INDEPENDENCE_FLAG = 1'b1;    // necessary for multithreading

    // TODO: include optional fields as desired (block checksum, content checksum, dict id, content size)
    // TODO: will need to differentiate the frame format for seen vs new frames, maybe use the FLG byte in the frame descriptor to indicate this?

    seen_frame_ready_o <= 1'b1; 

endmodule : seen_frame_assembler