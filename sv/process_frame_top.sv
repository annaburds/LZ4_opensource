`default_nettype none

// TODO: create a mode to stop compressing the data if the hash table is full and we don't want to evict anything

module process_frame_top #(
    parameter int unsigned WordLen             = 32,
    parameter int unsigned StreamLen           = 32'd1024,
    parameter int unsigned HashWidth           = 5,
    parameter int unsigned RepeatCounterWidth  = 32
) (
    input  logic clk_i,
    input  logic rst_ni,
    input  logic [StreamLen-1:0] data_stream_i,
    input  logic data_valid_i,
    input  logic frame_received_i,
    // TODO standardize frame output width
    output generic_frame_struct_t frame_o,
    output logic ready_for_new_data_o,
    output logic send_frame_o
);
    logic table_full;
    logic hash_table_saved;
    logic save_hash_to_register;
    logic hash_match;
    logic save_hash_to_table;

    logic new_frame_ready, seen_frame_ready;
    logic next_word_same;
    logic assemble_new_frame, assemble_seen_frame;
    generic_frame_struct_t new_frame, seen_frame, frame;
    
    logic [WordLen-1:0] data_o, register_data, data_word_i;
    logic [HashWidth-1:0] hash, register_hash;

    logic [RepeatCounterWidth-1:0] counter;
    logic ready_for_new_data;

    assign ready_for_new_data_o = ready_for_new_data;

    process_frame_fsm #(.WordLen(WordLen), .StreamLen(StreamLen), .HashWidth(HashWidth))
                    FSM
                    (.clk_i(clk_i), .rst_ni(rst_ni), 
                     .table_full_i(table_full),
                     .hash_table_saved_i(hash_table_saved), 
                     .new_frame_ready_i(new_frame_ready),
                    //  .next_word_same_i(next_word_same),
                     .seen_frame_ready_i(seen_frame_ready), 
                     .frame_received_i(frame_received_i),
                     .hash_match_i(hash_match), 
                     .data_valid_i(data_valid_i),
                     .data_stream_i(data_stream_i),
                     .data_word_i(data_word_i),
                     .counter_q(counter),
                     .ready_for_new_data_o(ready_for_new_data), 
                     .evict_word_o(),
                     .save_hash_to_table_o(save_hash_to_table),
                     .save_hash_to_register_o(save_hash_to_register),
                     .assemble_new_frame_o(assemble_new_frame), 
                     .assemble_seen_frame_o(assemble_seen_frame),
                     .send_frame_o(send_frame_o));

    sub_per_hash #(.InpWidth(WordLen), .HashWidth(HashWidth))
                    HASH_GENERATOR
                    (.data_i(data_word_i), 
                     .hash_o(hash), 
                     .hash_onehot_o());

    // TO DO: IMPLEMENT HASH TABLE AND HASH REGISTER MODULES
    hash_table #(.HashLen(HashWidth), .RawWordLen(WordLen))
                    HASH_TABLE
                    (.clk_i(clk_i), 
                     .rst_ni(rst_ni), 
                     .hash_i(hash), 
                     .insert_i(save_hash_to_table), 
                     .data_i(data_word_i),
                     .hash_saved_o(hash_table_saved), 
                     .table_full_o(table_full), 
                     .data_o(data_o), 
                     .hash_match_o(hash_match));

    hash_register #(.HashWidth(HashWidth), .DataWidth(WordLen))
                    HASH_REGISTER
                    (.clk_i(clk_i), 
                     .rst_ni(rst_ni), 
                     .data_i(data_word_i), 
                     .hash_i(hash), 
                     .load_i(save_hash_to_register),
                     .data_o(register_data), 
                     .hash_o(register_hash));

    seen_frame_assembler #(.RawWordLen(WordLen), .HashLen(HashWidth), .RepeatCounterLen(RepeatCounterWidth))
                    SEEN_FRAME_ASSEMBLER
                    (.clk_i(clk_i), 
                     .rst_ni(rst_ni), 
                     .hash_i(register_hash), 
                     .counter_i(counter),
                     .seen_frame_o(seen_frame), 
                     .seen_frame_ready_o(seen_frame_ready));

    new_frame_assembler #(.RawWordLen(WordLen), .HashLen(HashWidth), .RepeatCounterLen(RepeatCounterWidth))
                    NEW_FRAME_ASSEMBLER
                    (.clk_i(clk_i), 
                     .rst_ni(rst_ni), 
                     .data_i(register_data), 
                     .new_frame_o(new_frame),
                     .new_frame_ready_o(new_frame_ready));

    frame_mux #(.Width($bits(generic_frame_struct_t)))
                    FRAME_MUX
                    (.a(new_frame), 
                     .b(seen_frame), 
                     .sel(assemble_new_frame), 
                     .o(frame));
                    

    frame_register #(.Width($bits(generic_frame_struct_t)))
                    FRAME_REG
                    (.clk_i(clk_i), 
                     .rst_ni(rst_ni), 
                     .data_i(frame), 
                     .load_i(assemble_new_frame || assemble_seen_frame),
                     .data_o(frame_o));


endmodule : process_frame_top

module process_frame_fsm #(
    parameter int unsigned WordLen            = 32,
    parameter int unsigned StreamLen          = 1024,
    parameter int unsigned HashWidth          = 5,
    parameter int unsigned RepeatCounterLen   = 32
) (
    input logic clk_i,
    input logic rst_ni,
    input logic table_full_i,
    input logic hash_table_saved_i,
    input logic new_frame_ready_i,
    // input logic next_word_same_i,
    input logic seen_frame_ready_i,
    input logic frame_received_i,
    input logic hash_match_i,
    input logic data_valid_i,
    input logic [StreamLen-1:0]     data_stream_i,
    output logic [WordLen-1:0]      data_word_i,
    output logic evict_word_o,
    output logic save_hash_to_table_o,
    output logic save_hash_to_register_o,
    output logic assemble_new_frame_o,
    output logic assemble_seen_frame_o,
    output logic send_frame_o,
    output logic [RepeatCounterLen-1:0] counter_q,
    output logic ready_for_new_data_o
);
    logic [WordLen-1:0]             word_index_q, word_index_next;
    logic                           next_word_same;
    logic [WordLen-1:0]             next_data_word;
    logic [RepeatCounterLen-1:0]    counter_next;

    // State encoding
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

    always_ff @(posedge clk_i, negedge rst_ni) begin
        if (!rst_ni) begin
            current_state   <= START;
            word_index_q    <= 0;
            counter_q       <= 1;
        end else begin
            // data_word_i <= data_stream_i[word_index*WordLen +: WordLen];
            current_state   <= next_state;
            word_index_q    <= word_index_next;
            counter_q       <= counter_next;
        end
    end

    assign data_word_i = data_stream_i[word_index_q*WordLen +: WordLen];

    // Next state and output logic
    always_comb begin

        // Set default values for next state and outputs
        next_state = START;
        evict_word_o = 0;
        save_hash_to_table_o = 0;
        save_hash_to_register_o = 0;
        assemble_new_frame_o = 0;
        assemble_seen_frame_o = 0;
        send_frame_o = 0;
        ready_for_new_data_o = 1'b1;
        next_data_word = 0;
        next_word_same = 0;
        word_index_next = word_index_q;
        counter_next = counter_q;

        case( current_state )
            START: begin
                // Reset the hash register and counter for the new frame.
                // hash_register_reset_o = 1'b1;
                counter_next = 1;
                // data_word_i <= data_stream_i[word_index*WordLen +: WordLen];

                // Check if the new word's hash is already in the table
                // Hash table and hash generator are combinational
                // Do we need to wait a cycle for the hash to be generated and the table to be checked? If so, we can add a WAIT state here.
                if (data_valid_i) save_hash_to_register_o = 1;

                if (~data_valid_i)                      next_state = START; // Stay in START state until data is valid
                else if (~hash_match_i && table_full_i)    next_state = TABLE_FULL;
                else if (~hash_match_i)                    next_state = NEW_WORD;
                else                                    next_state = SEEN_WORD;
            end
            TABLE_FULL: begin
                // Evict a word from the hash table
                // TO DO: IMPLEMENT EVICTION POLICY FOR HASH TABLE
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
                // save_hash_to_register_o = 1'b1;

                                                        next_state = CHECK_NEXT_WORD;

                // if (hash_reg_saved_i)                   next_state = CHECK_NEXT_WORD;
                // else                                    next_state = SEEN_WORD;
            end
            CHECK_NEXT_WORD: begin
                // Increment counter
                // Since counter starts at 1, we increment is we find out the next one is the same
                next_data_word = data_stream_i[(word_index_q + counter_q)*WordLen +: WordLen];
                next_word_same = (next_data_word == data_word_i);

                if (~next_word_same)
                                                        next_state = MAKE_SEEN_FRAME;
                else begin
                    counter_next = counter_q + 1;
                    
                    // Prevent counter overflow
                    if (counter_next == '1)
                                                        next_state = MAKE_SEEN_FRAME;
                    else
                                                        next_state = CHECK_NEXT_WORD;
                end
            end
            MAKE_SEEN_FRAME: begin
                // Assemble frame containing hash and counter value
                assemble_seen_frame_o = 1'b1;

                if (seen_frame_ready_i)                 next_state = SEND_FRAME;
                else                                    next_state = MAKE_SEEN_FRAME;
            end
            SEND_FRAME: begin
                // Send frame to output FIFO
                send_frame_o = 1'b1;

                if (frame_received_i) begin
                                                        next_state = START;
                    send_frame_o = 1'b0;                // Stop sending frame after it has been received
                    ready_for_new_data_o = 1'b1;        // Ready for new data after sending the frame
                    word_index_next = word_index_q + counter_q;
                end
                else                                    next_state = SEND_FRAME;
            end
            default: begin
                // Should never enter this case
                                                        next_state = START;
            end
        endcase
    end
endmodule: process_frame_fsm
