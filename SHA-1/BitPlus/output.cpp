#include "pch.h"
#include "output.h"
#include "support.h"
#include <algorithm>
#include <iostream>
#include <sstream>


std::string BitValuesToBinaryString(std::vector<BitUnit> vbg) {
    if (vbg.size() == 0) { return "";}
    std::string s;
    // leftmost character in string is index 0
    // rightmost value in vbg is index 0
    // so, have to go backwards
    for (size_t i = vbg.size(); i>0; --i) {
        s += vbg[i-1].get_bit() + 48;
    }
    return s;
}
std::string BitValuesToBinaryString_extended(std::vector<BitUnit> vector_bit_unit, int group_size, std::string delimiter) {
    std::string s1 = BitValuesToBinaryString(vector_bit_unit);
	std::string s2 = AddDelimiters(s1, group_size, delimiter);
	std::string s = s2 + " (b" + std::to_string(s1.size()) + ")";
	return s;
}
std::string BitValuesToBinaryString_condensed(std::vector<BitUnit> vector_bit_unit, int group_size, std::string delimiter) {
    std::string s1 = BitValuesToBinaryString(vector_bit_unit);
	std::string s2 = AddDelimiters(s1, group_size, delimiter);
	std::string s = s2 + " (b" + std::to_string(s1.size()) + ")";
	// check for length <= 100
	if (s.size() <= 100) { return s; }
	// take out middle and insert ..........
	//   length to be condensed = 100 characters - length_of_trailing_bit_count - type_indicator - two_parentheses - ten_dots
	size_t total_group_size = group_size + delimiter.size();
	size_t starting_length = 100 - std::to_string(s1.size()).size() - 1 - 2 - 10;
	//std::cout << "Length to be condensed = " << starting_length << std::endl;

	// this will obviously be approximate 
	//   total length / total size of each group
	size_t number_of_groups = starting_length / total_group_size;
	//std::cout << "Number of groups = " << number_of_groups << std::endl;

	// first part of new string
	//  this number is "rounded down"
	size_t number_of_left_groups = number_of_groups / 2;
	size_t left_size = number_of_left_groups * total_group_size;
	std::string left_part = s.substr(0,left_size);

	// right side length
	size_t number_of_right_groups = number_of_left_groups + (number_of_groups % 2);
	//std::cout << "Number of right groups = " << number_of_right_groups << std::endl;
	// starting index for right substring = total_size - length_of_trailing_bit_count - type_indicator - two_parentheses - 
	//                                        (number_of_right_groups * total_group_size)
	size_t starting_index = s.size() - std::to_string(s1.size()).size() - 1 - 2 - (number_of_right_groups * total_group_size);
	//std::cout << "Starting index for right substring = " << starting_index << std::endl;
	std::string right_part = s.substr(starting_index);
	//std::cout << right_part << std::endl;

	std::string result = left_part + ".........." + right_part;

	return result;
}
std::string BitValuesToOctalString(std::vector<BitUnit> vbg) {
    if (vbg.size() == 0) { return "";}
    std::string s;
	// add zeros to get a multiple of three in the size
	size_t pad = 3 - (vbg.size() % 3);
	if (pad == 1) { AddLeadingZeros(1, vbg); }
	else if (pad == 2) { AddLeadingZeros(2, vbg); }
	for (size_t i = 0; i < vbg.size(); i = i + 3) {
		int number = (vbg[i].get_bit() * 1) + (vbg[i+1].get_bit() * 2) + (vbg[i + 2].get_bit() * 4);
		s += std::to_string(number);
    }
	std::reverse(s.rbegin(), s.rend());
	return s;
}
std::string BitValuesToOctalString_extended(std::vector<BitUnit> vector_bit_unit, int group_size, std::string delimiter) {
    std::string s1 = BitValuesToOctalString(vector_bit_unit);
	std::string s2 = AddDelimiters(s1, group_size, delimiter);
	std::string s = s2 + " (o" + std::to_string(s1.size()) + ")";
	return s;
}

