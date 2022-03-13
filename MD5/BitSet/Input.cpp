
#include "Input.h"


void LoadMessageFromString(std::string in, std::bitset<BITS_PER_CHARACTER * CHARACTERS_PER_WORD> m[MAX_BLOCKS][WORDS_PER_BLOCK], int &n) {
	

	int shift_amount = 24;
	std::bitset< BITS_PER_CHARACTER * CHARACTERS_PER_WORD> single_entry;
	for (int i = 0; i < in.length(); i++) {

		

		single_entry = char(in[i]);
		single_entry = single_entry << shift_amount;
		m[0][0] = m[0][0].to_ullong() + single_entry.to_ullong();
		shift_amount -= BITS_PER_CHARACTER;



	}

}