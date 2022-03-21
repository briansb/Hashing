#include "pch.h"
#include "op_tests.h"
#include "BitGroup.h"
#include <string>
#include <iostream>
#include <vector>

void tester_on();
void tester_off();
bool test_output(std::string message);
std::string print_results(std::string ID, bool result);

void op_tester() {
	// this module tests the various operations..indexing, addition, etc.
	//   anything that is not input/output

	std::cout << "Begin Op Testing" << std::endl;

	std::vector<std::string> test_names;
	std::vector<bool> test_results;
	bool result;

	tester_on();
	// All the tests go here

	// operations tests
	// check index operator
	// check for attempt with null value
	BitGroup op00a;
	std::cout << op00a[0].get_bit() << std::endl;
	result = test_output("Index 0 is out of bounds\n0\n");
	test_names.push_back("Test op01");
	test_results.push_back(result);
	// check for 0 index value
	BitGroup op01 = BitGroup("b111000");
	std::cout << op01[0].get_bit() << std::endl;
	result = test_output("0\n");
	test_names.push_back("Test op02");
	test_results.push_back(result);
	// check for middle element
	std::cout << op01[3].get_bit() << std::endl;
	result = test_output("1\n");
	test_names.push_back("Test op03");
	test_results.push_back(result);
	// check for last element
	size_t last = op01.size() - 1;
	std::cout << op01[last].get_bit() << std::endl;
	result = test_output("1\n");
	test_names.push_back("Test op04");
	test_results.push_back(result);
	// check for element out-ot-bounds
	std::cout << op01[12].get_bit() << std::endl;
	result = test_output("Index 12 is out of bounds\n0\n");
	test_names.push_back("Test op05");
	test_results.push_back(result);

	// check copy constructor
	// null
	BitGroup op00b = op00a;
	std::cout << op00b.text() << std::endl;
	result = test_output("\n");
	test_names.push_back("Test op06");
	test_results.push_back(result);
	// not null
	BitGroup op02 = BitGroup("b1011", 6);
	BitGroup op03 = op02;  // copies op02 to op03
	std::cout << op03.text() << std::endl;
	result = test_output("001011\n");
	test_names.push_back("Test op07");
	test_results.push_back(result);

	// check assignment operator
	// null
	BitGroup op00c = BitGroup("b1010");
	op00c = op00a;
	std::cout << op00c.text() << std::endl;
	result = test_output("\n");
	test_names.push_back("Test op08");
	test_results.push_back(result);
	//not null
	op02 = BitGroup("b1011", 8);
	op03 = op02;   // assigns op02 to op03 
	std::cout << op03.text() << std::endl;
	result = test_output("00001011\n");
	test_names.push_back("Test op09");
	test_results.push_back(result);

	// check equality operator
	// null
	op00c = BitGroup("b1010", "x");
	std::cout << (op00a == op00c) << std::endl;
	result = test_output("0\n");
	test_names.push_back("Test op10");
	test_results.push_back(result);
	// not null
	BitGroup op04 = BitGroup("b1011", 8, "by");
	std::cout << (op02 == op04) << std::endl;
	result = test_output("1\n");
	test_names.push_back("Test op11");
	test_results.push_back(result);
	BitGroup op05 = BitGroup("b1011", 7, "by");
	std::cout << (op04 == op05) << std::endl;
	result = test_output("0\n");
	test_names.push_back("Test op12");
	test_results.push_back(result);
	BitGroup op06 = BitGroup("b1111", 8, "by");
	std::cout << (op05 == op06) << std::endl;
	result = test_output("0\n");
	test_names.push_back("Test op13");
	test_results.push_back(result);

	// check + operator
	// null values
	op00b = op00a + op00c;
	std::cout << op00b.text() << std::endl;
	result = test_output("Can not add null values\n\n");
	test_names.push_back("Test op14");
	test_results.push_back(result);
	// not null
	BitGroup op08 = BitGroup("b10","p");
	BitGroup op09 = BitGroup("b1111","q");
	BitGroup op10 = op08 + op09;
	std::cout << op10.text() << std::endl;
	result = test_output("10001\n");
	test_names.push_back("Test op15");
	test_results.push_back(result);

	BitGroup op11 = BitGroup("b11111", "mm");
	BitGroup op12 = BitGroup("b11110000", "nn");
	BitGroup op13 = op12 + op11;
	std::cout << op13.text() << std::endl;
	result = test_output("100001111\n");
	test_names.push_back("Test op16");
	test_results.push_back(result);

	BitGroup op14 = BitGroup("b10001111", "oo");
	BitGroup op15 = op13 + op14;
	std::cout << op15.text() << std::endl;
	result = test_output("110011110\n");
	test_names.push_back("Test op17");
	test_results.push_back(result);

	BitGroup op16 = op15 + op10;
	std::cout << op16.text() << std::endl;
	result = test_output("110101111\n");
	test_names.push_back("Test op18");
	test_results.push_back(result);

	// bitwise AND operator
	// null value 
	op00b = op00c & op00a;
	std::cout << op00b.text() << std::endl;
	result = test_output("Can not AND null values\n\n");
	test_names.push_back("Test op19");
	test_results.push_back(result);

	// not null
	BitGroup op17 = BitGroup("b1111111", 7, "x");
	BitGroup op18 = BitGroup("b00000000", 8, "y");
	BitGroup op19 = op17 & op18;
	result = test_output("Unequal sizes sent to AND function\n");
	test_names.push_back("Test op20");
	test_results.push_back(result);

	BitGroup op20 = BitGroup("b11111111", 8, "n");
	BitGroup op21 = BitGroup("b00000000", 8, "o");
	BitGroup op22 = op20 & op21;
	std::cout << op22.text() << std::endl;
	result = test_output("00000000\n");
	test_names.push_back("Test op21");
	test_results.push_back(result);

	BitGroup op23 = BitGroup("b11111111", 8, "p");
	BitGroup op24 = BitGroup("b00011000", 8, "q");
	BitGroup op25 = op23 & op24;
	std::cout << op25.text() << std::endl;
	result = test_output("00011000\n");
	test_names.push_back("Test op22");
	test_results.push_back(result);

	BitGroup op26 = BitGroup("b111111111111", 12, "r");
	BitGroup op27 = BitGroup("b11001100", 12, "s");
	BitGroup op28 = op26 & op27;
	std::cout << op28.text() << std::endl;
	result = test_output("000011001100\n");
	test_names.push_back("Test op23");
	test_results.push_back(result);

	// bitwise OR operator
	// null value 
	op00b = op00c | op00a;
	std::cout << op00b.text() << std::endl;
	result = test_output("Can not OR null values\n\n");
	test_names.push_back("Test op24");
	test_results.push_back(result);
	// not null
	BitGroup op29 = BitGroup("b1111111", 7, "x");
	BitGroup op30 = BitGroup("b00000000", 8, "y");
	BitGroup op31 = op29 | op30;
	result = test_output("Unequal sizes sent to OR function\n");
	test_names.push_back("Test op25");
	test_results.push_back(result);

	BitGroup op32 = BitGroup("b11111111", 8, "v");
	BitGroup op33 = BitGroup("b00000000", 8, "w");
	BitGroup op34 = op32 | op33;
	std::cout << op34.text() << std::endl;
	result = test_output("11111111\n");
	test_names.push_back("Test op26");
	test_results.push_back(result);

	BitGroup op35 = BitGroup("b11111111", 8, "x");
	BitGroup op36 = BitGroup("b00011000", 8, "y");
	BitGroup op37 = op35 | op36;
	std::cout << op37.text() << std::endl;
	result = test_output("11111111\n");
	test_names.push_back("Test op27");
	test_results.push_back(result);

	BitGroup op38 = BitGroup("b111111111111", 12, "z");
	BitGroup op39 = BitGroup("b11001100", 12, "A");
	BitGroup op40 = op38 | op39;
	std::cout << op40.text() << std::endl;
	result = test_output("111111111111\n");
	test_names.push_back("Test op28");
	test_results.push_back(result);

	// Shift functions
	// null value
	BitGroup op41 = op00a << 3;
	std::cout << op41.text() << std::endl;
	result = test_output("Can not SHIFT null value\n\n");
	test_names.push_back("Test op29");
	test_results.push_back(result);
	op41 = op00a >> 6;
	std::cout << op41.text() << std::endl;
	result = test_output("Can not SHIFT null value\n\n");
	test_names.push_back("Test op30");
	test_results.push_back(result);

	// shift amount too big
	op41 = BitGroup("b10101010", "aza");
	BitGroup op42 = op41 >> 23;
	std::cout << op42.text() << std::endl;
	result = test_output("SHIFT amount is greater than word size\n10101010\n");
	test_names.push_back("Test op31");
	test_results.push_back(result);
	op42 = op41 << 12;
	std::cout << op42.text() << std::endl;
	result = test_output("SHIFT amount is greater than word size\n10101010\n");
	test_names.push_back("Test op32");
	test_results.push_back(result);

	// check for shift=0 and shift=size()
	op41 = BitGroup("b11001100", "aza");
	op42 = op41 >> 0;
	std::cout << op42.text() << std::endl;
	result = test_output("11001100\n");
	test_names.push_back("Test op33");
	test_results.push_back(result);
	op42 = op41 >> 8;
	std::cout << op42.text() << std::endl;
	result = test_output("11001100\n");
	test_names.push_back("Test op34");
	test_results.push_back(result);
	op42 = op41 << 0;
	std::cout << op42.text() << std::endl;
	result = test_output("11001100\n");
	test_names.push_back("Test op35");
	test_results.push_back(result);
	op42 = op41 << 8;
	std::cout << op42.text() << std::endl;
	result = test_output("11001100\n");
	test_names.push_back("Test op36");
	test_results.push_back(result);

	// legal shifts
	op41 = BitGroup("b11110000", "x");
	op42 = op41 >> 2;
	std::cout << op42.text() << std::endl;
	result = test_output("00111100\n");
	test_names.push_back("Test op37");
	test_results.push_back(result);
	op42 = op41 >> 5;
	std::cout << op42.text() << std::endl;
	result = test_output("00000111\n");
	test_names.push_back("Test op38");
	test_results.push_back(result);
	op41 = BitGroup("b00001111", 8, "y");
	op42 = op41 << 3;
	std::cout << op42.text() << std::endl;
	result = test_output("01111000\n");
	test_names.push_back("Test op39");
	test_results.push_back(result);
	op42 = op41 << 6;
	std::cout << op42.text() << std::endl;
	result = test_output("11000000\n");
	test_names.push_back("Test op40");
	test_results.push_back(result);

	// Rotate functions
	// null value
	BitGroup op43 = op00a <= 3;
	std::cout << op43.text() << std::endl;
	result = test_output("Can not ROTATE null value\n\n");
	test_names.push_back("Test op41");
	test_results.push_back(result);
	op43 = op00a >= 6;
	std::cout << op43.text() << std::endl;
	result = test_output("Can not ROTATE null value\n\n");
	test_names.push_back("Test op42");
	test_results.push_back(result);

	// rotation amount too big
	op43 = BitGroup("b10101010", "b");
	BitGroup op44 = op43 >= 23;
	std::cout << op44.text() << std::endl;
	result = test_output("ROTATE amount is greater than word size\n10101010\n");
	test_names.push_back("Test op43");
	test_results.push_back(result);
	op44 = op43 <= 12;
	std::cout << op44.text() << std::endl;
	result = test_output("ROTATE amount is greater than word size\n10101010\n");
	test_names.push_back("Test op44");
	test_results.push_back(result);

	// check for rotation=0 and rotation=size()
	op43 = BitGroup("b11001100", "c");
	op44 = op43 >= 0;
	std::cout << op44.text() << std::endl;
	result = test_output("11001100\n");
	test_names.push_back("Test op45");
	test_results.push_back(result);
	op44 = op43 >= 8;
	std::cout << op44.text() << std::endl;
	result = test_output("11001100\n");
	test_names.push_back("Test op46");
	test_results.push_back(result);
	op44 = op43 <= 0;
	std::cout << op44.text() << std::endl;
	result = test_output("11001100\n");
	test_names.push_back("Test op47");
	test_results.push_back(result);
	op44 = op43 <= 8;
	std::cout << op44.text() << std::endl;
	result = test_output("11001100\n");
	test_names.push_back("Test op48");
	test_results.push_back(result);

	// legal rotations
	op43 = BitGroup("b11110000", "x");
	op44 = op43 >= 2;
	std::cout << op44.text() << std::endl;
	result = test_output("00111100\n");
	test_names.push_back("Test op49");
	test_results.push_back(result);
	op44 = op43 >= 5;
	std::cout << op44.text() << std::endl;
	result = test_output("10000111\n");
	test_names.push_back("Test op50");
	test_results.push_back(result);
	op43 = BitGroup("b00001111", 8, "y");
	op44 = op43 <= 3;
	std::cout << op44.text() << std::endl;
	result = test_output("01111000\n");
	test_names.push_back("Test op51");
	test_results.push_back(result);
	op44 = op43 <= 6;
	std::cout << op44.text() << std::endl;
	result = test_output("11000011\n");
	test_names.push_back("Test op52");
	test_results.push_back(result);

	// append and prepend
	// nulls (only checking append...code is the same in prepend)
	BitGroup op45 = BitGroup("b11110000","a");
	BitGroup op46 = op45.append(BitGroup());
	std::cout << op46.text() << std::endl;
	result = test_output("11110000\n");
	test_names.push_back("Test op53");
	test_results.push_back(result);
	op46 = BitGroup().append(op45);
	std::cout << op46.text() << std::endl;
	result = test_output("11110000\n");
	test_names.push_back("Test op54");
	test_results.push_back(result);
	// append value
	op46 = BitGroup("b1111", "b");
	BitGroup op47 = op45.append(op46);
	std::cout << op47.text() << std::endl;
	result = test_output("111100001111\n");
	test_names.push_back("Test op56");
	test_results.push_back(result);
	op47 = op46.append(op45);
	std::cout << op47.text() << std::endl;
	result = test_output("111111110000\n");
	test_names.push_back("Test op57");
	test_results.push_back(result);
	// prepend value
	op47 = op45.prepend(op46);
	std::cout << op47.text() << std::endl;
	result = test_output("111111110000\n");
	test_names.push_back("Test op58");
	test_results.push_back(result);
	op47 = op46.prepend(op45);
	std::cout << op47.text() << std::endl;
	result = test_output("111100001111\n");
	test_names.push_back("Test op59");
	test_results.push_back(result);

	// get lsb bits
	BitGroup op48 = BitGroup("b11110000","a");
	std::cout << op48.lsb(-3).text() << std::endl;
	result = test_output("11110000\n");
	test_names.push_back("Test op60");
	test_results.push_back(result);
	std::cout << op48.lsb(32).text() << std::endl;
	result = test_output("11110000\n");
	test_names.push_back("Test op61");
	test_results.push_back(result);
	std::cout << op48.lsb(5).text() << std::endl;
	result = test_output("10000\n");
	test_names.push_back("Test op62");
	test_results.push_back(result);

	// extract smaller word from larger word
	BitGroup op49 = BitGroup("b111100001111", "x");
	std::cout << op49.subword(6).text() << std::endl;
	result = test_output("111100\n");
	test_names.push_back("Test op63");
	test_results.push_back(result);
	std::cout << op49.subword(6, 24).text() << std::endl;
	result = test_output("111100\n");
	test_names.push_back("Test op64");
	test_results.push_back(result);
	std::cout << op49.subword(6, 5).text() << std::endl;
	result = test_output("11100\n");
	test_names.push_back("Test op65");
	test_results.push_back(result);
	std::cout << op49.subword(6, 6).text() << std::endl;
	result = test_output("111100\n");
	test_names.push_back("Test op66");
	test_results.push_back(result);
	std::cout << op49.subword(6, 7).text() << std::endl;
	result = test_output("111100\n");
	test_names.push_back("Test op67");
	test_results.push_back(result);
	std::cout << op49.subword(11, 6).text() << std::endl;
	result = test_output("1\n");
	test_names.push_back("Test op68");
	test_results.push_back(result);
	std::cout << op49.subword(12, 6).text() << std::endl;
	result = test_output("\n");
	test_names.push_back("Test op69");
	test_results.push_back(result);
	

	// bitwise XOR operator
	// null value 
	op00b = op00c ^ op00a;
	std::cout << op00b.text() << std::endl;
	result = test_output("Can not XOR null values\n\n");
	test_names.push_back("Test op71");
	test_results.push_back(result);
	// not null
	BitGroup op50 = BitGroup("b1111111", 7, "x");
	BitGroup op51 = BitGroup("b00000000", 8, "y");
	BitGroup op52 = op50 ^ op51;
	result = test_output("Unequal sizes sent to XOR function\n");
	test_names.push_back("Test op72");
	test_results.push_back(result);

	BitGroup op53 = BitGroup("b11111111", 8, "v");
	BitGroup op54 = BitGroup("b00000000", 8, "w");
	BitGroup op55 = op53 ^ op54;
	std::cout << op55.text() << std::endl;
	result = test_output("11111111\n");
	test_names.push_back("Test op73");
	test_results.push_back(result);

	BitGroup op56 = BitGroup("b11111111", 8, "x");
	BitGroup op57 = BitGroup("b00011000", 8, "y");
	BitGroup op58 = op56 ^ op57;
	std::cout << op58.text() << std::endl;
	result = test_output("11100111\n");
	test_names.push_back("Test op74");
	test_results.push_back(result);

	BitGroup op59 = BitGroup("b111111111111", 12, "z");
	BitGroup op60 = BitGroup("b11001100", 12, "A");
	BitGroup op61 = op59 ^ op60;
	std::cout << op61.text() << std::endl;
	result = test_output("111100110011\n");
	test_names.push_back("Test op75");
	test_results.push_back(result);

	// bitwise Negation operator
	// null value 
	op00b = !op00a;
	std::cout << op00b.text() << std::endl;
	result = test_output("Can not NEGATE null value\n\n");
	test_names.push_back("Test op76");
	test_results.push_back(result);

	BitGroup op62 = BitGroup("b11111111", 8, "v");
	BitGroup op63 = !op62;
	std::cout << op63.text() << std::endl;
	result = test_output("00000000\n");
	test_names.push_back("Test op77");
	test_results.push_back(result);

	BitGroup op64 = !BitGroup("b00011000", 8, "y");
	std::cout << op64.text() << std::endl;
	result = test_output("11100111\n");
	test_names.push_back("Test op78");
	test_results.push_back(result);


	// multiple operation test
	BitGroup op95 = (BitGroup("b1001", 4, "a") + BitGroup("b0101", 4, "b")) & BitGroup("b1010", 4, "d");
	BitGroup op96 = ((BitGroup("b0100", 4, "f") | (!op95)) << 2) ^ BitGroup("b1010", "m");
	BitGroup op97 = BitGroup("b100000111","p") + ((BitGroup("b101","l") + ((BitGroup("b10111", 5, "i") + op96) >= 1)) << 1);
	BitGroup op98 = ((op97.append(BitGroup("b101","aa")).prepend(BitGroup("b111", "bb"))).lsb(8)).subword(1,6);
	std::cout << op98.text() << std::endl;
	result = test_output("010110\n");
	test_names.push_back("Test op99");
	test_results.push_back(result);




	// End of tests
	tester_off();

	for (size_t i = 0; i < test_names.size(); ++i) {
		if (!test_results[i]) { std::cout << print_results(test_names[i], test_results[i]) << std::endl; }
		// Prints results for every test
		//std::cout << print_results(test_names[i], test_results[i]) << std::endl;
	}

	std::cout << "Finished Op Testing" << std::endl << std::endl;

}