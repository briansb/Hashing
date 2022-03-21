#include "pch.h"
#include "output.h"

// no delimiter specified by delim = 'z'
// binary representation of string
std::string print_bits(const std::string s, char delim) {
	int counter = 0;
	std::stringstream ss;
	std::bitset<8> bword;
	for (size_t i = 0; i < s.length(); ++i) {
		bword = s[i];
		if (i != s.length()-1) { 
			if (delim == 'z') { ss << bword; }
			else { ss << bword << delim; }}
		else { ss << bword; }
		counter += 1;
	}
	ss << " (" << counter * 8 << " bits)";
	//convert the stream buffer into a string
	return ss.str();
}
// hex representation of string
std::string print_bits_hex(const std::string s, char delim) {
	int counter = 0;
	std::stringstream ss;
	std::bitset<8> bword;
	for (size_t i = 0; i < s.length(); ++i) {
		bword = s[i];
		if (i != s.length()-1) { ss << std::hex << bword.to_ullong() << delim; }
		else { ss << std::hex << bword.to_ullong(); }
		counter += 1;
	}
	ss << " (" << std::dec << counter * 8 << " bits)";
	//convert the stream buffer into a string
	return ss.str();
}
// binary representation of 32-bit word
std::string print_bits(const uint32 x) {
	std::stringstream ss;
	std::bitset<32> bword = x;
	ss << bword;
	return ss.str();
}
// hex representation of 32-bit word
std::string print_bits_hex(const uint32 x) {
	std::stringstream ss;
	std::bitset<32> bword = x;
	ss << std::hex << bword.to_ullong();
	return ss.str();
}
// binary representation of variables a,b,c,d,e
std::string print_abcde_bits(const uint32 a, const uint32 b, const uint32 c, 
							 const uint32 d, const uint32 e) {
	std::stringstream ss;
	std::bitset<32> word1 = a;
	std::bitset<32> word2 = b;
	std::bitset<32> word3 = c;
	std::bitset<32> word4 = d;
	std::bitset<32> word5 = e;
	ss << "a = " << word1 << std::endl << "b = " << word2 << std::endl << "c = " << word3 << 
							std::endl << "d = " << word4 << std::endl << "e = " << word5;
	return ss.str();
}
// binary representation of variables a,b,c,d,e
std::string dump_to_csv(const uint32 a, const uint32 b, const uint32 c, 
							 const uint32 d, const uint32 e) {
	std::stringstream ss;
	std::bitset<32> word1 = a;
	std::bitset<32> word2 = b;
	std::bitset<32> word3 = c;
	std::bitset<32> word4 = d;
	std::bitset<32> word5 = e;
	ss << word1 << "," << word2 << "," << word3 << "," << word4 << "," << word5;
	return ss.str();
}
// binary representation of array of 32-bit words
std::string print_bits(const uint32 block[], int n, char delim) {
	int counter = 0;
	std::stringstream ss;
	std::bitset<32> bword;
	for (int i = 0; i < n; ++i) {
		bword = block[i];
		if (i != n-1) { ss << bword << delim; }
		else { ss << bword; }
		counter += 1;
	}
	ss << " (" << counter * 32 << " bits)";
	//convert the stream buffer into a string
	return ss.str();
}
// hex representation of array of 32-bit words
std::string print_bits_hex(const uint32 block[], int n, char delim) {
 	int counter = 0;
 	std::stringstream ss;
 	std::bitset<32> bword;
 	for (int i = 0; i < n; ++i) {
 		bword = block[i];
 		if (i != n-1) { ss << std::hex << bword.to_ullong() << delim; } 
		else { ss << bword.to_ullong(); }
 		counter += 1;
 	}
 	ss << " (" << std::dec << counter * 32 << " bits)";
 	//convert the stream buffer into a string
 	return ss.str();
}
