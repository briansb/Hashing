#include "pch.h"
#include "symbol_tests.h"
#include "BitGroup.h"
#include <string>
#include <iostream>
#include <vector>

void tester_on();
void tester_off();
bool test_output(std::string message);
std::string print_results(std::string ID, bool result);

void symbol_tester() {
	// this module tests the functionality and manipulation of bit unit symbols
	// there will be some overlap with io_tests and op_tests
	// must come first due to automatic assigning of symbols

	std::cout << "Begin Symbol Testing" << std::endl;

	std::vector<std::string> test_names;
	std::vector<bool> test_results;
	bool result;

	tester_on();
	// All the tests go here

	// symbol io tests
	// default constructor
	BitGroup sym01;
	std::cout << sym01.symbols() << std::endl;
	result = test_output("\n");
	test_names.push_back("Test sym01");
	test_results.push_back(result);

	// null values
	// default constructor
	BitGroup sym02 = BitGroup();
	std::cout << sym02.symbols() << std::endl;
	result = test_output("\n");
	test_names.push_back("Test sym02");
	test_results.push_back(result);

	// constructors 1 and 2 have no symbol input, but symbols are still defined automatically
	// constructor #1
	BitGroup sym03 = BitGroup("b1010");
	std::cout << sym03.symbols() << std::endl;
	result = test_output("a3,a2,a1,a0\n");
	test_names.push_back("Test sym03");
	test_results.push_back(result);

	// constructor #2
	BitGroup sym04 = BitGroup("b1011110", 15);
	std::cout << sym04.symbols() << std::endl;
	result = test_output("b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0\n");
	test_names.push_back("Test sym04");
	test_results.push_back(result);
		
	// constructor #3
	BitGroup sym05 = BitGroup("b1011", "k");
	std::cout << sym05.symbols() << std::endl;
	result = test_output("k3,k2,k1,k0\n");
	test_names.push_back("Test sym05");
	test_results.push_back(result);

	// constructor #4
	BitGroup sym06 = BitGroup("b1011", 6, "l");
	std::cout << sym06.symbols() << std::endl;
	result = test_output("l5,l4,l3,l2,l1,l0\n");
	test_names.push_back("Test sym06");
	test_results.push_back(result);

	// illegal first character
	BitGroup sym07 = BitGroup("j1010");
	std::cout << sym07.symbols() << std::endl;
	result = test_output("j is not a legal first character\n\n");
	test_names.push_back("Test sym07");
	test_results.push_back(result);

	// binary input tests
	BitGroup sym08 = BitGroup("b");
	std::cout << sym08.symbols() << std::endl;
	result = test_output("c0\n");
	test_names.push_back("Test sym08");
	test_results.push_back(result);

	// check for binary zero value
	BitGroup sym09 = BitGroup("b0");
	std::cout << sym09.symbols() << std::endl;
	result = test_output("d0\n");
	test_names.push_back("Test sym09");
	test_results.push_back(result);

	// check for binary one value
	BitGroup sym10 = BitGroup("b1");
	std::cout << sym10.symbols() << std::endl;
	result = test_output("e0\n");
	test_names.push_back("Test sym10");
	test_results.push_back(result);

	// check for illegal binary string
	BitGroup sym11 = BitGroup("b10301");
	std::cout << sym11.symbols() << std::endl;
	result = test_output("10301 is not a legal binary string\n\n");
	test_names.push_back("Test sym11");
	test_results.push_back(result);

	// check for legal binary value
	BitGroup sym12 = BitGroup("b1010", "a");
	std::cout << sym12.symbols() << std::endl;
	result = test_output("a3,a2,a1,a0\n");
	test_names.push_back("Test sym12");
	test_results.push_back(result);

	// adds leading zeros
	BitGroup sym13 = BitGroup("b000011110000", 15, "b");
	std::cout << sym13.symbols() << std::endl;
	result = test_output("b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0\n");
	test_names.push_back("Test sym13");
	test_results.push_back(result);

	// change symbol delimiter
	BitGroup sym14 = BitGroup("b000011110000", 15, "b");
	std::cout << sym14.symbols("<->") << std::endl;
	result = test_output("b14<->b13<->b12<->b11<->b10<->b9<->b8<->b7<->b6<->b5<->b4<->b3<->b2<->b1<->b0\n");
	test_names.push_back("Test sym14");
	test_results.push_back(result);


	// symbol operator tests
	// check index operator
	// check for 0 index value
	BitGroup sym15 = BitGroup("b111000", "c");
	std::cout << sym15[0].get_symbol() << std::endl;
	result = test_output("c0\n");
	test_names.push_back("Test sym15");
	test_results.push_back(result);
	// check for middle element
	std::cout << sym15[3].get_symbol() << std::endl;
	result = test_output("c3\n");
	test_names.push_back("Test sym16");
	test_results.push_back(result);
	// check for last element
	size_t last = sym15.size() - 1;
	std::cout << sym15[last].get_symbol() << std::endl;
	result = test_output("c5\n");
	test_names.push_back("Test sym17");
	test_results.push_back(result);
	// check for element out-ot-bounds
	std::cout << sym15[12].get_symbol() << std::endl;
	result = test_output("Index 12 is out of bounds\n\n");
	test_names.push_back("Test sym18");
	test_results.push_back(result);

	// check copy constructor
	BitGroup sym16 = BitGroup("b1011", 6, "ez");
	BitGroup sym17 = sym16;  // copies sym16 to sym17
	std::cout << sym17.symbols("/") << std::endl;
	result = test_output("ez5/ez4/ez3/ez2/ez1/ez0\n");
	test_names.push_back("Test sym19");
	test_results.push_back(result);

	// check assignment operator
	sym16 = BitGroup("b1011", 8, "x01-");
	sym17 = sym16;   // assigns sym16 to sym17 
	std::cout << sym17.symbols() << std::endl;
	result = test_output("x01-7,x01-6,x01-5,x01-4,x01-3,x01-2,x01-1,x01-0\n");
	test_names.push_back("Test sym20");
	test_results.push_back(result);

	// check equality operator
	// sizes must be equal, all bits must be equal, symbols do not need to match
	BitGroup sym19 = BitGroup("b1011", 8, "by");
	std::cout << (sym16 == sym19) << std::endl;
	result = test_output("1\n");
	test_names.push_back("Test sym21");
	test_results.push_back(result);
	BitGroup sym20 = BitGroup("b1011", 7, "by");
	std::cout << (sym19 == sym20) << std::endl;
	result = test_output("0\n");
	test_names.push_back("Test sym22");
	test_results.push_back(result);
	BitGroup sym21 = BitGroup("b1111", 8, "by");
	std::cout << (sym19 == sym21) << std::endl;
	result = test_output("0\n");
	test_names.push_back("Test sym23");
	test_results.push_back(result);

	// check + operator
	BitGroup sym22 = BitGroup("b1000", "a");
	BitGroup sym23 = BitGroup("b1111", "b");
	BitGroup sym24 = sym22 + sym23;
	std::cout << sym24.symbols() << std::endl;
	result = test_output("(carry),(a3+b3+carry),(a2+b2+carry),(a1+b1+carry),(a0+b0)\n");
	test_names.push_back("Test sym24");
	test_results.push_back(result);

	BitGroup sym25 = BitGroup("b11111", "c");
	BitGroup sym26 = BitGroup("b11110000", "d");
	BitGroup sym27 = sym25 + sym26;
	std::cout << sym27.symbols() << std::endl;
	result = test_output("(carry),(d7+carry),(d6+carry),(d5+carry),(c4+d4+carry),(c3+d3+carry),(c2+d2+carry),(c1+d1+carry),(c0+d0)\n");
	test_names.push_back("Test sym25");
	test_results.push_back(result);

	BitGroup sym28 = BitGroup("b11110000", "e");
	BitGroup sym29 = BitGroup("b1111", "f");
	BitGroup sym30 = sym28 + sym29;
	std::cout << sym30.symbols() << std::endl;
	result = test_output("(e7+carry),(e6+carry),(e5+carry),(e4+carry),(e3+f3+carry),(e2+f2+carry),(e1+f1+carry),(e0+f0)\n");
	test_names.push_back("Test sym26");
	test_results.push_back(result);

	BitGroup sym31 = BitGroup("b11110000", "xn-");
	BitGroup sym32 = BitGroup("b11111", "yn-");
	BitGroup sym33 = sym31 + sym32;
	std::cout << sym33.symbols() << std::endl;
	result = test_output("(carry),(xn-7+carry),(xn-6+carry),(xn-5+carry),(xn-4+yn-4+carry),(xn-3+yn-3+carry),(xn-2+yn-2+carry),(xn-1+yn-1+carry),(xn-0+yn-0)\n");
	test_names.push_back("Test sym27");
	test_results.push_back(result);

	BitGroup sym34 = BitGroup("b101010", "w");
	BitGroup sym35 = sym24 + sym34;
	std::cout << sym35.symbols() << std::endl;
	result = test_output("(carry),(w5+carry),((carry)+w4+carry),((a3+b3+carry)+w3+carry),((a2+b2+carry)+w2+carry),((a1+b1+carry)+w1+carry),((a0+b0)+w0)\n");
	test_names.push_back("Test sym28");
	test_results.push_back(result);


	// bitwise AND operator
	BitGroup sym36 = BitGroup("b1111111", 7);
	BitGroup sym37 = BitGroup("b00000000", 8);
	BitGroup sym38 = sym36 & sym37;
	std::cout << sym38.symbols() << std::endl;
	result = test_output("Unequal sizes sent to AND function\n\n");
	test_names.push_back("Test sym29");
	test_results.push_back(result);

	BitGroup sym39 = BitGroup("b11111111", 8, "n");
	BitGroup sym40 = BitGroup("b00000000", 8, "o");
	BitGroup sym41 = sym39 & sym40;
	std::cout << sym41.symbols() << std::endl;
	result = test_output("(n7&o7),(n6&o6),(n5&o5),(n4&o4),(n3&o3),(n2&o2),(n1&o1),(n0&o0)\n");
	test_names.push_back("Test sym30");
	test_results.push_back(result);

	BitGroup sym42 = BitGroup("b11111111", 8, "p");
	BitGroup sym43 = BitGroup("b00011000", 8, "q");
	BitGroup sym44 = sym42 & sym43;
	std::cout << sym44.symbols() << std::endl;
	result = test_output("(p7&q7),(p6&q6),(p5&q5),(p4&q4),(p3&q3),(p2&q2),(p1&q1),(p0&q0)\n");
	test_names.push_back("Test sym31");
	test_results.push_back(result);

	BitGroup sym45 = BitGroup("b111111111111", 12, "r");
	BitGroup sym46 = BitGroup("b11001100", 12, "s");
	BitGroup sym47 = sym45 & sym46;
	std::cout << sym47.symbols() << std::endl;
	result = test_output("(r11&s11),(r10&s10),(r9&s9),(r8&s8),(r7&s7),(r6&s6),(r5&s5),(r4&s4),(r3&s3),(r2&s2),(r1&s1),(r0&s0)\n");
	test_names.push_back("Test sym32");
	test_results.push_back(result);

	// bitwise OR operator
	BitGroup sym48 = BitGroup("b1111111", 7);
	BitGroup sym49 = BitGroup("b00000000", 8);
	BitGroup sym50 = sym48 | sym49;
	std::cout << sym50.symbols() << std::endl;
	result = test_output("Unequal sizes sent to OR function\n\n");
	test_names.push_back("Test sym33");
	test_results.push_back(result);

	BitGroup sym51 = BitGroup("b11111111", 8, "n");
	BitGroup sym52 = BitGroup("b00000000", 8, "o");
	BitGroup sym53 = sym51 | sym52;
	std::cout << sym53.symbols() << std::endl;
	result = test_output("(n7|o7),(n6|o6),(n5|o5),(n4|o4),(n3|o3),(n2|o2),(n1|o1),(n0|o0)\n");
	test_names.push_back("Test sym34");
	test_results.push_back(result);

	BitGroup sym54 = BitGroup("b11111111", 8, "p");
	BitGroup sym55 = BitGroup("b00011000", 8, "q");
	BitGroup sym56 = sym54 | sym55;
	std::cout << sym56.symbols() << std::endl;
	result = test_output("(p7|q7),(p6|q6),(p5|q5),(p4|q4),(p3|q3),(p2|q2),(p1|q1),(p0|q0)\n");
	test_names.push_back("Test sym35");
	test_results.push_back(result);

	BitGroup sym57 = BitGroup("b111111111111", 12, "r");
	BitGroup sym58 = BitGroup("b11001100", 12, "s");
	BitGroup sym59 = sym57 | sym58;
	std::cout << sym59.symbols() << std::endl;
	result = test_output("(r11|s11),(r10|s10),(r9|s9),(r8|s8),(r7|s7),(r6|s6),(r5|s5),(r4|s4),(r3|s3),(r2|s2),(r1|s1),(r0|s0)\n");
	test_names.push_back("Test sym36");
	test_results.push_back(result);

	// Shift functions
	// null value
	BitGroup sym60 = sym01 << 3;
	std::cout << sym60.symbols() << std::endl;
	result = test_output("Can not SHIFT null value\n\n");
	test_names.push_back("Test sym37");
	test_results.push_back(result);
	sym60 = sym01 >> 6;
	std::cout << sym60.symbols() << std::endl;
	result = test_output("Can not SHIFT null value\n\n");
	test_names.push_back("Test sym38");
	test_results.push_back(result);

	// shift amount too big
	sym60 = BitGroup("b10101010", "m");
	BitGroup sym61 = sym60 >> 23;
	std::cout << sym61.symbols() << std::endl;
	result = test_output("SHIFT amount is greater than word size\nm7,m6,m5,m4,m3,m2,m1,m0\n");
	test_names.push_back("Test sym39");
	test_results.push_back(result);
	sym61 = sym60 << 12;
	std::cout << sym61.symbols() << std::endl;
	result = test_output("SHIFT amount is greater than word size\nm7,m6,m5,m4,m3,m2,m1,m0\n");
	test_names.push_back("Test sym40");
	test_results.push_back(result);

	// check for shift=0 and shift=size()
	sym60 = BitGroup("b11001100", "n");
	sym61 = sym60 >> 0;
	std::cout << sym61.symbols() << std::endl;
	result = test_output("n7,n6,n5,n4,n3,n2,n1,n0\n");
	test_names.push_back("Test sym41");
	test_results.push_back(result);
	sym61 = sym60 >> 8;
	std::cout << sym61.symbols() << std::endl;
	result = test_output("n7,n6,n5,n4,n3,n2,n1,n0\n");
	test_names.push_back("Test sym42");
	test_results.push_back(result);
	sym61 = sym60 << 0;
	std::cout << sym61.symbols() << std::endl;
	result = test_output("n7,n6,n5,n4,n3,n2,n1,n0\n");
	test_names.push_back("Test sym43");
	test_results.push_back(result);
	sym61 = sym60 << 8;
	std::cout << sym61.symbols() << std::endl;
	result = test_output("n7,n6,n5,n4,n3,n2,n1,n0\n");
	test_names.push_back("Test sym44");
	test_results.push_back(result);

	// legal shifts
	sym60 = BitGroup("b11110000", "x");
	sym61 = sym60 >> 2;
	std::cout << sym61.symbols() << std::endl;
	result = test_output("(>>0),(>>0),(>>x7),(>>x6),(>>x5),(>>x4),(>>x3),(>>x2)\n");
	test_names.push_back("Test sym45");
	test_results.push_back(result);
	sym61 = sym60 >> 5;
	std::cout << sym61.symbols() << std::endl;
	result = test_output("(>>0),(>>0),(>>0),(>>0),(>>0),(>>x7),(>>x6),(>>x5)\n");
	test_names.push_back("Test sym46");
	test_results.push_back(result);
	sym60 = BitGroup("b00001111", 8, "y");
	sym61 = sym60 << 3;
	std::cout << sym61.symbols() << std::endl;
	result = test_output("(<<y4),(<<y3),(<<y2),(<<y1),(<<y0),(<<0),(<<0),(<<0)\n");
	test_names.push_back("Test sym47");
	test_results.push_back(result);
	sym61 = sym60 << 6;
	std::cout << sym61.symbols() << std::endl;
	result = test_output("(<<y1),(<<y0),(<<0),(<<0),(<<0),(<<0),(<<0),(<<0)\n");
	test_names.push_back("Test sym48");
	test_results.push_back(result);

	// Rotation functions
	// null value
	BitGroup sym62 = sym01 <= 3;
	std::cout << sym62.symbols() << std::endl;
	result = test_output("Can not ROTATE null value\n\n");
	test_names.push_back("Test sym49");
	test_results.push_back(result);
	sym62 = sym01 >= 6;
	std::cout << sym62.symbols() << std::endl;
	result = test_output("Can not ROTATE null value\n\n");
	test_names.push_back("Test sym50");
	test_results.push_back(result);

	// rotations amount too big
	sym62 = BitGroup("b10101010", "m");
	BitGroup sym63 = sym62 >= 23;
	std::cout << sym63.symbols() << std::endl;
	result = test_output("ROTATE amount is greater than word size\nm7,m6,m5,m4,m3,m2,m1,m0\n");
	test_names.push_back("Test sym51");
	test_results.push_back(result);
	sym63 = sym62 <= 12;
	std::cout << sym63.symbols() << std::endl;
	result = test_output("ROTATE amount is greater than word size\nm7,m6,m5,m4,m3,m2,m1,m0\n");
	test_names.push_back("Test sym52");
	test_results.push_back(result);

	// check for rotation=0 and rotation=size()
	sym62 = BitGroup("b11001100", "n");
	sym63 = sym62 >= 0;
	std::cout << sym63.symbols() << std::endl;
	result = test_output("n7,n6,n5,n4,n3,n2,n1,n0\n");
	test_names.push_back("Test sym53");
	test_results.push_back(result);
	sym63 = sym62 >= 8;
	std::cout << sym63.symbols() << std::endl;
	result = test_output("n7,n6,n5,n4,n3,n2,n1,n0\n");
	test_names.push_back("Test sym54");
	test_results.push_back(result);
	sym63 = sym62 <= 0;
	std::cout << sym63.symbols() << std::endl;
	result = test_output("n7,n6,n5,n4,n3,n2,n1,n0\n");
	test_names.push_back("Test sym55");
	test_results.push_back(result);
	sym63 = sym62 <= 8;
	std::cout << sym63.symbols() << std::endl;
	result = test_output("n7,n6,n5,n4,n3,n2,n1,n0\n");
	test_names.push_back("Test sym56");
	test_results.push_back(result);

	// legal rotations
	sym62 = BitGroup("b11110000", "x");
	sym63 = sym62 >= 2;
	std::cout << sym63.symbols() << std::endl;
	result = test_output("(>=x1),(>=x0),(>=x7),(>=x6),(>=x5),(>=x4),(>=x3),(>=x2)\n");
	test_names.push_back("Test sym57");
	test_results.push_back(result);
	sym63 = sym62 >= 5;
	std::cout << sym63.symbols() << std::endl;
	result = test_output("(>=x4),(>=x3),(>=x2),(>=x1),(>=x0),(>=x7),(>=x6),(>=x5)\n");
	test_names.push_back("Test sym58");
	test_results.push_back(result);
	sym62 = BitGroup("b00001111", 8, "y");
	sym63 = sym62 <= 3;
	std::cout << sym63.symbols() << std::endl;
	result = test_output("(<=y4),(<=y3),(<=y2),(<=y1),(<=y0),(<=y7),(<=y6),(<=y5)\n");
	test_names.push_back("Test sym59");
	test_results.push_back(result);
	sym63 = sym62 <= 6;
	std::cout << sym63.symbols() << std::endl;
	result = test_output("(<=y1),(<=y0),(<=y7),(<=y6),(<=y5),(<=y4),(<=y3),(<=y2)\n");
	test_names.push_back("Test sym60");
	test_results.push_back(result);

	// append and prepend
	// nulls (only checking append...code is the same in prepend)
	BitGroup sym64 = BitGroup("b11110000","a");
	BitGroup sym65 = sym64.append(BitGroup());
	std::cout << sym65.symbols() << std::endl;
	result = test_output("a7,a6,a5,a4,a3,a2,a1,a0\n");
	test_names.push_back("Test sym61");
	test_results.push_back(result);
	// append value
	BitGroup sym66 = BitGroup("b1111", "b");
	BitGroup sym67 = sym64.append(sym66);
	std::cout << sym67.symbols() << std::endl;
	result = test_output("a7,a6,a5,a4,a3,a2,a1,a0,b3,b2,b1,b0\n");
	test_names.push_back("Test sym62");
	test_results.push_back(result);
	// prepend value
	sym67 = sym64.prepend(sym66);
	std::cout << sym67.symbols() << std::endl;
	result = test_output("b3,b2,b1,b0,a7,a6,a5,a4,a3,a2,a1,a0\n");
	test_names.push_back("Test sym63");
	test_results.push_back(result);

	// get lsb bits
	BitGroup sym68 = BitGroup("b11110000","e");
	std::cout << sym68.lsb(-3).symbols() << std::endl;
	result = test_output("e7,e6,e5,e4,e3,e2,e1,e0\n");
	test_names.push_back("Test sym64");
	test_results.push_back(result);
	std::cout << sym68.lsb(32).symbols() << std::endl;
	result = test_output("e7,e6,e5,e4,e3,e2,e1,e0\n");
	test_names.push_back("Test sym65");
	test_results.push_back(result);
	std::cout << sym68.lsb(4).symbols() << std::endl;
	result = test_output("e3,e2,e1,e0\n");
	test_names.push_back("Test sym66");
	test_results.push_back(result);

	// extract smaller word from larger word
	BitGroup sym69 = BitGroup("b111100001111", "x");
	std::cout << sym69.subword(6, 5).symbols() << std::endl;
	result = test_output("x10,x9,x8,x7,x6\n");
	test_names.push_back("Test sym67");
	test_results.push_back(result);

	// bitwise XOR operator
	BitGroup sym70 = BitGroup("b1111111", 7, "a");
	BitGroup sym71 = BitGroup("b00000000", 8, "b");
	BitGroup sym72 = sym70 ^ sym71;
	std::cout << sym72.symbols() << std::endl;
	result = test_output("Unequal sizes sent to XOR function\n\n");
	test_names.push_back("Test sym68");
	test_results.push_back(result);

	BitGroup sym73 = BitGroup("b11111111", 8, "n");
	BitGroup sym74 = BitGroup("b00000000", 8, "o");
	BitGroup sym75 = sym73 ^ sym74;
	std::cout << sym75.symbols() << std::endl;
	result = test_output("(n7^o7),(n6^o6),(n5^o5),(n4^o4),(n3^o3),(n2^o2),(n1^o1),(n0^o0)\n");
	test_names.push_back("Test sym69");
	test_results.push_back(result);

	BitGroup sym76 = BitGroup("b11111111", 8, "p");
	BitGroup sym77 = BitGroup("b00011000", 8, "q");
	BitGroup sym78 = sym76 ^ sym77;
	std::cout << sym78.symbols() << std::endl;
	result = test_output("(p7^q7),(p6^q6),(p5^q5),(p4^q4),(p3^q3),(p2^q2),(p1^q1),(p0^q0)\n");
	test_names.push_back("Test sym70");
	test_results.push_back(result);

	BitGroup sym79 = BitGroup("b111111111111", 12, "r");
	BitGroup sym80 = BitGroup("b11001100", 12, "s");
	BitGroup sym81 = sym79 ^ sym80;
	std::cout << sym81.symbols() << std::endl;
	result = test_output("(r11^s11),(r10^s10),(r9^s9),(r8^s8),(r7^s7),(r6^s6),(r5^s5),(r4^s4),(r3^s3),(r2^s2),(r1^s1),(r0^s0)\n");
	test_names.push_back("Test sym71");
	test_results.push_back(result);

	//  bitwise Negation operator
	BitGroup sym82 = BitGroup("b1111000011110000", "k");
	BitGroup sym83 = !sym82;
	std::cout << sym83.symbols() << std::endl;
	result = test_output("(!k15),(!k14),(!k13),(!k12),(!k11),(!k10),(!k9),(!k8),(!k7),(!k6),(!k5),(!k4),(!k3),(!k2),(!k1),(!k0)\n");
	test_names.push_back("Test sym72");
	test_results.push_back(result);
	

	// multiple operation test
	BitGroup sym95 = (BitGroup("b1001", 4, "a") + BitGroup("b0101", 4, "b")) & BitGroup("b1010", 4, "d");
	BitGroup sym96 = ((BitGroup("b0100", 4, "f") | !sym95) << 2) ^ BitGroup("b1010", "m");
	BitGroup sym97 = BitGroup("b100000111","p") + ((BitGroup("b101","l") + ((BitGroup("b10111", 5, "i") + sym96) >= 1)) << 1);
	BitGroup sym98 = ((sym97.append(BitGroup("b101","aa")).prepend(BitGroup("b111", "bb"))).lsb(8)).subword(1,6);
	std::cout << sym98.symbols() << std::endl;
	result = test_output("(p3+(<<(l2+(>=(i3+((<<(f1|(!((a1+b1+carry)&d1))))^m3)+carry))+carry))+carry),"
						 "(p2+(<<(l1+(>=(i2+((<<(f0|(!((a0+b0)&d0))))^m2)+carry))+carry))+carry),"
						 "(p1+(<<(l0+(>=(i1+((<<0)^m1)+carry))))+carry),(p0+(<<0)),aa2,aa1\n");
	test_names.push_back("Test sym99");
	test_results.push_back(result);
	

	// End of tests
	tester_off();

	for (size_t i = 0; i < test_names.size(); ++i) {
		if (!test_results[i]) { std::cout << print_results(test_names[i], test_results[i]) << std::endl; }
		// Prints results for every test
		//std::cout << print_results(test_names[i], test_results[i]) << std::endl;
	}

	std::cout << "Finished Symbol Testing" << std::endl << std::endl;

}