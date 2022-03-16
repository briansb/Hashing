
//  https://www.geeksforgeeks.org/c-bitset-and-its-application/
//  https://www.cplusplus.com/reference/bitset/bitset/
//  https://www.educba.com/c-plus-plus-bitset/
//  https://docs.microsoft.com/en-us/cpp/standard-library/bitset-class?view=msvc-170


#include <iostream>
#include <string>
#include <bitset>

#include "Input.h"
#include "Output.h"

/*  IMPORTANT:  Start building the reverse hash as soon as possible  */

int main()
{
    int number_of_blocks = 0;
    std::bitset<BITS_PER_WORD> message[MAX_BLOCKS][WORDS_PER_BLOCK];

    // Get message from source code and load blocks
    //std::string input_message = "They are deterministic";
    //std::string input_message = "They";
    std::string input_message = "They are deterministic.  They are non-deterministic.  They are ee";
    LoadMessageFromString(input_message, message, number_of_blocks);



    // need print function
    for (int i = 0; i < number_of_blocks; i++) {
        std::cout << "Block " << i+1 << ":" << std::endl;
        for (int j = 0; j < WORDS_PER_BLOCK; j++) {
            std::cout << "Word " << std::setfill ('0') << std::setw(2) << j << " - ";
            std::cout << OutputWord_Binary(message, i, j) << " -> ";
            std::cout << OutputWord_Hex(message, i, j) << std::endl;
        }
        std::cout << std::endl;
    }
    
    return 0;
}
