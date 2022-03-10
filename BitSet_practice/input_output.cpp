#include "input_output.hh"

void message_to_blocks(std::string message, word blocks[][WORDS_PER_BLOCK], int &number_of_blocks) {
    std::cout << "Converting the message to blocks" << std::endl;

    message = "Brian";
    
    blocks[0][0] = 66;
    blocks[0][1] = 114;
    blocks[0][2] = 105;
    blocks[0][3] = 97;
    blocks[0][4] = 110;

    number_of_blocks = 1;

    return;
}