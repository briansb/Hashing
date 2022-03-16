
#include "Input.h"

void LoadMessageFromString(std::string in, std::bitset<BITS_PER_WORD> m[MAX_BLOCKS][WORDS_PER_BLOCK], int &block_number) {
	
	block_number = 1;
	int block_length = BITS_PER_WORD * WORDS_PER_BLOCK;
	int bit_counter = 1;
	int word_index = 0;
	int shift_amount = BITS_PER_WORD - BITS_PER_BYTE;
	std::bitset< BITS_PER_WORD> single_entry;
	for (size_t i = 0; i < in.length(); i++) {
		if (bit_counter > block_length) { bit_counter = 1; word_index = 0; block_number++; }	 // filled up block

		single_entry = char(in[i]);
		single_entry = single_entry << shift_amount;
		m[block_number-1][word_index] = m[block_number-1][word_index].to_ullong() + single_entry.to_ullong();
		shift_amount -= BITS_PER_BYTE;
		bit_counter += BITS_PER_BYTE;

		if (shift_amount < 0){
			shift_amount = BITS_PER_WORD - BITS_PER_BYTE;
			word_index++;
		}
	}

	//  insert 1
	if (bit_counter > block_length) { bit_counter = 1; word_index = 0; block_number++; }
	std::cout << "Block number = " << block_number << ", word index = " << word_index << ", shift_amount = " << shift_amount << ", bit_counter = " << bit_counter << std::endl;

	single_entry = 128;
	single_entry = single_entry << shift_amount;
	m[block_number-1][word_index] = m[block_number-1][word_index].to_ullong() + single_entry.to_ullong();
	bit_counter++;

	// how much padding do we need?  We need at least 64 bits for the size
	



	return;
}