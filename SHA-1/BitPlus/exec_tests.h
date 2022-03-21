#pragma once
#include <string>

void run_tests();

void tester_on();
void tester_off();
bool test_output(std::string message);
std::string print_results(std::string ID, bool result);