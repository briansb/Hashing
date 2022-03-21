#ifndef SHA1_HPP
#define SHA1_HPP

#include <string>
#include <iostream>

typedef unsigned long int uint32;      // needs to be at least 32 bits
typedef unsigned long long uint64;     // needs to be at least 64 bits

const unsigned int DIGEST_INTS = 5;    // number of 32bit integers in a SHA1 digest */
const unsigned int INITIAL_BLOCK_INTS = 16;  // initial number of 32-bit integers in block
const unsigned int FINAL_BLOCK_INTS = 80;    // final number of 32-bit integers in block */


std::string sha1(const std::string &message);
void Initialize();
void buffer_to_block(const std::string &buffer);

#endif /* SHA1_HPP */