#include <string>
#include <iostream>
#include <bitset>

#include "definitions.hh"

typedef std::bitset<LETTERS_PER_WORD * 8> word;

void message_to_blocks(std::string message, word blocks[][WORDS_PER_BLOCK], int &number_of_blocks);