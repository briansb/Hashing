#include "pch.h"
#include "operations.h"
#include "input.h"
#include "support.h"
#include <iostream>

// index operator
BitUnit GetIndex(BitGroup& vbu, size_t index) {
	// no need to check for index<0 since size_t is unsigned
	if (index >= vbu.size()) {
		std::cout << "Index " << index << " is out of bounds" << std::endl;
		return BitUnit(0, "", false);
	}
	return vbu.vector_bit_unit[index];
}
// equality operator
bool EqualityCheck(BitGroup rhs, BitGroup lhs) {
	// for two BitGroup variables to be equal,
	//   sizes must be equal, bit values must be equal, symbols do NOT have to be equal
	if (rhs.size() == lhs.size()) {
		for (size_t index = 0; index<lhs.size(); ++index) {
			if ( rhs[index].get_bit() != lhs[index].get_bit() ) { return false; }
		}
	} else { return false; }
	return true;
}
// negation operator
BitGroup Negate(BitGroup lhs) {
	BitGroup Negated;
	if (lhs.size() == 0) {
		std::cout << "Can not NEGATE null value" << std::endl;
		return Negated;
	}
	// NEGATE the bits and symbols
	int single_bit;
	std::string new_symbol;
	for (size_t index = 0; index < lhs.size(); ++index) {
		single_bit = !lhs[index].get_bit();
		if (process_symbols) new_symbol = "(!" + lhs[index].get_symbol() + ")";
		Negated.vector_bit_unit.push_back(BitUnit(single_bit, new_symbol, false));
	}
	return Negated;
}
// addition operator
// HUGE!
// even though there may not be a carry, the POTENTIAL for a carry exists
// so one might have a 16-bit number after addition, but the 17th symbol bit will exist
BitGroup Sum(BitGroup lhs, BitGroup rhs) {
	BitGroup total;
	if ((lhs.size() == 0) | (rhs.size() == 0)) {
		std::cout << "Can not add null values" << std::endl;
		return total;
	}
	if (lhs.size() > rhs.size()) {
		size_t pad = lhs.size()-rhs.size();
		AddLeadingZeros(pad, rhs.vector_bit_unit);
	} else if (lhs.size() < rhs.size()) {
		size_t pad = rhs.size() - lhs.size();
		AddLeadingZeros(pad, lhs.vector_bit_unit);
	}
	int carry = 0;
	int bit = 0;
	int addend1 = 0;
	int addend2 = 0;
	int intermediate = 0;
	// sizes are now equal
	for (size_t index = 0; index<lhs.size(); ++index) {
		addend1 = lhs[index].get_bit();
		addend2 = rhs[index].get_bit();
		intermediate = carry + addend1 + addend2;
		bit = intermediate % 2;
		carry = intermediate / 2;
		total.vector_bit_unit.push_back(BitUnit(bit, "", false));
	}
	if (carry == 1) {total.vector_bit_unit.push_back(BitUnit(1, "", false));}

	// add the symbols
	// ?? do we need to indicate where the carry came from ??  For now, no
	if (process_symbols) {
		std::string s;
		for (size_t index = 0; index < lhs.size(); ++index) {
			if (index == 0) {
				s = "(" + lhs[index].get_symbol() + "+" + rhs[index].get_symbol() + ")";
			}
			else if (lhs[index].get_symbol() == "") {
				s = "(" + rhs[index].get_symbol() + "+carry)";
			}
			else if (rhs[index].get_symbol() == "") {
				s = "(" + lhs[index].get_symbol() + "+carry)";
			}
			else {
				s = "(" + lhs[index].get_symbol() + "+" + rhs[index].get_symbol() + "+carry)";
			}
			total.vector_bit_unit[index].set_symbol(s);
		}
		// no matter the sizes, there could always POTENTIALLY be a carry
		if (carry ==1) {
			total.vector_bit_unit[total.size() - 1].set_symbol("(carry)");
		}
	}
	
	return total;
}

