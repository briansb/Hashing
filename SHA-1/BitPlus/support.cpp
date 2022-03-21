#include "pch.h"
#include "support.h"
#include <iostream>
#include <sstream>
#include <algorithm>

char next_symbol = '`';
char prefix = '?';

std::string NextSymbol() {

	next_symbol += 1;

	if (next_symbol == 123) {
		if (prefix == '?') {
			// switch from single lower case to uppercase
			next_symbol = 65;
		}
	} else if (next_symbol == 91) {
		if (prefix == '?') {
			std::cout << "We're all out of 1-character symbols...switching to 2-character symbols" << std::endl;
			// switch to dual symbol
			prefix = 'a';
			next_symbol = 'A';
		} else {
			if (prefix == 122) {
				std::cout << "We're all out of 2-character symbols...switching to gibberish symbols" << std::endl;
				prefix += 1;
				next_symbol = 'A';
			} else {
				prefix += 1;
				next_symbol = 'A';
			}
		}
	}

	if (prefix == '?') {
		std::string s(1, next_symbol);
		return s;
	} else {
		std::string s1(1, prefix);
		std::string s2(1, next_symbol);
		return s1 + s2;
	}
}

void RemoveLeadingZeros(std::vector<BitUnit> &vbg) {
	if (vbg.size() <= 1) { return; }
	for (size_t index = vbg.size(); index>0; --index)
		if (vbg[index-1].get_bit() == 0) {
			vbg.erase(vbg.begin() + index -1);
		}
		else { break; }
	return;
}
void AddLeadingZeros(size_t pad, std::vector<BitUnit> &vbg) {
	for (size_t i = 0; i < pad; ++i) {
		vbg.push_back(BitUnit(0, "", false));
	}
	return;
}

int HexSymbolToDecimalInteger(char c) {
	// get a decimal value, 0 -> 15 , from a hexadecimal character
	if ((c>='0') and (c<='9')) {return c-48;}
	if ((c>='A') and (c<='F')) {return c-55;}
	if ((c>='a') and (c<='f')) {return c-87;}
	return -1;
}
char DecimalIntegerToHexSymbol(int d) {
	if ((d >= 0) and (d <= 9)) { return d + 48; }
	if ((d >= 10) and (d <= 15)) { return d + 87; }
	return 0;
}
std::string AddDelimiters(std::string s, int group_size, std::string delim) {
	// string[0] is left-most character
	std::ostringstream os;
	size_t sz = s.size();
	for (size_t i = 0; i < sz; i++) {
		os << s[sz - 1 - i];
		if (((i + 1) % group_size == 0) & ((sz - 1 - i) != 0)) {
			os << delim;
		}
	}
	std::string flop = os.str();
	std::reverse(flop.begin(), flop.end());
	return flop;
}

void DivideByTwo(std::string dividend, std::string &quotient, char &remainder) {
	// uses long division to halve a number
	// uses strings to avoid integer length problems
	int number = 0;
	int result = 0;
	int carry = 0;
	quotient = "";
	remainder = '\0';
	for (size_t i = 0; i < dividend.size(); i++) {
		number = (10 * carry) + int(dividend[i] - 48);
		result = number / 2;
		quotient += result + 48;
		carry = number % 2;
	}
	// lose leading zero
	if (quotient[0] == '0' and quotient.size() > 1) {
		quotient = quotient.substr(1, std::string::npos);
	}
	remainder = carry + 48;
	return;
}

std::string MultiplyByTwo(std::string a) {
	// 48 converts to and from ASCII
	int working = 0;
	int carry = 0;
	char digit = '\0';
	std::string s = "";
	std::string result = "";
	for (size_t i = a.size(); i > 0; i--) {
		working = ((a[i - 1] - 48) * 2) + carry;
		carry = working / 10;
		digit = (working % 10) + 48;
		s += digit;
	}
	if (carry == 1) { s += (carry + 48); }
	// reverse the string
	for (size_t i = s.length(); i > 0; --i) {
		result += s[i - 1];
	}
	return result;
}
std::string AddOne(std::string s) {
	// need to start at s[size-1] then loop down
	//     Remember, left-most character is s[0]
	std::string t = "";
	size_t sz = s.size() - 1;
	int result = s[sz] - 48 + 1;
	int carry = result / 10;
	char digit = (result % 10) + 48;
	std::string answer(1, digit);
	for (size_t i = sz; i > 0; i--) {
		if (carry == 0) {
			answer += s[i - 1];
		}
		else {
			result = (s[i - 1] - 48) + 1;
			carry = result / 10;
			digit = (result % 10) + 48;
			answer += digit;
		}
	}
	// must add the 1 to the left
	if (carry == 1) { answer += "1"; }
	// now reverse answer
	for (size_t i = answer.length(); i > 0; --i) {
		t += answer[i - 1];
	}
	return t;
}