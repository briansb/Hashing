#ifndef ROUTINE_H
#define ROUTINE_H

#include <vector>
#include <stdint.h>
#include "Utilities.h"

void GetMD5Hash(std::vector<uint32_t> words, uint8_t digest[]);

#endif