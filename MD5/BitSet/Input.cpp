
#include "Input.h"

void LoadMessageFromString(std::string in, std::bitset<BITS_PER_WORD> m[MAX_BLOCKS][WORDS_PER_BLOCK], int &block_number) {
	
	block_number = 1;
	unsigned long long message_length = 0;
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
		message_length += BITS_PER_BYTE;

		if (shift_amount < 0){
			shift_amount = BITS_PER_WORD - BITS_PER_BYTE;
			word_index++;
		}
	}

	//  insert 1
	if (bit_counter > block_length) { bit_counter = 1; word_index = 0; block_number++; }
	//std::cout << "Block number = " << block_number << ", word index = " << word_index << ", shift_amount = " << shift_amount << ", bit_counter = " << bit_counter << std::endl;

	single_entry = 128;
	single_entry = single_entry << shift_amount;
	m[block_number-1][word_index] = m[block_number-1][word_index].to_ullong() + single_entry.to_ullong();
	bit_counter++;

	// how much padding do we need?  We need at least 64 bits for the size
	if ((block_length - bit_counter) < 64 ) {
		block_number++;
	}

	//  length is 64 bits long, so it takes up all of words 14 and 15
	//  assume the message is less than 2^32 bits long...4,294,967,296...
	//    and only load word 15
	word_index = 15;
	m[block_number-1][word_index] = m[block_number-1][word_index].to_ullong() + message_length;


	return;
}