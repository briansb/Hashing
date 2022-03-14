#ifndef OUTPUT_H
#define OUTPUT_H


#include <iostream>
#include <bitset> 

#include "Definitions.h"


std::string OutputWord_Binary(std::bitset<BITS_PER_WORD> m[MAX_BLOCKS][WORDS_PER_BLOCK], int block, int word);
std::string OutputWord_Hex(std::bitset<BITS_PER_WORD> m[MAX_BLOCKS][WORDS_PER_BLOCK], int block, int word);
std::string ByteToHex(std::string byte_string);




#endif