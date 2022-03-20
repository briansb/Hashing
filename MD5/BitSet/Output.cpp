
#include "Output.h"

void PrintBlock(int n, std::bitset<BITS_PER_WORD> m[MAX_BLOCKS][WORDS_PER_BLOCK]) {

		std::cout << "Block " << n << ":" << std::endl;
		for (int j = 0; j < WORDS_PER_BLOCK; j++) {
			std::cout << "Word " << std::setfill('0') << std::setw(2) << j << " - ";
			std::cout << OutputWord_Binary(m, n, j) << " -> ";
			std::cout << OutputWord_Hex(m, n, j) << std::endl;
		}
		std::cout << std::endl;
}

std::string OutputWord_Binary(std::bitset<BITS_PER_WORD> m[MAX_BLOCKS][WORDS_PER_BLOCK], int block, int word) {
	// add space between each btye (if BITS_PER_WORD is multiple of 8)
	std::string output_string;
	if (BITS_PER_WORD % BITS_PER_BYTE == 0) {
		for (size_t i = 0; i < m[block][word].to_string().length(); i = i + BITS_PER_BYTE) {
			output_string = output_string + m[block][word].to_string().substr(i, BITS_PER_BYTE) + " ";
		}
		return output_string;
	} else {
		return m[block][word].to_string();
	}
}

std::string OutputWord_Hex(std::bitset<BITS_PER_WORD> m[MAX_BLOCKS][WORDS_PER_BLOCK], int block, int word) {
	// add space between each btye (if BITS_PER_WORD is multiple of 8)
	std::string output_string;
	if (BITS_PER_WORD % BITS_PER_BYTE == 0) {
		for (size_t i = 0; i < m[block][word].to_string().length(); i = i + BITS_PER_BYTE) {
			output_string = output_string + ByteToHex(m[block][word].to_string().substr(i, BITS_PER_BYTE));
		}
		output_string = output_string + " ";
		return output_string;
	} else {
		return m[block][word].to_string();
	}
}


std::string ByteToHex(std::string byte_string) {

	int i = (byte_string[0] - 48) * 8 + 
			(byte_string[1] - 48) * 4 +
			(byte_string[2] - 48) * 2 +
			(byte_string[3] - 48) * 1;
	int j = (byte_string[4] - 48) * 8 + 
			(byte_string[5] - 48) * 4 +
			(byte_string[6] - 48) * 2 +
			(byte_string[7] - 48) * 1;	

	return IntToHex(i) + IntToHex(j);
}

std::string IntToHex(int i)
{
  std::stringstream stream;
  stream << std::setw(1) << std::hex << i;
  return stream.str();
}