// bitwise AND
BitGroup GetAnd(BitGroup lhs, BitGroup rhs) {
	BitGroup Anded;
	if ((lhs.size() == 0) | (rhs.size() == 0)) {
		std::cout << "Can not AND null values" << std::endl;
		return Anded;
	}
	if (lhs.size() != rhs.size()) {
		std::cout << "Unequal sizes sent to AND function" << std::endl;
		return Anded;
	}
	// AND the bits and combine the symbols
	int single_bit;
	std::string new_symbol;
	for (size_t index = 0; index < rhs.size(); ++index) {
		single_bit = lhs[index].get_bit() & rhs[index].get_bit();
		if (process_symbols) new_symbol = "(" + lhs[index].get_symbol() + "&" + rhs[index].get_symbol() + ")";
		Anded.vector_bit_unit.push_back(BitUnit(single_bit, new_symbol, false));
	}
	return Anded;
}
// bitwise OR
BitGroup GetOr(BitGroup lhs, BitGroup rhs) {
	BitGroup Ored;
	if ((lhs.size() == 0) | (rhs.size() == 0)) {
		std::cout << "Can not OR null values" << std::endl;
		return Ored;
	}
	if (lhs.size() != rhs.size()) {
		std::cout << "Unequal sizes sent to OR function" << std::endl;
		return Ored;
	}
	// OR the bits and combine the symbols
	int single_bit;
	std::string new_symbol;
	for (size_t index = 0; index < rhs.size(); ++index) {
		single_bit = lhs[index].get_bit() | rhs[index].get_bit();
		if (process_symbols) new_symbol = "(" + lhs[index].get_symbol() + "|" + rhs[index].get_symbol() + ")";
		Ored.vector_bit_unit.push_back(BitUnit(single_bit, new_symbol, false));
	}
	return Ored;
}

BitGroup GetXOr(BitGroup lhs, BitGroup rhs) {
	BitGroup XOred;
	if ((lhs.size() == 0) | (rhs.size() == 0)) {
		std::cout << "Can not XOR null values" << std::endl;
		return XOred;
	}
	if (lhs.size() != rhs.size()) {
		std::cout << "Unequal sizes sent to XOR function" << std::endl;
		return XOred;
	}
	// XOR the bits and combine the symbols
	int single_bit;
	std::string new_symbol;
	for (size_t index = 0; index < rhs.size(); ++index) {
		single_bit = lhs[index].get_bit() ^ rhs[index].get_bit();
		if (process_symbols) new_symbol = "(" + lhs[index].get_symbol() + "^" + rhs[index].get_symbol() + ")";
		XOred.vector_bit_unit.push_back(BitUnit(single_bit, new_symbol, false));
	}
	return XOred;
}


BitGroup ShiftLeft(BitGroup lhs, size_t movement){
	if (lhs.size() == 0) { std::cout << "Can not SHIFT null value" << std::endl; return lhs;  }
	// movement is unsigned, so no need to check for <0
	if (movement > lhs.size()){ std::cout << "SHIFT amount is greater than word size" << std::endl; return lhs; }
	// if rotation/shift amount =0 or =size, no need to shift/rotate
	if ((movement==0) | (movement==lhs.size())) { return lhs;}

	BitGroup result;
	// put in the zeros
	for (size_t i = 0; i<movement; ++i) {
		result.vector_bit_unit.push_back(BitUnit(0, "(<<0)", false));
	}
	// do the shift left
	int new_bit;
	std::string new_symbol;
	for (size_t i=movement; i<lhs.size(); ++i) {
		new_bit = lhs[i-movement].get_bit();
		if (process_symbols) new_symbol = "(<<" + lhs[i - movement].get_symbol() + ")";
		result.vector_bit_unit.push_back(BitUnit(new_bit, new_symbol, false));	
	}

	return result;
}

BitGroup ShiftRight(BitGroup lhs, size_t movement){
	if (lhs.size() == 0) { std::cout << "Can not SHIFT null value" << std::endl; return lhs;  }
	if (movement > lhs.size()){ std::cout << "SHIFT amount is greater than word size" << std::endl; return lhs; }
	if ((movement==0) | (movement==lhs.size())) { return lhs;}

	BitGroup result;
	// do the shift right
	int new_bit;
	std::string new_symbol;
	for (size_t i=movement; i<lhs.size(); ++i) {
		new_bit = lhs[i].get_bit();
		if (process_symbols) new_symbol = "(>>" + lhs[i].get_symbol() + ")";
		result.vector_bit_unit.push_back(BitUnit(new_bit, new_symbol, false));	
	}
	// put in the zeros
	for (size_t i = 0; i<movement; ++i) {
		result.vector_bit_unit.push_back(BitUnit(0, "(>>0)", false));
	}

	return result;
}

