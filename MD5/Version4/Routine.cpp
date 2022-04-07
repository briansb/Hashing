#include "Routine.h"


/************  Assumptions  ************/
/*     characters are 8-bit            */
/*     words are 4, 8-bit characters   */
/*     words are 32-bits               */
/*     one block of 8 words            */
/*     Little Endian                   */
/***************************************/


void GetMD5Hash(std::vector<uint32_t> words, uint8_t digest[]) {

    // Initialize variables:
    uint32_t a0 = 0x67452301;
    uint32_t b0 = 0xefcdab89;
    //uint32_t c0 = 0x98badcfe;
    //uint32_t d0 = 0x10325476;

    //  Initialize constants
    uint32_t K[64] =  { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee ,
                        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501 ,
                        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be ,
                        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821 ,
                        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa ,
                        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8 ,
                        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed ,
                        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a ,
                        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c ,
                        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70 ,
                        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05 ,
                        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665 ,
                        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039 ,
                        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1 ,
                        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1 ,
                        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391 };

    int s[64] =   { 7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
                    5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
                    4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
                    6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21 };



    
    uint32_t M[8];
    //  assume one block - 8 words big - 256 bits
    //  build array M[] 8 words
    for (int i = 0; i < 8; i++) { M[i] = words[i]; }

    uint32_t A = a0;
    uint32_t B = b0;
    //uint32_t C = c0;
    //uint32_t D = d0;

    // std::cout << "Start of loop - w[i]" << std::endl;
    // for (int i = 0; i < 8; i++) { std::cout << OutputHex(M[i]) << " "; }
    // std::cout << std::endl;
    // std::cout << "Start of loop - a0, b0, c0, d0" << std::endl;
    // std::cout << OutputHex(a0) << " " << OutputHex(b0) << " " << OutputHex(c0) << " " << OutputHex(d0) << " " << std::endl << std::endl;

    int main_loop = 64;  // should be 64
    for (int i = 0; i < main_loop; i++) {
        uint32_t F, g;
        if ((i >= 0) and (i <= 15)) {
            //F = (B & C) | ((~B) & D);
            //F = (B & C) | (~B);
            F = (B) | (~B);
            g = i;
        }
        // else if ((i >= 16) and (i <= 31)) {
        //     F = (D & B) | ((~D) & C);
        //     g = (5 * i + 1) % 16;
        // }
        // else if ((i >= 32) and (i <= 47)) {
        //     F = B ^ C ^ D;
        //     g = (3 * i + 5) % 16;
        // }
        // else if ((i >= 48) and (i <= 63)) {
        //     F = C ^ (B | (~D));
        //     g = (7 * i) % 16;
        // }

        F = F + A + K[i] + M[g];
        A = B;
        //A = D;
        //D = C;
        //C = B;
        B = B + RotateLeft(F, s[i]);
        
    } // end 64-step loop

    a0 = a0 + A;
    b0 = b0 + B;
    //c0 = c0 + C;
    //d0 = d0 + D;
    
    // std::cout << "End of loop - a0, b0, c0, d0" << std::endl;
    // std::cout << OutputHex(a0) << " " << OutputHex(b0) << " " << OutputHex(c0) << " " << OutputHex(d0) << " " << std::endl;

    WordToBytes(a0, digest);
    WordToBytes(b0, digest + 4);  //  digest is now 64 bits
    //WordToBytes(c0, digest + 8);  //  digest is now 96 bits 
    //WordToBytes(d0, digest + 12);

}