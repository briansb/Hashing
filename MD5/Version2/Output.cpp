
#include "Output.h"
#include <cstdio>

std::string OutputHex(uint32_t w) {
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(8) << std::hex << w;
    return stream.str();
}
std::string OutputBinary(uint32_t w) {
    std::stringstream stream;
    std::string out;
    stream << std::bitset<32>(w);
    out = stream.str();
    out.insert(24, 1, ' ');
    out.insert(16, 1, ' ');
    out.insert(8, 1, ' ');
    return out;
}

// overloaded methods
std::string OutputBinary(uint32_t w, int byte_number) {
    std::stringstream stream;
    std::string out;
    int shift_amount = 8 * byte_number;
    uint8_t temp = (uint8_t) (w >> shift_amount);
    stream << std::bitset<8>(temp);
    out = stream.str();
    return out;
}
std::string OutputHex(uint32_t w, int byte_number) {
    int shift_amount = 8 * byte_number;
    uint8_t temp = (uint8_t) (w >> shift_amount);
    char buffer[3];
    sprintf (buffer, "%2.2x", temp);
    return buffer;
}


