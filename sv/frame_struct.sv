/*
* frame_struct.sv
* 
* This SystemVerilog file defines the data structures for a frame format, including the frame descriptor and data block. 
* Can be used as a package to be imported in other SystemVerilog files for easier handling of frame data.
*
* Author: Adriana Holtzman 
*/

package frame_pkg;

typedef enum logic [7:0] { 
    VERSION_MSB             = 7,
    VERSION_LSB             = 6,
    BLOCK_INDEPENDENCE_FLAG = 5,
    BLOCK_CHECKSUM_FLAG     = 4,
    CONTENT_SIZE_FLAG       = 3,
    CONTENT_CHECKSUM_FLAG   = 2,
    DICT_ID_FLAG            = 0
} flg_bits_e;

// Refers to maximum size of original uncompressed data
// 4 --> 64 KB, 5 --> 256 KB, 6 --> 1 MB, 7 --> 4 MB
// RESERVED bits must be set to 0
// TODO: is this relevant for LZ4? All of our data blocks are the same size.
typedef enum logic [7:0] { 
    RESERVED_BIT_7 = 7,
    DATA_MAXSIZE_6 = 6,
    DATA_MAXSIZE_5 = 5,
    DATA_MAXSIZE_4 = 4,
    RESERVED_BIT_3 = 3,
    RESERVED_BIT_2 = 2,
    RESERVED_BIT_1 = 1,
    RESERVED_BIT_0 = 0
} bd_bits_e;

typedef struct packed {
    byte unsigned FLG;          // 1 byte
    byte unsigned BD;           // 1 byte
    logic [63:0]  CONTENT_SIZE; // 0-8 bytes (optional, only if FLG[3] is set)
    logic [31:0]  DICT_ID;      // 0-4 bytes (optional, only if FLG[0] is set)
    byte unsigned HC;           // 1 byte (header checksum)
} frame_descriptor_t;

typedef struct packed {
    logic [31:0]                    DataSize;       // 4 bytes
    logic [`HASH_LEN-1:0]           Hash;   
    logic [`REPEAT_COUNTER_LEN-1:0] RepeatCounter;
    logic [31:0]                    BlockChecksum;  // 0-4 bytes (optional, only if FLG[4] is set)
} seen_data_block_t;

typedef struct packed {
    logic [31:0]        MagicNumber;
    frame_descriptor_t  FrameDescriptor;
    seen_data_block_t   DataBlock;
    logic [31:0]        EndMark;            // 4 bytes
    logic [31:0]        ContentChecksum;    // 0-4 bytes (optional, only if FLG[2] is set)
} seen_frame_struct_t;

typedef struct packed {
    logic [31:0]                MagicNumber;
    frame_descriptor_t          FrameDescriptor;
    logic [`RAW_WORD_LEN-1:0]   RawData;
    logic [31:0]                EndMark;            // 4 bytes
    logic [31:0]                ContentChecksum;    // 0-4 bytes (optional, only if FLG[2] is set)
} new_frame_struct_t;

typedef struct packed {
    logic [`RAW_WORD_LEN-1:0]   RawData; // for now because this is longer than the other one
} generic_data_block_t;

typedef struct packed {
    logic [31:0]                MagicNumber;
    frame_descriptor_t          FrameDescriptor;
    generic_data_block_t        DataBlock;
    logic [31:0]                EndMark;            // 4 bytes
    logic [31:0]                ContentChecksum;    // 0-4 bytes (optional, only if FLG[2] is set)
} generic_frame_struct_t;

endpackage : frame_pkg