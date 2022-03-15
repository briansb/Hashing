
#include "Input.h"


void LoadMessageFromString(std::string in, std::bitset<BITS_PER_WORD> m[MAX_BLOCKS][WORDS_PER_BLOCK], int &block_number) {
	//  Assumes only one block
	block_number = 1;
	int word_index = 0;
	int shift_amount = BITS_PER_WORD - BITS_PER_BYTE;
	std::bitset< BITS_PER_WORD> single_entry;
	for (size_t i = 0; i < in.length(); i++) {

		single_entry = char(in[i]);
		single_entry = single_entry << shift_amount;
		m[block_number-1][word_index] = m[block_number-1][word_index].to_ullong() + single_entry.to_ullong();
		shift_amount -= BITS_PER_BYTE;

		if (shift_amount < 0){
			shift_amount = BITS_PER_WORD - BITS_PER_BYTE;
			word_index++;
		}
	}


	// need to compute remaining bits...to determine if another block is needed
	

	return;
}