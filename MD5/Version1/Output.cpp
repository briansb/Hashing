
#include "Output.h"

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
