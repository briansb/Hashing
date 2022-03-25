
#include "Utilities.h"

unsigned int RotateLeft(unsigned int b, int n) {
    return (b << n) | (b >> (32 - n));
}