BitGroup RotateLeft(BitGroup lhs, size_t movement){
	if (lhs.size() == 0) { std::cout << "Can not ROTATE null value" << std::endl; return lhs;  }
	if (movement > lhs.size()){ std::cout << "ROTATE amount is greater than word size" << std::endl; return lhs; }
	if ((movement==0) | (movement==lhs.size())) { return lhs;}

	BitGroup result;
	// put in the leftmost "movement" bits and symbols
	int new_bit;
	std::string new_symbol;
	size_t offset;
	for (size_t i = 0; i<movement; ++i) {
		offset = lhs.size() - movement + i;
		new_bit = lhs[offset].get_bit();
		if (process_symbols) new_symbol = "(<=" + lhs[offset].get_symbol() + ")";
		result.vector_bit_unit.push_back(BitUnit(new_bit, new_symbol, false));
	}
	// do the shift left
	for (size_t i=movement; i<lhs.size(); ++i) {
		new_bit = lhs[i-movement].get_bit();
		if (process_symbols) new_symbol = "(<=" + lhs[i - movement].get_symbol() + ")";
		result.vector_bit_unit.push_back(BitUnit(new_bit, new_symbol, false));	
	}

	return result;
}
BitGroup RotateRight(BitGroup lhs, size_t movement) {
	if (lhs.size() == 0) { std::cout << "Can not ROTATE null value" << std::endl; return lhs;  }
	if (movement > lhs.size()){ std::cout << "ROTATE amount is greater than word size" << std::endl; return lhs; }
	if ((movement==0) | (movement==lhs.size())) { return lhs;}

	BitGroup result;
	// do the shift right
	int new_bit;
	std::string new_symbol;
	for (size_t i=movement; i<lhs.size(); ++i) {
		new_bit = lhs[i].get_bit();
		if (process_symbols) new_symbol = "(>=" + lhs[i].get_symbol() + ")";
		result.vector_bit_unit.push_back(BitUnit(new_bit, new_symbol, false));	
	}
	// put in the rightmost "movement" bits and symbols
	size_t offset;
	for (size_t i = 0; i<movement; ++i) {
		offset = i;
		new_bit = lhs[offset].get_bit();
		if (process_symbols) new_symbol = "(>=" + lhs[offset].get_symbol() + ")";
		result.vector_bit_unit.push_back(BitUnit(new_bit, new_symbol, false));
	}

	return result;
}

BitGroup AppendTwoBitGroups(BitGroup base, BitGroup x) {
	// symbols not manipulated or transformed
	if (base.size() == 0) { return x; }
	if (x.size() == 0) { return base; }
	BitGroup increased;
	int new_bit;
	std::string new_symbol;
	for (size_t i = 0; i<x.size(); i++) {
		new_bit = x[i].get_bit();
		if (process_symbols) new_symbol = x[i].get_symbol();
		increased.vector_bit_unit.push_back(BitUnit(new_bit, new_symbol, false));
	}
	for (size_t i = 0; i<base.size(); i++) {
		new_bit = base[i].get_bit();
		if (process_symbols) new_symbol = base[i].get_symbol();
		increased.vector_bit_unit.push_back(BitUnit(new_bit, new_symbol, false));
	}
	return increased;
}
BitGroup PrependTwoBitGroups(BitGroup base, BitGroup x) {
	// symbols not manipulated or transformed
	if (base.size() == 0) { return x; }
	if (x.size() == 0) { return base; }
	BitGroup increased;
	int new_bit;
	std::string new_symbol;
	for (size_t i = 0; i<base.size(); i++) {
		new_bit = base[i].get_bit();
		if (process_symbols) new_symbol = base[i].get_symbol();
		increased.vector_bit_unit.push_back(BitUnit(new_bit, new_symbol, false));
	}
	for (size_t i = 0; i<x.size(); i++) {
		new_bit = x[i].get_bit();
		if (process_symbols) new_symbol = x[i].get_symbol();
		increased.vector_bit_unit.push_back(BitUnit(new_bit, new_symbol, false));
	}
	return increased;
}

BitGroup LeastSignificantBits(BitGroup x, size_t number) {
	BitGroup shorty;
	if (number <= 0) {return shorty;}
	if (number > x.size() ) { number = x.size();}
	int new_bit;
	std::string new_symbol;
	for (size_t i =0; i<number; i++) {
		new_bit = x[i].get_bit();
		if (process_symbols) new_symbol = x[i].get_symbol();
		shorty.vector_bit_unit.push_back(BitUnit(new_bit, new_symbol, false));
	}
	return shorty;
}

BitGroup ExtractBitsFromWord(BitGroup x, size_t start, size_t length) {
	// start is 0-based, counted from the right
	// iow, it's the exponent of the power of 2
	// if length=0 or length>x.size(), then extract to end of word
	BitGroup smaller;
	
	// start >= x.size() will result in a null BitGroup
	size_t firstindex = start;

	size_t lastindex;
	if ((length == 0) or (length > x.size())) { 
		lastindex = x.size(); }
	else if (start+length > x.size()) {
		lastindex = x.size();	}
	 else {
		lastindex = start+length; }


	int new_bit;
	std::string new_symbol;
	for (size_t i=firstindex; i<lastindex; ++i) {
		new_bit = x[i].get_bit();
		if (process_symbols) new_symbol = x[i].get_symbol();
		smaller.vector_bit_unit.push_back(BitUnit(new_bit, new_symbol, false));
	}
	return smaller;
}