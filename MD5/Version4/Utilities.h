#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdint.h>

//  rotates left (not shift)
unsigned int RotateLeft(unsigned int b, int n);

// loads least significant byte into byte_array[0]
// loads most significant byte into byte_array[3]
void WordToBytes(uint32_t word, uint8_t *byte_array);

#endif
