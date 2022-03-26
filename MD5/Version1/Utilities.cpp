
#include "Utilities.h"
#include <stdint.h>

unsigned int RotateLeft(unsigned int b, int n) {
    return (b << n) | (b >> (32 - n));
}

unsigned int ToLittleEndian(unsigned int a) {
    
    unsigned int w, x, y, z;

    w = a << 24;
    x = ((a >> 8) << 24) >> 8;
    y = ((a << 8) >> 24) << 8;
    z = a >> 24;



    return w | x | y | z;
}