#include "pch.h"
#include "exec_tests.h"
#include "io_tests.h"
#include "op_tests.h"
#include "symbol_tests.h"
#include <iostream>
#include <string>
#include <sstream>

std::ostringstream strCout;
std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();

void run_tests() {
	std::cout << "Begin Main Test loop" << std::endl << std::endl;
	// symbol tester must be run first, due to automatic symbol assignment
	symbol_tester();
	io_tester();
	op_tester();
	std::cout << "Finished Main Test loop" << std::endl << std::endl;
}

// Excellent article, and basis for following...
// https://stackoverflow.com/questions/4810516/c-redirecting-stdout  - first answer

void tester_on() {
	// Redirect cout
	std::cout.rdbuf(strCout.rdbuf());
}

void tester_off() {
	// Restore old cout.
	std::cout.rdbuf(oldCoutStreamBuf);
}

bool test_output(std::string message) {
	// Test captured console output against expected message
	std::string buffer = strCout.str();
	// must clear strCout each time
	strCout.str("");
	strCout.clear();
	if (buffer == message) { return true; }
	else { return false; }
}

std::string print_results(std::string ID, bool result) {
	std::string output = ID + ":  ";
	if (result) {
		output += "SUCCESS";
	}
	else {
		output += "FAILED";
	}
	return output;
}