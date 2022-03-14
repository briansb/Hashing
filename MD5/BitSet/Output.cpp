
#include "Output.h"


std::string OutputWord_Binary(std::bitset<BITS_PER_WORD> m[MAX_BLOCKS][WORDS_PER_BLOCK], int block, int word) {
	// add space between each btye (if BITS_PER_WORD is multiple of 8)
	std::string output_string;
	if (BITS_PER_WORD % BITS_PER_CHARACTER == 0) {
		for (size_t i = 0; i < m[block][word].to_string().length(); i = i + BITS_PER_CHARACTER) {
			output_string = output_string + m[block][word].to_string().substr(i, BITS_PER_CHARACTER) + " ";
		}
		return output_string;
	} else {
		return m[block][word].to_string();
	}
}

std::string OutputWord_Hex(std::bitset<BITS_PER_WORD> m[MAX_BLOCKS][WORDS_PER_BLOCK], int block, int word) {
	// add space between each btye (if BITS_PER_WORD is multiple of 8)
	std::string output_string;
	if (BITS_PER_WORD % BITS_PER_CHARACTER == 0) {
		for (size_t i = 0; i < m[block][word].to_string().length(); i = i + BITS_PER_CHARACTER) {
			output_string = output_string + ByteToHex(m[block][word].to_string().substr(i, BITS_PER_CHARACTER));
		}
		output_string = output_string + " ";
		return output_string;
	} else {
		return m[block][word].to_string();
	}
}

std::string ByteToHex(std::string byte_string) {

	std::string a = byte_string;
	return "ff";
}