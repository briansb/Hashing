#pragma once
#include <string>

struct BitUnit {
private:
	int bit;
	std::string symbol;
	bool spare;

public:
	BitUnit();
	BitUnit(int bit, std::string symbol, bool spare);


	int get_bit();
	void set_bit(int n);
	
	std::string get_symbol();
	void set_symbol(std::string s);

	bool get_spare();
	void set_spare(bool b);
	
};