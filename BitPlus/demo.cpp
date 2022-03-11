#include "pch.h"
#include "demo.h"
#include "BitGroup.h"
#include <iostream>


void run_demo() {

	// this is the user's manual
	// demonstrates all the capabilities
	std::cout << "Null assignment:" << std::endl;
	BitGroup demo01;
	std::cout << "   BitGroup demo01; -> " << demo01.text_ext() << std::endl;

	std::cout << "Null assignment:" << std::endl;
	BitGroup demo02 = BitGroup();
	std::cout << "   BitGroup demo02 = BitGroup(); -> " << demo02.text_ext() << std::endl;

	std::cout << "Zero initialization:" << std::endl;
	BitGroup demo03 = BitGroup("");
	std::cout << "   BitGroup demo03 = BitGroup(\"\"); -> " << demo03.text_ext() << std::endl;

	std::cout << "Zero initialization:" << std::endl;
	BitGroup demo04 = BitGroup("b");
	std::cout << "   BitGroup demo04 = BitGroup(\"b\"); -> " << demo04.text_ext() << std::endl;

	std::cout << "Specify number of bits:" << std::endl;
	BitGroup demo05 = BitGroup("b11001100", 13);
	std::cout << "   BitGroup(\"b11001100\", 13) -> " << demo05.text_ext() << std::endl;

	std::cout << "Specify symbol:" << std::endl;
	BitGroup demo06 = BitGroup("b1011", "k");
	std::cout << "   BitGroup(\"b1011\", \"k\") -> " << demo06.symbols() << std::endl;

	std::cout << "Specify number of bits and symbol:" << std::endl;
	BitGroup demo07 = BitGroup("b1011", 6, "l");
	std::cout << "   BitGroup(\"b1011\", 6, \"l\") -> " << demo07.text_ext() << " -> " << demo07.symbols() << std::endl;

	std::cout << "Truncate leading zeros:" << std::endl;
	BitGroup demo08 = BitGroup("b000011110000");
	std::cout << "   BitGroup(\"b000011110000\") -> " << demo08.text_ext() << std::endl;

	std::cout << "Input options:" << std::endl;
	BitGroup demo09 = BitGroup("o2735651");
	std::cout << "   octal input, BitGroup(\"o2735651\") -> " << demo09.text_ext() << std::endl;
	BitGroup demo10 = BitGroup("d123456789009");
	std::cout << "   decimal input, BitGroup(\"d123456789009\") -> " << demo10.text_ext() << std::endl;
	BitGroup demo11 = BitGroup("h27a56d51f");
	std::cout << "   hexadecimal input, BitGroup(\"h27a56d51f\") -> " << demo11.text_ext() << std::endl;
	BitGroup demo12 = BitGroup("c !\"4& }M");
	std::cout << "   character input, BitGroup(\"c!4# $}M~\") -> " << demo12.text_ext() << std::endl;

	std::cout << "Output options: BitGroup(\"b011000010110001001100011\", 24, \"x\")" << std::endl;
	BitGroup demo13 = BitGroup("b011000010110001001100011", 24, "x");
	std::cout << "   normal text -> " << demo13.text() << std::endl;
	std::cout << "   extended text -> " << demo13.text_ext() << std::endl;
	std::cout << "   octal output -> " << demo13.otext_ext() << std::endl;
	std::cout << "   decimal output -> " << demo13.dtext_ext() << std::endl;
	std::cout << "   hexadecimal output -> " << demo13.htext_ext() << std::endl;
	std::cout << "   character output -> " << demo13.ctext_ext() << std::endl;
	std::cout << "   symbols -> " << demo13.symbols() << std::endl;
	std::cout << "   2-bit group size, _|_ delimiter -> " << demo13.text_ext(2, "_|_") << std::endl;
	std::cout << "   @@ symbol delimiter -> " << demo13.symbols("@@").substr(0,80) << "..." << std::endl;

	std::cout << "Get individual bits: BitGroup(\"b1111010000\", \"Xi\")" << std::endl;
	BitGroup demo14 = BitGroup("b1111010000", "Xi");
	std::cout << "   Get individual bit 5 -> " << demo14[5].get_bit() << std::endl;
	std::cout << "   Get individual symbol 5 -> " << demo14[5].get_symbol() << std::endl;
	std::cout << "Set individual bits: BitGroup(\"b1111010000\", \"Xi\")" << std::endl;
	demo14.vector_bit_unit[2].set_bit(1);
	std::cout << "   Set individual bit 2 -> " << demo14.text() << std::endl;
	demo14.vector_bit_unit[3].set_symbol("Nu");
	std::cout << "   Set individual symbol 3 -> " << demo14.symbols() << std::endl;

	BitGroup demo15 = demo14;
	std::cout << "Assignment operator, BitGroup demo15 = demo14; -> " << demo15.text() << ", " << demo15.symbols() << std::endl;

	demo15 = demo08;
	std::cout << "Copy constructor, demo15 = demo08; -> " << demo15.text() << ", " << demo15.symbols() << std::endl;

	std::cout << "Equality operator, demo15 == demo14 -> " << (demo15 == demo14) << std::endl;

	BitGroup demo16 = BitGroup("b1100", "a");
	BitGroup demo17 = BitGroup("b1101", "b");
	std::cout << "Addition, BitGroup(\"b1100\", \"a\") + BitGroup(\"b1101\", \"b\") = -> " << (demo16 + demo17).text() <<
				 ", " << (demo16 + demo17).symbols() << std::endl;

	BitGroup demo18 = BitGroup("b1011", "x");
	BitGroup demo19 = BitGroup("b0110", 4, "y");
	std::cout << "Bitwise AND, BitGroup(\"b1011\", \"a\") & BitGroup(\"b0110\", 8, \"b\") = -> " << (demo18 & demo19).text() << 
				 ", " << (demo18 & demo19).symbols() << std::endl;

	std::cout << "Bitwise OR, BitGroup(\"b1011\", \"a\") | BitGroup(\"b0110\", 8, \"b\") = -> " << (demo18 | demo19).text() << 
				 ", " << (demo18 | demo19).symbols() << std::endl;

	std::cout << "Bitwise XOR, BitGroup(\"b1011\", \"a\") ^ BitGroup(\"b0110\", 8, \"b\") = -> " << (demo18 ^ demo19).text() <<
		", " << (demo18 ^ demo19).symbols() << std::endl;

	std::cout << "Bitwise Negation, !BitGroup(\"b1011\", \"a\") -> " << (!demo18).text() <<
		", " << (!demo18).symbols() << std::endl;

	std::cout << "Shift left 2, BitGroup(\"b11111111\", \"x\") << 2 -> " << (BitGroup("b11111111", "x") << 2).text() << 
				 ", " << (BitGroup("b11111111", "x") << 2).symbols() << std::endl;

	std::cout << "Rotate right 3, BitGroup(\"b10000011\", \"x\") >= 3 -> " << (BitGroup("b10000011", "x") >= 3).text() << 
				 ", " << (BitGroup("b10000011", "x") >= 3).symbols() << std::endl;

	std::cout << "Append BitGroup(\"b1101\") to BitGroup(\"b11110000\") -> " << BitGroup("b11110000").append(BitGroup("b1101")).text() << std::endl;
	std::cout << "Prepend BitGroup(\"b1101\") to BitGroup(\"b11110000\") -> " << BitGroup("b11110000").prepend(BitGroup("b1101")).text() << std::endl;

	std::cout << "Extract 5 least significant bits, BitGroup(\"b10101111\") -> " << BitGroup("b10101111").lsb(5).text() << std::endl;

	std::cout << "Extract a 4-bit word, starting at index 3,from BitGroup(\"b10101111\") -> " << BitGroup("b10101111").subword(3,4).text() << std::endl;

	BitGroup demo20 = BitGroup("C !\"#$%& }~");
	std::cout << "Condense output to 100 characters -> " << demo20.text_condensed() << std::endl;

	BitGroup demo95 = (BitGroup("b1001", 4, "a") + BitGroup("b0101", 4, "b")) & BitGroup("b1010", 4, "d");
	BitGroup demo96 = ((BitGroup("b0100", 4, "f") | !demo95) << 2) ^ BitGroup("b1010", "m");
	BitGroup demo97 = BitGroup("b100000111","p") + ((BitGroup("b101","l") + ((BitGroup("b10111", 5, "i") + demo96) >= 1)) << 1);
	BitGroup demo98 = ((demo97.append(BitGroup("b101","aa")).prepend(BitGroup("b111", "bb"))).lsb(8)).subword(1,6);
	std::cout << std::endl << "Multiple operations:" << std::endl;
	std::cout << "  BitGroup demo95 = (BitGroup(\"b1001\", 4, \"a\") + BitGroup(\"b0101\", 4, \"b\")) & BitGroup(\"b1010\", 4, \"d\");" << std::endl;
	std::cout << "  BitGroup demo96 = ((BitGroup(\"b0100\", 4, \"f\") | !demo95) << 2) ^ BitGroup(\"b1010\", \"m\");" << std::endl;
	std::cout << "  BitGroup demo97 = BitGroup(\"b100000111\",\"p\") + ((BitGroup(\"b101\",\"l\") + ((BitGroup(\"b10111\", 5, \"i\") + demo96) >= 1)) << 1);" << std::endl;
	std::cout << "  BitGroup demo98 = (demo97.append(BitGroup(\"b101\",\"aa\")).prepend(BitGroup(\"b111\", \"bb\"))).lsb(8);" << std::endl;
	std::cout << "    -> " << demo98.text_ext() << std::endl;
	std::cout << "    -> " << demo98.symbols() << std::endl;
	std::cout << "    -> " << demo98.symbols_formatted() << std::endl;
}