std::string BitValuesToDecimalString(std::vector<BitUnit> vbg) {
    if (vbg.size() == 0) { return "";}
	// Uses  https://circuitglobe.com/decimal-to-binary-conversion-methods.html
    std::string s = "";
	std::string current = "0";
	for (size_t i = vbg.size(); i > 0; --i) {
		current = MultiplyByTwo(current);
		if (vbg[i-1].get_bit() == 1) {
			current = AddOne(current);
		}
	}
	return current;

}
std::string BitValuesToDecimalString_extended(std::vector<BitUnit> vector_bit_unit, int group_size, std::string delimiter) {
    std::string s1 = BitValuesToDecimalString(vector_bit_unit);
	std::string s2 = AddDelimiters(s1, group_size, delimiter);
	std::string s = s2 + " (d" + std::to_string(s1.size()) + ")";
	return s;
}

std::string BitValuesToHexadecimalString(std::vector<BitUnit> vbg) {
    if (vbg.size() == 0) { return "";}
    std::string s;
	// add zeros to get a multiple of four in the size
	size_t pad = 4 - (vbg.size() % 4);
	if (pad == 1) { AddLeadingZeros(1, vbg); }
	else if (pad == 2) { AddLeadingZeros(2, vbg); }
    else if (pad == 3) { AddLeadingZeros(3, vbg); }
	for (size_t i = 0; i < vbg.size(); i = i + 4) {
		int number = (vbg[i].get_bit() * 1) + (vbg[i+1].get_bit() * 2) + 
                     (vbg[i + 2].get_bit() * 4) + (vbg[i + 3].get_bit() * 8);
		s += DecimalIntegerToHexSymbol(number);
    }
	std::reverse(s.rbegin(), s.rend());
	return s;
}
std::string BitValuesToHexadecimalString_extended(std::vector<BitUnit> vector_bit_unit, int group_size, std::string delimiter) {
    std::string s1 = BitValuesToHexadecimalString(vector_bit_unit);
	std::string s2 = AddDelimiters(s1, group_size, delimiter);
	std::string s = s2 + " (h" + std::to_string(s1.size()) + ")";
	return s;
}

std::string BitValuesToAlphanumericString(std::vector<BitUnit> vbg) {
    std::string hex_string = BitValuesToHexadecimalString(vbg);
    std::string s;
    if (!(hex_string.size() % 2 == 0)) { std::cout << "Malformed alphanumeric string" << std::endl; return "";}
    for (size_t i = hex_string.size(); i>0; i-=2) {
        s += std::stoi(hex_string.substr(i-2,2), 0, 16);
    }
    std::reverse(s.rbegin(), s.rend());
    return s;
}
std::string BitValuesToAlphanumericString_extended(std::vector<BitUnit> vector_bit_unit, int group_size, std::string delimiter) {
	std::string s1 = BitValuesToAlphanumericString(vector_bit_unit);
	std::string s2 = AddDelimiters(s1, group_size, delimiter);
	std::string s = s2 + " (c" + std::to_string(s1.size()) + ")";
	return s;
}

std::string SymbolsToString(std::string delimiter, std::vector<BitUnit> vbg) {
    if (vbg.size() == 0) { return "";}
    std::string s;
    for (size_t i = vbg.size(); i>0; --i) {
        s += vbg[i-1].get_symbol();
        if (i != 1) {
            s += delimiter;
        }
    }
    return s;
}
std::string SymbolsToString_formatted(std::vector<BitUnit> vbg) {
	if (vbg.size() == 0) { return "";}
    std::ostringstream s;
    for (size_t i = vbg.size(); i>0; --i) {
		s << "[" << i-1 << "]: ";
		s << vbg[i-1].get_symbol() << std::endl;
    }
    return s.str();
}
std::string SpareToString(std::string delimiter, std::vector<BitUnit> vbg) {
	if (vbg.size() == 0) { return "";}
	std::ostringstream s;
    for (size_t i = vbg.size(); i>0; --i) {
        s << std:: boolalpha << vbg[i-1].get_spare();
        if (i != 1) {
            s << delimiter;
        }
    }
    return s.str();
}