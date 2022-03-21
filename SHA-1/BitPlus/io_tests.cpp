#include "pch.h"
#include "io_tests.h"
#include "BitGroup.h"
#include <string>
#include <iostream>
#include <vector>

void tester_on();
void tester_off();
bool test_output(std::string message);
std::string print_results(std::string ID, bool result);

void io_tester() {
	// 
	// this module tests the input and output routines
	// 
	std::cout << "Begin IO Testing" << std::endl;

	std::vector<std::string> test_names;
	std::vector<bool> test_results;
	bool result;

	tester_on();
	// All the tests go here

	// io tests
	// default constructor
	// null values
	BitGroup io01;
	std::cout << io01.text() << std::endl;
	std::cout << io01.text_ext() << std::endl;
	std::cout << io01.otext() << std::endl;
	std::cout << io01.otext_ext() << std::endl;
	std::cout << io01.dtext() << std::endl;
	std::cout << io01.dtext_ext() << std::endl;
	std::cout << io01.htext() << std::endl;
	std::cout << io01.htext_ext() << std::endl;
	std::cout << io01.ctext() << std::endl;
	std::cout << io01.ctext_ext() << std::endl;
	result = test_output("\n (b0)\n\n (o0)\n\n (d0)\n\n (h0)\n\n (c0)\n");
	test_names.push_back("Test io01");
	test_results.push_back(result);	
	
	// null values
	// default constructor
	BitGroup io02 = BitGroup();
	std::cout << io02.text() << std::endl;
	std::cout << io02.text_ext() << std::endl;
	std::cout << io02.otext() << std::endl;
	std::cout << io02.otext_ext() << std::endl;
	std::cout << io02.dtext() << std::endl;
	std::cout << io02.dtext_ext() << std::endl;
	std::cout << io02.htext() << std::endl;
	std::cout << io02.htext_ext() << std::endl;
	std::cout << io02.ctext() << std::endl;
	std::cout << io02.ctext_ext() << std::endl;
	result = test_output("\n (b0)\n\n (o0)\n\n (d0)\n\n (h0)\n\n (c0)\n");
	test_names.push_back("Test io02");
	test_results.push_back(result);

	// default value
	// constructor #1
	BitGroup io03 = BitGroup("");
	std::cout << io03.text() << std::endl;
	std::cout << io03.text_ext() << std::endl;
	std::cout << io03.otext() << std::endl;
	std::cout << io03.otext_ext() << std::endl;
	std::cout << io03.dtext() << std::endl;
	std::cout << io03.dtext_ext() << std::endl;
	std::cout << io03.htext() << std::endl;
	std::cout << io03.htext_ext() << std::endl;
	std::cout << io03.ctext() << std::endl;
	std::cout << io03.ctext_ext() << std::endl;
	result = test_output("0\n0 (b1)\n0\n0 (o1)\n0\n0 (d1)\n0\n0 (h1)\nMalformed alphanumeric string\n\nMalformed alphanumeric string\n (c0)\n");
	test_names.push_back("Test io03");
	test_results.push_back(result);

	// constructor #1
	BitGroup io04 = BitGroup("b11001100");
	std::cout << io04.text() << std::endl;
	std::cout << io04.text_ext() << std::endl;
	std::cout << io04.otext() << std::endl;
	std::cout << io04.otext_ext() << std::endl;
	std::cout << io04.dtext() << std::endl;
	std::cout << io04.dtext_ext() << std::endl;
	std::cout << io04.htext() << std::endl;
	std::cout << io04.htext_ext() << std::endl;
	result = test_output("11001100\n1100 1100 (b8)\n314\n314 (o3)\n204\n204 (d3)\ncc\ncc (h2)\n");
	test_names.push_back("Test io04");
	test_results.push_back(result);

	// constructor #2
	BitGroup io05 = BitGroup("b11001100", 13);
	std::cout << io05.text() << std::endl;
	std::cout << io05.text_ext() << std::endl;
	std::cout << io05.otext() << std::endl;
	std::cout << io05.otext_ext() << std::endl;
	std::cout << io05.dtext() << std::endl;
	std::cout << io05.dtext_ext() << std::endl;
	std::cout << io05.htext() << std::endl;
	std::cout << io05.htext_ext() << std::endl;
	result = test_output("0000011001100\n0 0000 1100 1100 (b13)\n00314\n0 0314 (o5)\n204\n204 (d3)\n00cc\n00 cc (h4)\n");
	test_names.push_back("Test io05");
	test_results.push_back(result);

	// constructor #3
	BitGroup io06 = BitGroup("b1011", "k");
	std::cout << io06.text() << std::endl;
	std::cout << io06.text_ext() << std::endl;
	std::cout << io06.htext() << std::endl;
	std::cout << io06.htext_ext() << std::endl;
	result = test_output("1011\n1011 (b4)\nb\nb (h1)\n");
	test_names.push_back("Test io06");
	test_results.push_back(result);

	BitGroup io07 = BitGroup("b1011", "vx");
	std::cout << io07.text() << std::endl;
	std::cout << io07.text_ext() << std::endl;
	std::cout << io07.htext() << std::endl;
	std::cout << io07.htext_ext() << std::endl;
	result = test_output("1011\n1011 (b4)\nb\nb (h1)\n");
	test_names.push_back("Test io07");
	test_results.push_back(result);

	// constructor #4
	BitGroup io08 = BitGroup("b1011", 6, "l");
	std::cout << io08.text() << std::endl;
	std::cout << io08.text_ext() << std::endl;
	std::cout << io08.htext() << std::endl;
	std::cout << io08.htext_ext() << std::endl;
	result = test_output("001011\n00 1011 (b6)\n0b\n0b (h2)\n");
	test_names.push_back("Test io08");
	test_results.push_back(result);

	BitGroup io09 = BitGroup("b1011", 7, "ay");
	std::cout << io09.text() << std::endl;
	std::cout << io09.text_ext() << std::endl;
	std::cout << io09.htext() << std::endl;
	std::cout << io09.htext_ext() << std::endl;
	result = test_output("0001011\n000 1011 (b7)\n0b\n0b (h2)\n");
	test_names.push_back("Test io09");
	test_results.push_back(result);

	// illegal first character
	BitGroup io10 = BitGroup("j1010");
	std::cout << io10.text() << std::endl;
	result = test_output("j is not a legal first character\n\n");
	test_names.push_back("Test io10");
	test_results.push_back(result);

	// binary input tests
	BitGroup io11 = BitGroup("b");
	std::cout << io11.text() << std::endl;
	std::cout << io11.text_ext() << std::endl;
	std::cout << io11.otext() << std::endl;
	std::cout << io11.otext_ext() << std::endl;
	std::cout << io11.dtext() << std::endl;
	std::cout << io11.dtext_ext() << std::endl;
	std::cout << io11.htext() << std::endl;
	std::cout << io11.htext_ext() << std::endl;
	std::cout << io11.ctext() << std::endl;
	std::cout << io11.ctext_ext() << std::endl;
	result = test_output("0\n0 (b1)\n0\n0 (o1)\n0\n0 (d1)\n0\n0 (h1)\nMalformed alphanumeric string\n\nMalformed alphanumeric string\n (c0)\n");
	test_names.push_back("Test io11");
	test_results.push_back(result);

	// check for binary zero value
	BitGroup io12 = BitGroup("b0");
	std::cout << io12.text() << std::endl;
	std::cout << io12.text_ext() << std::endl;
	std::cout << io12.otext() << std::endl;
	std::cout << io12.otext_ext() << std::endl;
	std::cout << io12.dtext() << std::endl;
	std::cout << io12.dtext_ext() << std::endl;
	std::cout << io12.htext() << std::endl;
	std::cout << io12.htext_ext() << std::endl;
	std::cout << io12.ctext() << std::endl;
	std::cout << io12.ctext_ext() << std::endl;
	result = test_output("0\n0 (b1)\n0\n0 (o1)\n0\n0 (d1)\n0\n0 (h1)\nMalformed alphanumeric string\n\nMalformed alphanumeric string\n (c0)\n");
	test_names.push_back("Test io12");
	test_results.push_back(result);

	// check for binary one value
	BitGroup io13 = BitGroup("b1");
	std::cout << io13.text() << std::endl;
	std::cout << io13.text_ext() << std::endl;
	std::cout << io13.otext() << std::endl;
	std::cout << io13.otext_ext() << std::endl;
	std::cout << io13.dtext() << std::endl;
	std::cout << io13.dtext_ext() << std::endl;
	std::cout << io13.htext() << std::endl;
	std::cout << io13.htext_ext() << std::endl;
	std::cout << io13.ctext() << std::endl;
	std::cout << io13.ctext_ext() << std::endl;
	result = test_output("1\n1 (b1)\n1\n1 (o1)\n1\n1 (d1)\n1\n1 (h1)\nMalformed alphanumeric string\n\nMalformed alphanumeric string\n (c0)\n");
	test_names.push_back("Test io13");
	test_results.push_back(result);

	// check for illegal binary string
	BitGroup io14 = BitGroup("b10301");
	std::cout << io14.text() << std::endl;
	result = test_output("10301 is not a legal binary string\n\n");
	test_names.push_back("Test io14");
	test_results.push_back(result);

	// check for legal binary value
	BitGroup io15 = BitGroup("b1010");
	std::cout << io15.text() << std::endl;
	std::cout << io15.text_ext() << std::endl;
	std::cout << io15.otext() << std::endl;
	std::cout << io15.otext_ext() << std::endl;
	std::cout << io15.dtext() << std::endl;
	std::cout << io15.dtext_ext() << std::endl;
	std::cout << io15.htext() << std::endl;
	std::cout << io15.htext_ext() << std::endl;
	std::cout << io15.ctext() << std::endl;
	std::cout << io15.ctext_ext() << std::endl;
	result = test_output("1010\n1010 (b4)\n12\n12 (o2)\n10\n10 (d2)\na\na (h1)\nMalformed alphanumeric string\n\nMalformed alphanumeric string\n (c0)\n");
	test_names.push_back("Test io15");
	test_results.push_back(result);

	// check for legal binary value
	BitGroup io16 = BitGroup("b10101111000011000100100101010101010101010000101011010100101011100010101010");
	std::cout << io16.text() << std::endl;
	std::cout << io16.text_ext() << std::endl;
	std::cout << io16.otext() << std::endl;
	std::cout << io16.otext_ext() << std::endl;
	std::cout << io16.dtext() << std::endl;
	std::cout << io16.dtext_ext() << std::endl;
	std::cout << io16.htext() << std::endl;
	std::cout << io16.htext_ext() << std::endl;
	std::cout << io16.ctext() << std::endl;
	std::cout << io16.ctext_ext() << std::endl;
	result = test_output(
		"10101111000011000100100101010101010101010000101011010100101011100010101010\n10 1011 1100 0011 0001 0010 0101 0101 0101 0101 0100 0010 1011 0101 0010 1011 1000 1010 1010 (b74)\n"
		"2570304452525205324534252\n2 5703 0445 2525 2053 2453 4252 (o25)\n"
		"12916262182098675349674\n12,916,262,182,098,675,349,674 (d23)\n"
		"2bc312555542b52b8aa\n2 bc 31 25 55 54 2b 52 b8 aa (h19)\n"
		"Malformed alphanumeric string\n\nMalformed alphanumeric string\n (c0)\n"
		);
	test_names.push_back("Test io16");
	test_results.push_back(result);

	// check for leading zero truncation
	BitGroup io17 = BitGroup("b000011110000");
	std::cout << io17.text() << std::endl;
	std::cout << io17.text_ext() << std::endl;
	std::cout << io17.otext() << std::endl;
	std::cout << io17.otext_ext() << std::endl;
	std::cout << io17.dtext() << std::endl;
	std::cout << io17.dtext_ext() << std::endl;
	std::cout << io17.htext() << std::endl;
	std::cout << io17.htext_ext() << std::endl;
	result = test_output("11110000\n1111 0000 (b8)\n360\n360 (o3)\n240\n240 (d3)\nf0\nf0 (h2)\n");
	test_names.push_back("Test io17");
	test_results.push_back(result);

	// check for number_of_bits handling
	// too few bits...error
	BitGroup io18 = BitGroup("b000011110000", 4);
	std::cout << io18.text() << std::endl;
	result = test_output("b000011110000 too big for 4 bits\n\n");
	test_names.push_back("Test io18");
	test_results.push_back(result);

	// exact number of bits
	BitGroup io19 = BitGroup("b000011110000", 8);
	std::cout << io19.text() << std::endl;
	std::cout << io19.text_ext() << std::endl;
	std::cout << io19.otext() << std::endl;
	std::cout << io19.otext_ext() << std::endl;
	std::cout << io19.dtext() << std::endl;
	std::cout << io19.dtext_ext() << std::endl;
	std::cout << io19.htext() << std::endl;
	std::cout << io19.htext_ext() << std::endl;
	result = test_output("11110000\n1111 0000 (b8)\n360\n360 (o3)\n240\n240 (d3)\nf0\nf0 (h2)\n");
	test_names.push_back("Test io19");
	test_results.push_back(result);

	// adds leading zeros
	BitGroup io20 = BitGroup("b000011110000", 32);
	std::cout << io20.text() << std::endl;
	std::cout << io20.text_ext() << std::endl;
	std::cout << io20.otext() << std::endl;
	std::cout << io20.otext_ext() << std::endl;
	std::cout << io20.dtext() << std::endl;
	std::cout << io20.dtext_ext() << std::endl;
	std::cout << io20.htext() << std::endl;
	std::cout << io20.htext_ext() << std::endl;
	result = test_output(
		"00000000000000000000000011110000\n0000 0000 0000 0000 0000 0000 1111 0000 (b32)\n"
		"00000000360\n000 0000 0360 (o11)\n"
		"240\n240 (d3)\n000000f0\n00 00 00 f0 (h8)\n"
		);
	test_names.push_back("Test io20");
	test_results.push_back(result);


	// octal testing
	// check for octal default value
	BitGroup io21 = BitGroup("o");
	std::cout << io21.text() << std::endl;
	std::cout << io21.text_ext() << std::endl;
	std::cout << io21.otext() << std::endl;
	std::cout << io21.otext_ext() << std::endl;
	std::cout << io21.dtext() << std::endl;
	std::cout << io21.dtext_ext() << std::endl;
	std::cout << io21.htext() << std::endl;
	std::cout << io21.htext_ext() << std::endl;
	result = test_output("0\n0 (b1)\n0\n0 (o1)\n0\n0 (d1)\n0\n0 (h1)\n");
	test_names.push_back("Test io21");
	test_results.push_back(result);

	// check for illegal octal string
	BitGroup io22 = BitGroup("o18301");
	std::cout << io22.otext() << std::endl;
	result = test_output("18301 is not a legal octal string\n\n");
	test_names.push_back("Test io22");
	test_results.push_back(result);

	// check for legal octal value
	BitGroup io23 = BitGroup("o2735651");
	std::cout << io23.text() << std::endl;
	std::cout << io23.text_ext() << std::endl;
	std::cout << io23.otext() << std::endl;
	std::cout << io23.otext_ext() << std::endl;
	std::cout << io23.dtext() << std::endl;
	std::cout << io23.dtext_ext() << std::endl;
	std::cout << io23.htext() << std::endl;
	std::cout << io23.htext_ext() << std::endl;
	result = test_output("10111011101110101001\n1011 1011 1011 1010 1001 (b20)\n"
						 "2735651\n273 5651 (o7)\n"
						 "768937\n768,937 (d6)\n"
						 "bbba9\nb bb a9 (h5)\n");
	test_names.push_back("Test io23");
	test_results.push_back(result);

	BitGroup io24 = BitGroup("o1772663554562771000350163");
	std::cout << io24.text() << std::endl;
	std::cout << io24.text_ext() << std::endl;
	std::cout << io24.otext() << std::endl;
	std::cout << io24.otext_ext() << std::endl;
	std::cout << io24.dtext() << std::endl;
	std::cout << io24.dtext_ext() << std::endl;
	std::cout << io24.htext() << std::endl;
	std::cout << io24.htext_ext() << std::endl;
	result = test_output("1111111010110110011101101100101110010111111001000000000011101000001110011\n"
						 "1 1111 1101 0110 1100 1110 1101 1001 0111 0010 1111 1100 1000 0000 0001 1101 0000 0111 0011 (b73)\n"
						 "1772663554562771000350163\n1 7726 6355 4562 7710 0035 0163 (o25)\n"
						 "9397241829475213234291\n9,397,241,829,475,213,234,291 (d22)\n"
						 "1fd6ced972fc801d073\n1 fd 6c ed 97 2f c8 01 d0 73 (h19)\n");
	test_names.push_back("Test io24");
	test_results.push_back(result);

	// check for leading zero truncation
	BitGroup io25 = BitGroup("o0000355247");
	std::cout << io25.text() << std::endl;
	std::cout << io25.text_ext() << std::endl;
	std::cout << io25.otext() << std::endl;
	std::cout << io25.otext_ext() << std::endl;
	std::cout << io25.dtext() << std::endl;
	std::cout << io25.dtext_ext() << std::endl;
	std::cout << io25.htext() << std::endl;
	std::cout << io25.htext_ext() << std::endl;
	result = test_output("11101101010100111\n1 1101 1010 1010 0111 (b17)\n"
						 "355247\n35 5247 (o6)\n121511\n121,511 (d6)\n1daa7\n1 da a7 (h5)\n");
	test_names.push_back("Test io25");
	test_results.push_back(result);

	// check for number_of_bits handling
	BitGroup io26 = BitGroup("o123", 64);
	std::cout << io26.text() << std::endl;
	std::cout << io26.text_ext() << std::endl;
	std::cout << io26.otext() << std::endl;
	std::cout << io26.otext_ext() << std::endl;
	std::cout << io26.dtext() << std::endl;
	std::cout << io26.dtext_ext() << std::endl;
	std::cout << io26.htext() << std::endl;
	std::cout << io26.htext_ext() << std::endl;
	result = test_output("0000000000000000000000000000000000000000000000000000000001010011\n"
						 "0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0101 0011 (b64)\n"
						 "0000000000000000000123\n00 0000 0000 0000 0000 0123 (o22)\n"
						 "83\n83 (d2)\n0000000000000053\n00 00 00 00 00 00 00 53 (h16)\n");
	test_names.push_back("Test io26");
	test_results.push_back(result);


	// decimal testing
	// check for decimal default value
	BitGroup io27 = BitGroup("d");
	std::cout << io27.text() << std::endl;
	std::cout << io27.text_ext() << std::endl;
	std::cout << io27.otext() << std::endl;
	std::cout << io27.otext_ext() << std::endl;
	std::cout << io27.dtext() << std::endl;
	std::cout << io27.dtext_ext() << std::endl;
	std::cout << io27.htext() << std::endl;
	std::cout << io27.htext_ext() << std::endl;
	result = test_output("0\n0 (b1)\n0\n0 (o1)\n0\n0 (d1)\n0\n0 (h1)\n");
	test_names.push_back("Test io27");
	test_results.push_back(result);

	// check for illegal decimal string
	BitGroup io28 = BitGroup("d18g301");
	std::cout << io28.text() << std::endl;
	result = test_output("18g301 is not a legal decimal string\n\n");
	test_names.push_back("Test io28");
	test_results.push_back(result);

	// check for legal decimal value
	BitGroup io29 = BitGroup("d9999");
	std::cout << io29.text() << std::endl;
	std::cout << io29.text_ext() << std::endl;
	std::cout << io29.otext() << std::endl;
	std::cout << io29.otext_ext() << std::endl;
	std::cout << io29.dtext() << std::endl;
	std::cout << io29.dtext_ext() << std::endl;
	std::cout << io29.htext() << std::endl;
	std::cout << io29.htext_ext() << std::endl;
	result = test_output("10011100001111\n10 0111 0000 1111 (b14)\n23417\n2 3417 (o5)\n"
						 "9999\n9,999 (d4)\n270f\n27 0f (h4)\n");
	test_names.push_back("Test io29");
	test_results.push_back(result);

	// check for legal decimal value
	BitGroup io30 = BitGroup("d09090911");
	std::cout << io30.text() << std::endl;
	std::cout << io30.text_ext() << std::endl;
	std::cout << io30.otext() << std::endl;
	std::cout << io30.otext_ext() << std::endl;
	std::cout << io30.dtext() << std::endl;
	std::cout << io30.dtext_ext() << std::endl;
	std::cout << io30.htext() << std::endl;
	std::cout << io30.htext_ext() << std::endl;
	result = test_output("100010101011011101011111\n1000 1010 1011 0111 0101 1111 (b24)\n"
						 "42533537\n4253 3537 (o8)\n9090911\n9,090,911 (d7)\n8ab75f\n8a b7 5f (h6)\n");
	test_names.push_back("Test io30");
	test_results.push_back(result);

	BitGroup io31 = BitGroup("d123456789009");
	std::cout << io31.text() << std::endl;
	std::cout << io31.text_ext() << std::endl;
	std::cout << io31.otext() << std::endl;
	std::cout << io31.otext_ext() << std::endl;
	std::cout << io31.dtext() << std::endl;
	std::cout << io31.dtext_ext() << std::endl;
	std::cout << io31.htext() << std::endl;
	std::cout << io31.htext_ext() << std::endl;
	result = test_output("1110010111110100110010001101000010001\n1 1100 1011 1110 1001 1001 0001 1010 0001 0001 (b37)\n"
						 "1627646215021\n1 6276 4621 5021 (o13)\n123456789009\n123,456,789,009 (d12)\n"
						 "1cbe991a11\n1c be 99 1a 11 (h10)\n");
	test_names.push_back("Test io31");
	test_results.push_back(result);

	BitGroup io32 = BitGroup("d9876543210001234");
	std::cout << io32.text() << std::endl;
	std::cout << io32.text_ext() << std::endl;
	std::cout << io32.otext() << std::endl;
	std::cout << io32.otext_ext() << std::endl;
	std::cout << io32.dtext() << std::endl;
	std::cout << io32.dtext_ext() << std::endl;
	std::cout << io32.htext() << std::endl;
	std::cout << io32.htext_ext() << std::endl;
	result = test_output("100011000101101010100111101001101001000001001101010010\n"
						 "10 0011 0001 0110 1010 1001 1110 1001 1010 0100 0001 0011 0101 0010 (b54)\n"
						 "430552475151011522\n43 0552 4751 5101 1522 (o18)\n"
						 "9876543210001234\n9,876,543,210,001,234 (d16)\n"
						 "2316a9e9a41352\n23 16 a9 e9 a4 13 52 (h14)\n");
	test_names.push_back("Test io32");
	test_results.push_back(result);

	// check for leading zero truncation
	BitGroup io33 = BitGroup("d000035199");
	std::cout << io33.text() << std::endl;
	std::cout << io33.text_ext() << std::endl;
	std::cout << io33.otext() << std::endl;
	std::cout << io33.otext_ext() << std::endl;
	std::cout << io33.dtext() << std::endl;
	std::cout << io33.dtext_ext() << std::endl;
	std::cout << io33.htext() << std::endl;
	std::cout << io33.htext_ext() << std::endl;
	result = test_output("1000100101111111\n1000 1001 0111 1111 (b16)\n"
						 "104577\n10 4577 (o6)\n35199\n35,199 (d5)\n"
						 "897f\n89 7f (h4)\n");
	test_names.push_back("Test io33");
	test_results.push_back(result);

	// check for number_of_bits handling
	BitGroup io34 = BitGroup("d987", 64);
	std::cout << io34.text() << std::endl;
	std::cout << io34.text_ext() << std::endl;
	std::cout << io34.otext() << std::endl;
	std::cout << io34.otext_ext() << std::endl;
	std::cout << io34.dtext() << std::endl;
	std::cout << io34.dtext_ext() << std::endl;
	std::cout << io34.htext() << std::endl;
	std::cout << io34.htext_ext() << std::endl;
	result = test_output("0000000000000000000000000000000000000000000000000000001111011011\n"
						 "0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0011 1101 1011 (b64)\n"
						 "0000000000000000001733\n00 0000 0000 0000 0000 1733 (o22)\n"
						 "987\n987 (d3)\n00000000000003db\n00 00 00 00 00 00 03 db (h16)\n");
	test_names.push_back("Test io34");
	test_results.push_back(result);
	

	// hexadecimal testing
	// check for hexadecimal default value
	BitGroup io35 = BitGroup("h");
	std::cout << io35.text() << std::endl;
	std::cout << io35.text_ext() << std::endl;
	std::cout << io35.otext() << std::endl;
	std::cout << io35.otext_ext() << std::endl;
	std::cout << io35.dtext() << std::endl;
	std::cout << io35.dtext_ext() << std::endl;
	std::cout << io35.htext() << std::endl;
	std::cout << io35.htext_ext() << std::endl;
	result = test_output("0\n0 (b1)\n0\n0 (o1)\n0\n0 (d1)\n0\n0 (h1)\n");
	test_names.push_back("Test io35");
	test_results.push_back(result);

	// check for illegal hexadecimal string
	BitGroup io36 = BitGroup("h18g301");
	std::cout << io36.text() << std::endl;
	result = test_output("18g301 is not a legal hexadecimal string\n\n");
	test_names.push_back("Test io36");
	test_results.push_back(result);

	// check for legal hexadecimal value
	BitGroup io37 = BitGroup("h4F");
	std::cout << io37.text() << std::endl;
	std::cout << io37.text_ext() << std::endl;
	std::cout << io37.otext() << std::endl;
	std::cout << io37.otext_ext() << std::endl;
	std::cout << io37.dtext() << std::endl;
	std::cout << io37.dtext_ext() << std::endl;
	std::cout << io37.htext() << std::endl;
	std::cout << io37.htext_ext() << std::endl;
	result = test_output("1001111\n100 1111 (b7)\n117\n117 (o3)\n79\n79 (d2)\n4f\n4f (h2)\n");
	test_names.push_back("Test io37");
	test_results.push_back(result);

	// check for legal hexadecimal value
	BitGroup io38 = BitGroup("h8FE");
	std::cout << io38.text() << std::endl;
	std::cout << io38.text_ext() << std::endl;
	std::cout << io38.otext() << std::endl;
	std::cout << io38.otext_ext() << std::endl;
	std::cout << io38.dtext() << std::endl;
	std::cout << io38.dtext_ext() << std::endl;
	std::cout << io38.htext() << std::endl;
	std::cout << io38.htext_ext() << std::endl;
	result = test_output("100011111110\n1000 1111 1110 (b12)\n4376\n4376 (o4)\n2302\n2,302 (d4)\n8fe\n8 fe (h3)\n");
	test_names.push_back("Test io38");
	test_results.push_back(result);

	BitGroup io39 = BitGroup("h27a56d51f");
	std::cout << io39.text() << std::endl;
	std::cout << io39.text_ext() << std::endl;
	std::cout << io39.otext() << std::endl;
	std::cout << io39.otext_ext() << std::endl;
	std::cout << io39.dtext() << std::endl;
	std::cout << io39.dtext_ext() << std::endl;
	std::cout << io39.htext() << std::endl;
	std::cout << io39.htext_ext() << std::endl;
	result = test_output("1001111010010101101101010100011111\n10 0111 1010 0101 0110 1101 0101 0001 1111 (b34)\n"
						 "117225552437\n1172 2555 2437 (o12)\n10642445599\n10,642,445,599 (d11)\n27a56d51f\n2 7a 56 d5 1f (h9)\n");
	test_names.push_back("Test io39");
	test_results.push_back(result);

	BitGroup io40 = BitGroup("h17b872663554ff56c27781a00035d01a6e3");
	std::cout << io40.text() << std::endl;
	std::cout << io40.text_ext() << std::endl;
	std::cout << io40.otext() << std::endl;
	std::cout << io40.otext_ext() << std::endl;
	std::cout << io40.dtext() << std::endl;
	std::cout << io40.dtext_ext() << std::endl;
	std::cout << io40.htext() << std::endl;
	std::cout << io40.htext_ext() << std::endl;
	result = test_output("10111101110000111001001100110001101010101010011111111010101101100001001110111100000011010000000000000001101011101000000011010011011100011\n"
						 "1 0111 1011 1000 0111 0010 0110 0110 0011 0101 0101 0100 1111 1111 0101 0110 1100 0010 0111 0111 1000 0001 1010 0000 0000 0000 0011 0101 1101 0000 0001 1010 0110 1110 0011 (b137)\n"
						 "2756071146152523772554116740320000153500323343\n27 5607 1146 1525 2377 2554 1167 4032 0000 1535 0032 3343 (o46)\n"
						 "129146662164464956207484064237889429546723\n129,146,662,164,464,956,207,484,064,237,889,429,546,723 (d42)\n"
						 "17b872663554ff56c27781a00035d01a6e3\n1 7b 87 26 63 55 4f f5 6c 27 78 1a 00 03 5d 01 a6 e3 (h35)\n");
	test_names.push_back("Test io40");
	test_results.push_back(result);

	// check for leading zero truncation
	BitGroup io41 = BitGroup("h000035fe5247");
	std::cout << io41.text() << std::endl;
	std::cout << io41.text_ext() << std::endl;
	std::cout << io41.otext() << std::endl;
	std::cout << io41.otext_ext() << std::endl;
	std::cout << io41.dtext() << std::endl;
	std::cout << io41.dtext_ext() << std::endl;
	std::cout << io41.htext() << std::endl;
	std::cout << io41.htext_ext() << std::endl;
	result = test_output("110101111111100101001001000111\n11 0101 1111 1110 0101 0010 0100 0111 (b30)\n"
						 "6577451107\n65 7745 1107 (o10)\n905859655\n905,859,655 (d9)\n35fe5247\n35 fe 52 47 (h8)\n");
	test_names.push_back("Test io41");
	test_results.push_back(result);

	// check for number_of_bits handling
	BitGroup io42 = BitGroup("h12f", 64);
	std::cout << io42.text() << std::endl;
	std::cout << io42.text_ext() << std::endl;
	std::cout << io42.otext() << std::endl;
	std::cout << io42.otext_ext() << std::endl;
	std::cout << io42.dtext() << std::endl;
	std::cout << io42.dtext_ext() << std::endl;
	std::cout << io42.htext() << std::endl;
	std::cout << io42.htext_ext() << std::endl;
	result = test_output("0000000000000000000000000000000000000000000000000000000100101111\n"
						 "0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0001 0010 1111 (b64)\n"
						 "0000000000000000000457\n00 0000 0000 0000 0000 0457 (o22)\n"
						 "303\n303 (d3)\n000000000000012f\n00 00 00 00 00 00 01 2f (h16)\n");
	test_names.push_back("Test io42");
	test_results.push_back(result);


	// alphanumeric testing
	// check for alphanumeric default value
	// not a good test, since 0 is not alphanumeric
	BitGroup io43 = BitGroup("c");
	std::cout << io43.text() << std::endl;
	std::cout << io43.ctext() << std::endl;
	result = test_output("0\nMalformed alphanumeric string\n\n");
	test_names.push_back("Test io43");
	test_results.push_back(result);

	// no check for illegal alphanumeric string since it's hard to type in an illegal character

	// check for alphanumeric value
	BitGroup io44 = BitGroup("cZ Test");
	std::cout << io44.text() << std::endl;
	std::cout << io44.text_ext() << std::endl;
	std::cout << io44.otext() << std::endl;
	std::cout << io44.otext_ext() << std::endl;
	std::cout << io44.dtext() << std::endl;
	std::cout << io44.dtext_ext() << std::endl;
	std::cout << io44.htext() << std::endl;
	std::cout << io44.htext_ext() << std::endl;
	std::cout << io44.ctext() << std::endl;
	std::cout << io44.ctext_ext() << std::endl;
	result = test_output("010110100010000001010100011001010111001101110100\n0101 1010 0010 0000 0101 0100 0110 0101 0111 0011 0111 0100 (b48)\n"
						 "2642012431271564\n2642 0124 3127 1564 (o16)\n99094901388148\n99,094,901,388,148 (d14)\n"
						 "5a2054657374\n5a 20 54 65 73 74 (h12)\nZ Test\nZ Test (c6)\n");
	test_names.push_back("Test io44");
	test_results.push_back(result);

	// check for alphanumeric value
	BitGroup io45 = BitGroup("C !\"#$%& }~");
	std::cout << io45.text() << std::endl;
	std::cout << io45.text_ext() << std::endl;
	std::cout << io45.otext() << std::endl;
	std::cout << io45.otext_ext() << std::endl;
	std::cout << io45.dtext() << std::endl;
	std::cout << io45.dtext_ext() << std::endl;
	std::cout << io45.htext() << std::endl;
	std::cout << io45.htext_ext() << std::endl;
	std::cout << io45.ctext() << std::endl;
	std::cout << io45.ctext_ext() << std::endl;
	result = test_output("00100000001000010010001000100011001001000010010100100110001000000111110101111110\n"
						 "0010 0000 0010 0001 0010 0010 0010 0011 0010 0100 0010 0101 0010 0110 0010 0000 0111 1101 0111 1110 (b80)\n"
						 "040102210431102244610076576\n040 1022 1043 1102 2446 1007 6576 (o27)\n"
						 "151726929855824508517758\n151,726,929,855,824,508,517,758 (d24)\n"
						 "20212223242526207d7e\n20 21 22 23 24 25 26 20 7d 7e (h20)\n !\"#$%& }~\n !\"#$%& }~ (c10)\n");
	test_names.push_back("Test io45");
	test_results.push_back(result);

	// no check for leading zero truncation
	// no check for number_of_bits handling

	// check text_ext() routines
	BitGroup io46 = BitGroup("b010000010010000001010100011001010111001101110100");
	std::cout << io46.text() << std::endl;
	std::cout << io46.text_ext() << std::endl;
	std::cout << io46.text_ext(8,"-") << std::endl;
	result = test_output("10000010010000001010100011001010111001101110100\n100 0001 0010 0000 0101 0100 0110 0101 0111 0011 0111 0100 (b47)\n1000001-00100000-01010100-01100101-01110011-01110100 (b47)\n");
	test_names.push_back("Test io46");
	test_results.push_back(result);

	// check otext_ext() with io46
	std::cout << io46.otext() << std::endl;
	std::cout << io46.otext_ext() << std::endl;
	std::cout << io46.otext_ext(6,",") << std::endl;
	result = test_output("2022012431271564\n2022 0124 3127 1564 (o16)\n2022,012431,271564 (o16)\n");
	test_names.push_back("Test io47");
	test_results.push_back(result);

	// check dtext_ext() with io46
	std::cout << io46.dtext() << std::endl;
	std::cout << io46.dtext_ext() << std::endl;
	std::cout << io46.dtext_ext(5,",") << std::endl;
	result = test_output("71607110693748\n71,607,110,693,748 (d14)\n7160,71106,93748 (d14)\n");
	test_names.push_back("Test io48");
	test_results.push_back(result);	

	// check htext_ext() with io46
	std::cout << io46.htext() << std::endl;
	std::cout << io46.htext_ext() << std::endl;
	std::cout << io46.htext_ext(4,"|") << std::endl;
	result = test_output("412054657374\n41 20 54 65 73 74 (h12)\n4120|5465|7374 (h12)\n");
	test_names.push_back("Test io49");
	test_results.push_back(result);

	// check ctext_ext() with io46
	std::cout << io46.ctext() << std::endl;
	std::cout << io46.ctext_ext() << std::endl;
	std::cout << io46.ctext_ext(3,";") << std::endl;
	result = test_output("A Test\nA Test (c6)\nA T;est (c6)\n");
	test_names.push_back("Test io50");
	test_results.push_back(result);

	// chck text_condensed() with io45
	std::cout << io45.text_condensed() << std::endl;
	result = test_output("0010 0000 0010 0001 0010 0010 0010 0011 ..........0101 0010 0110 0010 0000 0111 1101 0111 1110 (b80)\n");
	test_names.push_back("Test io51");
	test_results.push_back(result);



	// End of tests
	tester_off();

	for (size_t i = 0; i < test_names.size(); ++i) {
		if (!test_results[i]) { std::cout << print_results(test_names[i], test_results[i]) << std::endl; }
		// Prints results for every test
		//std::cout << print_results(test_names[i], test_results[i]) << std::endl;
	}

	std::cout << "Finished IO Testing" << std::endl << std::endl;

}