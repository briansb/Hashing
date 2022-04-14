
#include "Utilities.h"


unsigned int RotateLeft(unsigned int b, int n) {
    return (b << n) | (b >> (32 - n));
}

void WordToBytes(uint32_t word, uint8_t *byte_array) {
    byte_array[0] = (uint8_t) word;
    byte_array[1] = (uint8_t) (word >> 8);
    byte_array[2] = (uint8_t) (word >> 16);
    byte_array[3] = (uint8_t) (word >> 24);
    return;
}