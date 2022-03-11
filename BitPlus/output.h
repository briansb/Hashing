#pragma once
#include "BitUnit.h"
#include <vector>


std::string BitValuesToBinaryString(std::vector<BitUnit> vbg);
std::string BitValuesToBinaryString_extended(std::vector<BitUnit> vbg, int group_size, std::string delimiter);
std::string BitValuesToBinaryString_condensed(std::vector<BitUnit> vbg, int group_size, std::string delimiter);
std::string BitValuesToOctalString(std::vector<BitUnit> vbg);
std::string BitValuesToOctalString_extended(std::vector<BitUnit> vbg, int group_size, std::string delimiter);
std::string BitValuesToDecimalString(std::vector<BitUnit> vbg);
std::string BitValuesToDecimalString_extended(std::vector<BitUnit> vbg, int group_size, std::string delimiter);
std::string BitValuesToHexadecimalString(std::vector<BitUnit> vbg);
std::string BitValuesToHexadecimalString_extended(std::vector<BitUnit> vbg, int group_size, std::string delimiter);
std::string BitValuesToAlphanumericString(std::vector<BitUnit> vbg);
std::string BitValuesToAlphanumericString_extended(std::vector<BitUnit> vbg, int group_size, std::string delimiter);

std::string SymbolsToString(std::string delimiter, std::vector<BitUnit> vbg);
std::string SymbolsToString_formatted(std::vector<BitUnit> vbg);
std::string SpareToString(std::string delimiter, std::vector<BitUnit> vbg);

