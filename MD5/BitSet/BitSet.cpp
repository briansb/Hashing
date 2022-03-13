
//  https://www.geeksforgeeks.org/c-bitset-and-its-application/
//  https://www.cplusplus.com/reference/bitset/bitset/
//  https://www.educba.com/c-plus-plus-bitset/
//  https://docs.microsoft.com/en-us/cpp/standard-library/bitset-class?view=msvc-170


#include <iostream>
#include <string>
#include <bitset>

#include "Input.h"
#include "Output.h"


int main()
{
    
    //std::string input_message = "They are deterministic";
    std::string input_message = "They";
    int number_of_blocks = 0;
    std::bitset<BITS_PER_CHARACTER * CHARACTERS_PER_WORD> message[MAX_BLOCKS][WORDS_PER_BLOCK];


    LoadMessageFromString(input_message, message, number_of_blocks);

    // need print function
    OutputWordHex(message[0][0]);



    return 0;
}
