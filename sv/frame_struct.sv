/*
* frame_struct.sv
* 
* This SystemVerilog file defines the data structures for a frame format, including the frame descriptor and data block. 
* Can be used as a package to be imported in other SystemVerilog files for easier handling of frame data.
*
* Author: Adriana Holtzman 
*/

// Define macros 
`define HASH_LEN            32'd5 // example lengths, adjust as needed
`define REPEAT_COUNTER_LEN  32'd4 
`define RAW_WORD_LEN        32'd32

typedef enum logic [7:0] { 
    VERSION                 = 7:6, // 2 bits for version
    BLOCK_INDEPENDENCE_FLAG = 5,
    BLOCK_CHECKSUM_FLAG     = 4,
    CONTENT_SIZE_FLAG       = 3,
    CONTENT_CHECKSUM_FLAG   = 2,
    DICT_ID_FLAG            = 0
} flg_bits_e;

// Refers to maximum size of original uncompressed data
// 4 --> 64 KB, 5 --> 256 KB, 6 --> 1 MB, 7 --> 4 MB
// TODO: is this relevant for LZ4? All of our data blocks are the same size.
typedef enum logic [7:0] { 
    DATA_MAXSIZE = 6:4  
} bd_bits_e;

typedef struct packed {
    byte unsigned FLG;          // 1 byte
    byte unsigned BD;           // 1 byte
    long unsigned CONTENT_SIZE; // 0-8 bytes (optional, only if FLG[3] is set)
    int  unsigned DICT_ID;      // 0-4 bytes (optional, only if FLG[0] is set)
    byte unsigned HC;           // 1 byte (header checksum)
} frame_descriptor_t;

typedef struct packed {
    int  unsigned DataSize;         // 4 bytes
    byte unsigned Hash[HASH_LEN];   
    byte unsigned RepeatCounter[REPEAT_COUNTER_LEN];
    int  unsigned BlockChecksum;    // 0-4 bytes (optional, only if FLG[4] is set)
} seen_data_block_t;

typedef struct packed {
    int unsigned        MagicNumber;
    frame_descriptor_t  FrameDescriptor;
    seen_data_block_t   DataBlock;
    int unsigned        EndMark;            // 4 bytes
    int unsigned        ContentChecksum;    // 0-4 bytes (optional, only if FLG[2] is set)
} seen_frame_struct_t;

typedef struct packed {
    int unsigned        MagicNumber;
    frame_descriptor_t  FrameDescriptor;
    int unsigned        RawData[RAW_WORD_LEN];
    int unsigned        EndMark;            // 4 bytes
    int unsigned        ContentChecksum;    // 0-4 bytes (optional, only if FLG[2] is set)
} new_frame_struct_t;