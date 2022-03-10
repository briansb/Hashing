﻿/* bitset practice */
//  https://www.geeksforgeeks.org/c-bitset-and-its-application/

//  https://www.cplusplus.com/reference/bitset/bitset/
//  https://www.educba.com/c-plus-plus-bitset/
//  https://docs.microsoft.com/en-us/cpp/standard-library/bitset-class?view=msvc-170

#include "input_output.hh"

int main() {

    //  Need to do a struct, so we can reference like
    //     block[2].word[3], or something like it
    
    word blocks[100][WORDS_PER_BLOCK];      // This holds the message
                                            // Each block holds 16 32-bit words, or 64 characters
    // Initialize blocks[][]
    int number_of_blocks = 0;
    std::string message = "Brian";
    message_to_blocks(message, blocks, number_of_blocks);
    
    std::cout << blocks[0][0] << std::endl;
    std::cout << blocks[0][1] << std::endl;


    std::cout << std::endl << "-----------------------------------------------------------------------" << std::endl;
    std::bitset<8> letters[5];
    letters[0] = 66;
    letters[1] = 114;
    letters[2] = 105;
    letters[3] = 97;
    letters[4] = 110;
    
    std::cout << letters[0] << " " << 
                 letters[1] << " " <<
                 letters[2] << " " <<
                 letters[3] << " " <<
                 letters[4] << std::endl;

    std::cout << letters[0].to_ulong() << " " << 
                 letters[1].to_ulong() << " " <<
                 letters[2].to_ulong() << " " <<
                 letters[3].to_ulong() << " " <<
                 letters[4].to_ulong() << std::endl;

    std::cout << char(letters[0].to_ulong()) << " " << 
                 char(letters[1].to_ulong()) << " " <<
                 char(letters[2].to_ulong()) << " " <<
                 char(letters[3].to_ulong()) << " " <<
                 char(letters[4].to_ulong()) << std::endl;

    // now combine into one 32-bit word
    std::bitset<32> lotsofletters;

    lotsofletters = letters[0].to_ulong();

    lotsofletters = lotsofletters << 8;
    lotsofletters = lotsofletters.to_ulong() + letters[1].to_ulong();
    
    lotsofletters = lotsofletters << 8;
    lotsofletters = lotsofletters.to_ulong() + letters[2].to_ulong();

    lotsofletters = lotsofletters << 8;
    lotsofletters = lotsofletters.to_ulong() + letters[3].to_ulong();

    lotsofletters = lotsofletters << 8;
    lotsofletters = lotsofletters.to_ulong() + letters[4].to_ulong();

    std::cout << lotsofletters << std::endl;
    std::cout << lotsofletters.to_ullong() << std::endl;

    return 0;
}
