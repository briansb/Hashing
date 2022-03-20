
//  https://www.geeksforgeeks.org/c-bitset-and-its-application/
//  https://www.cplusplus.com/reference/bitset/bitset/
//  https://www.educba.com/c-plus-plus-bitset/
//  https://docs.microsoft.com/en-us/cpp/standard-library/bitset-class?view=msvc-170


#include <iostream>
#include <string>
#include <bitset>

#include "Input.h"
#include "Output.h"
#include "Utilities.h"

/*  IMPORTANT:  Start building the reverse hash as soon as possible  */

int main()
{
    int number_of_blocks = 0;
    std::bitset<BITS_PER_WORD> message[MAX_BLOCKS][WORDS_PER_BLOCK];
    std::bitset<BITS_PER_WORD> a0, b0, c0, d0;
    std::bitset<BITS_PER_WORD> A, B, C, D;
    std::bitset<BITS_PER_WORD> F, g;

    // Get message from source code and load blocks
    //std::string input_message = "They";
    std::string input_message = "They are deterministic";
    //std::string input_message = "They are deterministic.  They are non-deterministic.  Abcdefghijkl";
    LoadMessageFromString(input_message, message, number_of_blocks);

    // Load shift amounts
    int *s;
    s = LoadShiftAmounts();
    //std::cout << "Third shift value = " << s[2] << std::endl;
    // Load constants
    unsigned long *K;
    K = LoadConstants();
    //std::cout << "Seventh constant = " << K[6] << std::endl;
    //  Initial values of variables
    a0 = 0x01234567;
    b0 = 0x89abcdef;
    c0 = 0xfedcba98;
    d0 = 0x76543210;
    
    for (int block = 0; block < number_of_blocks; block++) {
        PrintBlock(block, message);
        
        A = a0;
        B = b0;
        C = c0;
        D = d0;

        for (int i = 0; i < 64; i++) {
            
            if (i >= 0 and i <= 15) {

                F = (B & C) | ((~B) & D);
                std::cout << B.to_string() << " " << C.to_string() << " " << D.to_string() << std::endl;
                std::cout << IntToHex(B.to_ulong()) << " " << IntToHex(C.to_ulong()) << " " << IntToHex(D.to_ulong()) << std::endl;

            }

            std::cout << F.to_string() << std::endl;
            std::cout << IntToHex(F.to_ulong()) << std::endl;
            std::cin.get();



        }  // end 64 iteration loop




    } // end loop over blocks

 

    
    
    return 0;
}
