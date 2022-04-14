#include "Routine.h"

void GetMD5Hash(std::vector<uint32_t> words, uint8_t digest[]) {
    //  had to change a lot to make the incremental hashes different from each other
    
    // Initialize variables:
    uint32_t a0 = 0x67452301;
    uint32_t b0 = 0xefcdab89;

    //  Initialize random constants
    uint32_t K[16] =  { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee ,
                        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501 };

    int s[16] =   { 7, 12, 17, 22,  7, 12, 17, 22 };

    uint32_t M[8];
    //  assume one block - 8 words big - 256 bits
    for (int i = 0; i < 8; i++) { M[i] = words[i]; }

    uint32_t A = a0;
    uint32_t B = b0;

    for (int i = 0; i < 8; i++) {
        uint32_t F;
        F = (B) | (~A);
        F = F + A + K[i] + M[i];
        A = B;
        B = B + RotateLeft(F, s[i]);
    } 

    a0 = a0 + A;
    b0 = b0 + B;

    WordToBytes(a0, digest);
    WordToBytes(b0, digest + 4);  //  digest is now 64 bits

}