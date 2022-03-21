#pragma once
#include "BitGroup.h"


std::vector<BitUnit> create_vector_bit_unit(std::string input_value, size_t number_of_bits, std::string symbol, bool spare);

bool LegalBinaryString(std::string s);
std::vector<BitUnit> LoadBinaryDigits(std::string binary_digits);
bool LegalOctalString(std::string s);
std::vector<BitUnit> LoadOctalDigits(std::string octal_digits);
bool LegalDecimalString(std::string s);
std::vector<BitUnit> LoadDecimalDigits(std::string decimal_digits);
bool LegalHexadecimalString(std::string s);
std::vector<BitUnit> LoadHexadecimalDigits(std::string hexadecimal_digits);
bool LegalAlphanumericString(std::string s);
std::vector<BitUnit> LoadAlphanumericDigits(std::string hexadecimal_digits);

void PopulateSymbols(std::vector<BitUnit> &v, std::string s);

// routine for spare, if present
