#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <bitset> 

#include "definitions.h"

void LoadMessageFromString(std::string in, std::bitset<BITS_PER_CHARACTER * CHARACTERS_PER_WORD> m[MAX_BLOCKS][WORDS_PER_BLOCK], int &n);



















#endif

