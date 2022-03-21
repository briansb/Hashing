#include "pch.h"
#include "BitGroup.h"
#include "input.h"
#include "output.h"
#include "operations.h"
#include <iostream>

// default constructor
BitGroup::BitGroup() {}

// all these constructors feed create_vector_bit_unit
// constructor #1
BitGroup::BitGroup(std::string input_value) {
	vector_bit_unit = create_vector_bit_unit(input_value, 0, "", false);
}
// constructor #2
BitGroup::BitGroup(std::string input_value, size_t number_of_bits) {
	vector_bit_unit = create_vector_bit_unit(input_value, number_of_bits, "", false);
}
// constructor #3
BitGroup::BitGroup(std::string input_value, std::string symbol) {
	vector_bit_unit = create_vector_bit_unit(input_value, 0, symbol, false);
}
// constructor #4
BitGroup::BitGroup(std::string input_value, size_t number_of_bits, std::string symbol) {
	vector_bit_unit = create_vector_bit_unit(input_value, number_of_bits, symbol, false);
}

//operators
// index
BitUnit BitGroup::operator [] (size_t index) {
	return GetIndex(*this, index);
}
// equality
bool BitGroup::operator == (BitGroup rhs) {
	return EqualityCheck(*this, rhs);
}
// negation
BitGroup BitGroup::operator ! () {
	return Negate(*this);
}
// addition
BitGroup BitGroup::operator + (BitGroup rhs) {
	return Sum(*this, rhs);
}

// bitwise AND
BitGroup BitGroup::operator & (BitGroup rhs) {
	return GetAnd(*this, rhs);
}

// bitwise OR
BitGroup BitGroup::operator | (BitGroup rhs) {
	return GetOr(*this, rhs);
}

// bitwise XOR
BitGroup BitGroup::operator ^ (BitGroup rhs) {
	return GetXOr(*this, rhs);
}

// shift word
BitGroup BitGroup::operator << (int movement) {
	return ShiftLeft(*this, movement);
}
BitGroup BitGroup::operator >> (int movement) {
	return ShiftRight(*this, movement);
}

// rotate word 
BitGroup BitGroup::operator <= (int movement) {
	return RotateLeft(*this, movement);
}
BitGroup BitGroup::operator >= (int movement) {
	return RotateRight(*this, movement);
}

size_t BitGroup::size() {
	return vector_bit_unit.size();
}

// prints BitGroup in native (binary) form

std::string BitGroup::text() {
	return BitValuesToBinaryString(vector_bit_unit);
}
// same as above, but with grouping and delimiters
std::string BitGroup::text_ext(int group_size, std::string delimiter) {
	return BitValuesToBinaryString_extended(vector_bit_unit, group_size, delimiter);
}
// same as above, but with grouping, delimiters and limited to 100 chars
std::string BitGroup::text_condensed(int group_size, std::string delimiter) {
	return BitValuesToBinaryString_condensed(vector_bit_unit, group_size, delimiter);
}

// prints BitGroup in octal form
std::string BitGroup::otext() {
	return BitValuesToOctalString(vector_bit_unit);
}
std::string BitGroup::otext_ext(int group_size, std::string delimiter) {
	return BitValuesToOctalString_extended(vector_bit_unit, group_size, delimiter);
}

// prints BitGroup in decimal form
std::string BitGroup::dtext() {
	return BitValuesToDecimalString(vector_bit_unit);
}
std::string BitGroup::dtext_ext(int group_size, std::string delimiter) {
	return BitValuesToDecimalString_extended(vector_bit_unit, group_size, delimiter);
}

// prints BitGroup in hexadecimal form
std::string BitGroup::htext() {
	return BitValuesToHexadecimalString(vector_bit_unit);
}
std::string BitGroup::htext_ext(int group_size, std::string delimiter) {
	return BitValuesToHexadecimalString_extended(vector_bit_unit, group_size, delimiter);
}

// prints BitGroup in string form (assumes each 8-bit section is a character)
std::string BitGroup::ctext() {
	return BitValuesToAlphanumericString(vector_bit_unit);
}
std::string BitGroup::ctext_ext(int group_size, std::string delimiter) {
	return BitValuesToAlphanumericString_extended(vector_bit_unit, group_size, delimiter);
}

// print symbols
std::string BitGroup::symbols(std::string delimiter) {
	return SymbolsToString(delimiter, vector_bit_unit);
}
// each bit symbol group on new line
std::string BitGroup::symbols_formatted() {
	return SymbolsToString_formatted(vector_bit_unit);
}
std::string BitGroup::spare_out(std::string delimiter) {
	return SpareToString(delimiter, vector_bit_unit);
}

// append & prepend
BitGroup BitGroup::append(BitGroup x) {
	return AppendTwoBitGroups(*this, x);
}
BitGroup BitGroup::prepend(BitGroup x) {
	return PrependTwoBitGroups(*this, x);
}


// returns the "number" least significant bits
BitGroup BitGroup::lsb(size_t number) {
	return LeastSignificantBits(*this, number);
}

// works like substring in reverse....extracts a binary word
// argument length is optional
BitGroup BitGroup::subword(size_t start, size_t length) {
	return ExtractBitsFromWord(*this, start, length);
}