#include "pch.h"
#include "input.h"
#include "support.h"
#include <iostream>
#include <iomanip>
#include <sstream>

int octal_groups[8][3] = {{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
int hexadecimal_groups[16][4] = {{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},
								{1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1},{1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}};

std::vector<BitUnit> create_vector_bit_unit(std::string input_value, size_t number_of_bits, std::string symbol, bool spare) {
	std::vector<BitUnit> vbu;

	// 1.  Deal with input_value
	if (input_value == "") { vbu.push_back(BitUnit(0, "", false)); }
	else {
		char first_char = input_value.substr(0, 1)[0];  // this nonsense is to convert to a char
		std::string digits = input_value.substr(1, input_value.size() - 1);
		switch (first_char) {
			case '\0':
				break;
			case 'b' :
			case 'B' :
				if (LegalBinaryString(digits)) { vbu = LoadBinaryDigits(digits); } 
				else { std::cout << digits << " is not a legal binary string" << std::endl; }
				break; 
			case 'o' :
			case 'O' :
				if (LegalOctalString(digits)) { vbu = LoadOctalDigits(digits); } 
				else { std::cout << digits << " is not a legal octal string" << std::endl; }
				break;
			case 'd' :
			case 'D' :
				if (LegalDecimalString(digits)) { vbu = LoadDecimalDigits(digits); } 
				else { std::cout << digits << " is not a legal decimal string" << std::endl; }
				break;
			case 'h' :
			case 'H' :
				if (LegalHexadecimalString(digits)) { vbu = LoadHexadecimalDigits(digits); } 
				else { std::cout << digits << " is not a legal hexadecimal string" << std::endl; }
				break;
			case 'c' :
			case 'C' :
				if (LegalAlphanumericString(digits)) { vbu = LoadAlphanumericDigits(digits); }
				else { std::cout << digits << " is not a legal alphanumeric string" << std::endl; }
				// can not allow truncation of leading zeros...required for ASCII
				number_of_bits = vbu.size();
				break;
			default :
				std::cout << first_char << " is not a legal first character" << std::endl;
				return vbu;
		}
	}

	// 2.  Deal with number_of_bits
	// take off leading zeros regardless of number_of_bits
	RemoveLeadingZeros(vbu);
	// number_of_bits = 0 means the vector_bit_unit will be the same size as the input_value string (minus the first character)
	// if number_of_bits < vbu.size, then send error
	if ((number_of_bits != 0) & (number_of_bits < vbu.size())) {
		std::cout << input_value << " too big for " << number_of_bits << " bits" << std::endl;
		vbu.clear();
		return vbu;
	}
	if (number_of_bits > vbu.size()) {
		size_t zeros_to_add = number_of_bits - vbu.size();
		AddLeadingZeros(zeros_to_add, vbu);
	}

	// 3.  Deal with symbol
	if (process_symbols) {
		if (symbol == "") {
			// use system-supplied symbol
			// with consecutive number appended
			PopulateSymbols(vbu, NextSymbol());
		}
		else {
			// use user-supplied symbol
			// with consecutive number appended
			PopulateSymbols(vbu, symbol);
		}
	}

	// 4.  Deal with spare, if present
	do {} while ((spare == true) & (spare == false));



	return vbu;
}

bool LegalBinaryString(std::string s) {
	for (size_t i = 0; i < s.size(); ++i) {
		if (s[i] != 48 and s[i] != 49) {
			return false;
		}
	}
	return true;
}
std::vector<BitUnit> LoadBinaryDigits(std::string binary_digits) {
	std::vector<BitUnit> vbu;
	if (binary_digits == "") { vbu.push_back(BitUnit(0, "", false)); return vbu; }
	for (size_t i = binary_digits.size(); i > 0; --i) {
		vbu.push_back(BitUnit(binary_digits[i-1] - 48, "", false));
	}
	return vbu;
}

bool LegalOctalString(std::string s) {
	for (size_t i = 0; i < s.size(); ++i) {
		if (s[i] < 48 or s[i] > 55) {
			return false;
		}
	}
	return true;
}
std::vector<BitUnit> LoadOctalDigits(std::string octal_digits) {
	std::vector<BitUnit> vbu;
	if (octal_digits == "") { vbu.push_back(BitUnit(0, "", false)); return vbu; }
	for (size_t i = octal_digits.size(); i > 0; --i) {
		int k = octal_digits[i-1] - 48;;
		for (int j = 2; j>=0; --j) {
			vbu.push_back(BitUnit(octal_groups[k][j], "", false));
		}
	}
	return vbu;
}

bool LegalDecimalString(std::string s) {
	for (size_t i = 0; i < s.size(); ++i) {
		if (s[i] < 48 or s[i] > 57) {
			return false;
		}
	}
	return true;
}
std::vector<BitUnit> LoadDecimalDigits(std::string decimal_digits) {
	std::vector<BitUnit> vbu;
	if (decimal_digits == "") { vbu.push_back(BitUnit(0, "", false)); return vbu; }

	// Dividend / Divisor = Quotient and Remainder
	// Divide by two repeatedly, and save the remainders...
	//     these are the bits of the number in binary
	std::string dividend = decimal_digits;
	std::string quotient = "";
	char remainder = '\0';
	do {
		DivideByTwo(dividend, quotient, remainder);
		dividend = quotient;
		vbu.push_back(BitUnit(remainder - 48, "", false));
	} while (quotient != "0");

	return vbu;
}

bool LegalHexadecimalString(std::string s) {
	for (size_t i = 0; i < s.size(); ++i) {
		if (!(s[i] >= 48 and s[i] <= 57) and !(s[i] >= 65 and s[i] <= 70) and !(s[i] >= 97 and s[i] <= 102)) {
			return false;
		}
	}
	return true;
}
std::vector<BitUnit> LoadHexadecimalDigits(std::string hexadecimal_digits) {
	std::vector<BitUnit> vbu;
	int k;
	if (hexadecimal_digits == "") { vbu.push_back(BitUnit(0, "", false)); return vbu; }
	for (size_t i = hexadecimal_digits.size(); i > 0; --i) {
		// this gets the correct index for hexadecimalgroups[][], defined above
		k = HexSymbolToDecimalInteger(hexadecimal_digits[i-1]);
		for (int j = 3; j>=0; --j) {
			vbu.push_back(BitUnit(hexadecimal_groups[k][j], "", false));
		}
	}
	return vbu;
}

bool LegalAlphanumericString(std::string s) {
	// The input of md5/sha1/etc is not characters/symbols but bytes.  All byte sequences are valid input.
	// To enter any  byte sequence, use the hex input format
	// This will check for numbers, letters, and special characters.
	// Range is decimal 32 through decimal 126, space through ~
	for (size_t i = 0; i < s.size(); ++i) {
		if (!(s[i] >= 32 and s[i] <= 126)) {
			return false;
		}
	}
	return true;
}
std::vector<BitUnit> LoadAlphanumericDigits(std::string alphanumeric_digits) {
	std::vector<BitUnit> vbu;
	if (alphanumeric_digits == "") { vbu.push_back(BitUnit(0, "", false)); return vbu; }
	std::ostringstream hex_string;
	for (size_t i = 0; i < alphanumeric_digits.size(); ++i) {
		hex_string << std::hex<< std::setw(2) << std::setfill('0') << int(alphanumeric_digits[i]);
	}
	// hex_string.str() contains the hexadecimal string representation of alphanumeric_digits
	// now use LoadHexadecimalDigits
	return LoadHexadecimalDigits(hex_string.str());
}

void PopulateSymbols(std::vector<BitUnit> &vbg, std::string s) {
	for (size_t i = 0; i < vbg.size(); ++i) {
		std::string index = std::to_string(i);
		vbg[i].set_symbol(s+index);
	}
}