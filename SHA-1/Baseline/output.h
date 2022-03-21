#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include "sha1.h"
#include <string>
#include <bitset>
#include <sstream>


// to have no delimiter, use 'z'
std::string print_bits(const std::string s, char delim = ' ');
std::string print_bits_hex(const std::string s, char delim = ' ');
std::string print_bits(const uint32 x);
std::string print_bits_hex(const uint32 x);
std::string print_abcde_bits(const uint32 a, const uint32 b, const uint32 c, const uint32 d, const uint32 e);
std::string dump_to_csv(const uint32 a, const uint32 b, const uint32 c, const uint32 d, const uint32 e);
std::string print_bits(const uint32 block[], int n, char delim = ' ');
std::string print_bits_hex(const uint32 block[], int n, char delim = ' ');


#endif /* OUTPUT_HPP */