#include "input_output.hh"

void message_to_blocks(std::string message, word blocks[][WORDS_PER_BLOCK], int &number_of_blocks) {
    std::cout << "Converting the message to blocks" << std::endl;

    int word_index = 0;
    int character_counter = 1;
    int shift_amount = (LETTERS_PER_WORD - 1)  * 8;
    word helper;
    for (size_t i = 0; i < message.length(); i++) {

            helper = int(char(message[i]));
            helper = helper << shift_amount;
            blocks[0][word_index] = blocks[0][word_index].to_ulong() + helper.to_ulong();

            if (character_counter < LETTERS_PER_WORD) {
                character_counter++;
                shift_amount -= 8;
            } else {
                word_index++;
                character_counter = 1;
                shift_amount = (LETTERS_PER_WORD -1)  * 8;
            }
    }

    number_of_blocks = 1;

    return;
}