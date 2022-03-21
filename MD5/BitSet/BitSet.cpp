
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
    std::bitset<BITS_PER_WORD> F;

    // Get message from source code and load blocks
    //std::string input_message = "They";
    std::string input_message = "They are deterministic";
    //std::string input_message = "They are deterministic.  They are non-deterministic.  Abcdefghijkl";
    LoadMessageFromString(input_message, message, number_of_blocks);

    // Load shift amounts
    int *s;
    s = LoadShiftAmounts();

    // Load constants
    unsigned long *K;
    K = LoadConstants();

    //  Initial values of variables
    a0 = 0x67452301;
    b0 = 0xefcdab89;
    c0 = 0x98badcfe;
    d0 = 0x10325476;

    std::cout << IntToHex(d0.to_ulong()) << std::endl;
    
    int g;
    for (int block = 0; block < number_of_blocks; block++) {
        PrintBlock(block, message);
        
        A = a0;
        B = b0;
        C = c0;
        D = d0;

        for (int i = 0; i < 64; i++) {
            if (i >= 0 and i <= 15) {
                F = (B & C) | ((~B) & D);
                g = i;
            } else if (i >= 16 and i <= 31) {
                F = (D & B) | ((~D) & C);
                g = (5*i + 1) % 16;
            } else if (i >= 32 and i <= 47) {
                F = B ^ C ^ D;
                g = (3*i + 5) % 16;
            } else if (i >= 48 and i <= 63) {
                F = C ^ (B | (~D));
                g = (7*i) % 16;
            }

            F = F.to_ulong() + A.to_ulong() + message[block][g].to_ulong() + K[i];
            A = D;
            D = C;
            C = B;
            B = B.to_ulong() + LeftRotate(F, s[i]).to_ulong();

            //std::cout << B.to_string() << std::endl;
            //std::cout << "Loop index = " << i << ", B = " << IntToHex(B.to_ulong()) << std::endl;
            //std::cin.get();

        }  // end 64 iteration loop
        a0 = a0.to_ulong() + A.to_ulong();
        b0 = b0.to_ulong() + B.to_ulong();
        c0 = c0.to_ulong() + C.to_ulong();
        d0 = d0.to_ulong() + D.to_ulong();

    } // end loop over blocks
    std::cout << "a0 = " << IntToHex(a0.to_ulong()) << std::endl;
    std::cout << "b0 = " << IntToHex(b0.to_ulong()) << std::endl;
    std::cout << "c0 = " << IntToHex(c0.to_ulong()) << std::endl;
    std::cout << "d0 = " << IntToHex(d0.to_ulong()) << std::endl;

    return 0;
}
