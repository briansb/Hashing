#pragma once
#include "BitUnit.h"
#include <string>
#include <vector>

// external - need this to be present, and uninitialized, across modules
extern std::string NextSymbol();

void RemoveLeadingZeros(std::vector<BitUnit> &v);
void AddLeadingZeros(size_t pad, std::vector<BitUnit> &v);
int HexSymbolToDecimalInteger(char c);
char DecimalIntegerToHexSymbol(int d);

std::string AddDelimiters(std::string s, int group_size, std::string delim);

void DivideByTwo(std::string dividend, std::string &quotient, char &remainder);
std::string MultiplyByTwo(std::string a);
std::string AddOne(std::string s);