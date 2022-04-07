#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>
#include <sstream>
#include <iomanip>
#include <bitset>


// can output a word, block, or message
std::string OutputBinary(uint32_t w);
std::string OutputHex(uint32_t w);

// overload to print individual bytes - byte 0 is least significant
std::string OutputBinary(uint32_t w, int byte_number);
std::string OutputHex(uint32_t w, int byte_number);

// overload to print string in hex
std::string OutputHex(std::string s);

#endif