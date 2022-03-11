#include "pch.h"
#include "BitUnit.h"
#include "SHA1-algorithm.h"
#include "BitGroup.h"
#include "exec_tests.h"
#include "run_data.h"
#include "demo.h"
#include <iostream>
#include <string>

std::string message_string;
std::string hash;

bool process_symbols = true;

int main()
{ 
	// if tests are to be run, they must be run first
	//run_tests();
	//std::cout << std::endl << "================================================================================================" << std::endl << std::endl;
	//run_demo();
	//std::cout << std::endl << "================================================================================================" << std::endl << std::endl;

	/*
	Defined messages
	 run 1 = "A Test"
	 run 2 = "This message is precisely sixty-four bytes long. Yep...64 bytes." // two blocks
	 run 3 = "The quick brown fox jumped over the lazy dog.  Now is the time for all good men to come to the aid of their country.  Jackdaws love my big sphinx of quartz." // three blocks
	 test every step & turn off symbol manipulation
	 */
	 //bool run_data_tests = true;
	 //process_symbols = false;
	 //int run_number = 2;
	 //message_string = run_input(run_number);

	/*
	user-defined message
	*/
	 bool run_data_tests = false;
	 int run_number = 0;
	 process_symbols = false;
	 message_string = "This message is precisely sixty-three bytes long. Yep,63 bytes.";

	// this does not change
	 std::cout << "Original message = " << message_string << std::endl;
	 hash = SHA1(message_string, run_number, run_data_tests);
	 std::cout << "Digest = " << hash << std::endl;

	return 0;
}