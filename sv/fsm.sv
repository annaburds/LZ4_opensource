`default_nettype none

// TODO: create a mode to stop compressing the data if the hash table is full and we don't want to evict anything

module process_frame_top #(
    parameter int unsigned InpWidth   = 32'd32,
    parameter int unsigned HashWidth  = 32'd5, 
    parameter int unsigned RepeatCounterWidth = 32'd4
) (
    input logic clk_i,
    input logic rst_ni,
    input logic [InpWidth-1:0] data_i,
    output logic [FrameWidth-1:0] frame_o
);
    logic new_word;
    logic table_full;
    logic hash_table_saved;
    logic new_frame_ready;
    logic hash_reg_saved;
    logic next_frame_same;
    logic seen_frame_ready;
    logic frame_received;
    logic [HashWidth-1:0] hash;
    logic hash_register_reset;
    logic [3:0] counter;
    logic ready_for_new_data;
    logic data_valid_i;

    process_frame_fsm #(.InpWidth(InpWidth), .HashWidth(HashWidth)) 
                    FSM
                    (.clk_i(clk_i), .rst_ni(rst_ni), .new_word_i(new_word), .table_full_i(table_full), 
                     .hash_table_saved_i(hash_table_saved), .new_frame_ready_i(new_frame_ready), 
                     .hash_reg_saved_i(hash_reg_saved), .next_frame_same_i(next_frame_same), 
                     .seen_frame_ready_i(seen_frame_ready), .frame_received_i(frame_received),
                     .hash_register_reset_o(hash_register_reset), .counter_o(counter), 
                     .ready_for_new_data_o(ready_for_new_data), .evict_word_o(), .save_hash_to_table_o(), .save_hash_to_register_o(), 
                     .assemble_new_frame_o(), .assemble_seen_frame_o(), .send_frame_o(), .data_valid_i(data_valid_i));

    sub_per_hash #(.InpWidth(InpWidth), .HashWidth(HashWidth)) 
                    HASH_GENERATOR
                    (.data_i(data_i), .hash_o(hash), .hash_onehot_o());

    // TO DO: IMPLEMENT HASH TABLE AND HASH REGISTER MODULES
    hash_table #(.HashWidth(HashWidth)) 
                    HASH_TABLE
                    (.clk_i(clk_i), .rst_ni(rst_ni), .hash_i(hash), 
                     .hash_saved_o(hash_table_saved), .table_full_o(table_full));
    
    register #(.Width(HashWidth)) 
                    HASH_REGISTER
                    (.clk_i(clk_i), .rst_ni(rst_ni), .d_i(hash), .q_o(), .en_i(hash_reg_saved), 
                     .reset_i(hash_register_reset));

    seen_frame_assembler #(.InpWidth(InpWidth), .HashWidth(HashWidth)) 
                    SEEN_FRAME_ASSEMBLER
                    (.clk_i(clk_i), .rst_ni(rst_ni), .hash_i(hash), .counter_i(counter), 
                     .seen_frame_o(frame_o), .seen_frame_ready_o(seen_frame_ready));

    new_frame_assembler #(.InpWidth(InpWidth), .HashWidth(HashWidth)) 
                    NEW_FRAME_ASSEMBLER
                    (.clk_i(clk_i), .rst_ni(rst_ni), .data_i(data_i), .new_frame_o(frame_o), 
                     .new_frame_ready_o(new_frame_ready));

    

    
endmodule : process_frame_top

module process_frame_fsm #(
    parameter int unsigned InpWidth   = 32'd32,
    parameter int unsigned HashWidth  = 32'd5,
    parameter int unsigned RepeatCounterWidth = 32'd4
) (
    input logic clk_i,
    input logic rst_ni,
    input logic new_word_i,
    input logic table_full_i,
    input logic hash_table_saved_i,
    input logic new_frame_ready_i,
    input logic hash_reg_saved_i,
    input logic next_frame_same_i,
    input logic seen_frame_ready_i,
    input logic frame_received_i,
    output logic evict_word_o,
    output logic save_hash_to_table_o,
    output logic hash_register_reset_o,
    output logic save_hash_to_register_o,
    output logic assemble_new_frame_o,
    output logic assemble_seen_frame_o,
    output logic send_frame_o,
    output logic [3:0] counter_o,
    output logic ready_for_new_data_o
);
    enum logic [3:0] {
        START,
        TABLE_FULL,
        NEW_WORD,
        MAKE_NEW_FRAME,
        SEEN_WORD,
        CHECK_NEXT_WORD,
        MAKE_SEEN_FRAME,
        SEND_FRAME
    } current_state, next_state;

    always_ff @(posedge clk_i, negedge rst_ni)
        if (rst_ni) 
            current_state <= START;
        else
            current_state <= next_state;

    // Next state and output logic
    always_comb begin

        // Set default values for next state and outputs
        next_state = START;
        hash_register_reset_o = 0;
        evict_word_o = 0;
        save_hash_to_table_o = 0;
        counter_o = 0;
        save_hash_to_register_o = 0;
        assemble_new_frame_o = 0;
        assemble_seen_frame_o = 0;
        send_frame_o = 0;
        ready_for_new_data_o = 1'b1;


        case( current_state )
            START: begin
                // Reset the hash register and counter for the new frame.
                hash_register_reset_o = 1'b1;
                counter_o = 0;

                if (~data_valid_i)                      next_state = START; // Stay in START state until data is valid
                else if (new_word_i && table_full_i)    next_state = TABLE_FULL;
                else if (new_word_i)                    next_state = NEW_WORD;
                else                                    next_state = SEEN_WORD;
            end
            TABLE_FULL: begin
                // Evict a word from the hash table
                evict_word_o = 1'b1;

                if (table_full_i)                       next_state = TABLE_FULL;
                else                                    next_state = NEW_WORD;
            end
            NEW_WORD: begin
                // Save hash to the hash table
                save_hash_to_table_o = 1'b1;

                if (hash_table_saved_i)                 next_state = MAKE_NEW_FRAME;
                else                                    next_state = NEW_WORD;
            end
            MAKE_NEW_FRAME: begin
                // Make new frame containing uncompressed word
                assemble_new_frame_o = 1'b1;

                if (new_frame_ready_i)                  next_state = SEND_FRAME;
                else                                    next_state = MAKE_NEW_FRAME;
            end
            SEEN_WORD: begin
                // Save hash to register
                save_hash_to_register_o = 1'b1;

                if (hash_reg_saved_i)                   next_state = CHECK_NEXT_WORD;
                else                                    next_state = SEEN_WORD;
            end
            CHECK_NEXT_WORD: begin
                // Increment counter
                // Since counter starts at 0, we can add one before checking if the next frame is the same
                counter_o = counter_o + 1;

                // Prevent counter overflow
                if (counter_o == {RepeatCounterWidth{1'b1}} || ~next_frame_same_i) 
                                                        next_state = MAKE_SEEN_FRAME;
                else                                    next_state = CHECK_NEXT_WORD;
            end
            MAKE_SEEN_FRAME: begin
                // Assemble frame containing hash and counter value
                assemble_seen_frame_o = 1'b1;

                if (hash_reg_saved_i)                   next_state = SEND_FRAME;
                else                                    next_state = MAKE_SEEN_FRAME;
            end
            SEND_FRAME: begin
                // Send frame to output FIFO
                send_frame_o = 1'b1;

                if (frame_received_i) {                 next_state = START;
                    send_frame_o = 1'b0;                // Stop sending frame after it has been received
                    ready_for_new_data_o = 1'b1;        // Ready for new data after sending the frame
                }
                else                                    next_state = SEND_FRAME;
            end
        endcase
    end
endmodule: process_frame_fsm