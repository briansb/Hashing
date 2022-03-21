#ifndef UTILITIES_H
#define UTILITIES_H

#include "Definitions.h"
#include <bitset>

int *LoadShiftAmounts();
unsigned long* LoadConstants();
std::bitset<BITS_PER_WORD> LeftRotate(std::bitset<BITS_PER_WORD> b, int n);


#endif