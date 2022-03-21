#include "pch.h"
#include "BitUnit.h"
#include <iostream>

// default constructor
BitUnit::BitUnit() {}

// standard constructor
BitUnit::BitUnit(int n, std::string s, bool b) {
	bit = n;
    symbol = s;
    spare = b;
}

int BitUnit::get_bit() {
	return bit;
}
void BitUnit::set_bit(int n) {
	bit = n;
}
std::string BitUnit::get_symbol() {
	return symbol;
}
void BitUnit::set_symbol(std::string s) {
	symbol = s;
}
bool BitUnit::get_spare() {
	return spare;
}
void BitUnit::set_spare(bool b) {
	spare = b;
}