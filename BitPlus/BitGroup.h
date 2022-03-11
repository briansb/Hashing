#pragma once
#include "BitUnit.h"
#include <vector>

//to make global variables work, you must
//   1.  declare in header as below
//   2.  then, in source code (that calls this header), initialize it
extern bool process_symbols;

class BitGroup {
public:
	std::vector<BitUnit> vector_bit_unit;

	BitGroup();
	BitGroup(std::string input_value);
	BitGroup(std::string input_value, size_t number_of_bits);
	BitGroup(std::string input_value, std::string symbol);
	BitGroup(std::string input_value, size_t number_or_bits, std::string symbol);

	// copy constructor
	//  If you do not declare a copy constructor, the compiler gives you one implicitly.
	//  The implicit copy constructor does a member-wise copy of the source object.
	// BitGroup is using the implicit copy constructor

	// assignment operator
	// If you do not declare an assignment operator, the compiler gives you one implicitly.  
	// The implicit assignment operator does member-wise assignment of each data member from the source object.
	// BitGroup is using the implicit assignment operator

	BitUnit operator [] (size_t index);

	bool operator == (BitGroup rhs);

	BitGroup operator ! ();

	BitGroup operator + (BitGroup rhs);

	BitGroup operator & (BitGroup rhs);

	BitGroup operator | (BitGroup rhs);  

	BitGroup operator ^ (BitGroup rhs);

	// shift left and right...  x << 2, y >> 4
	BitGroup operator << (int movement);
	BitGroup operator >> (int movement);

	// rotate left and right... x <<= 3, y >>= 1
	BitGroup operator <= (int movement);
	BitGroup operator >= (int movement);
	
	size_t size();

	std::string text();
	std::string text_ext(int group_size = 4, std::string delimiter = " ");
	std::string text_condensed(int group_size = 4, std::string delimiter = " ");
	std::string otext();
	std::string otext_ext(int group_size = 4, std::string delimiter = " ");
	std::string dtext();
	std::string dtext_ext(int group_size = 3, std::string delimiter = ",");
	std::string htext();
	std::string htext_ext(int group_size = 2, std::string delimiter = " ");
	std::string ctext();
	std::string ctext_ext(int group_size = 1000000, std::string delimiter = " ");
	std::string symbols(std::string delimiter = ",");
	std::string symbols_formatted();
	std::string spare_out(std::string delimiter = ",");

	// append & prepend
	BitGroup append(BitGroup x);
	BitGroup prepend(BitGroup x);

	// returns the "number" least significant bits
	BitGroup lsb(size_t number);

	// returns part of a word
	BitGroup subword(size_t start, size_t length = 0);

};