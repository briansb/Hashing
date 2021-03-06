

#include <iostream>

#include "Input.h"
#include "Output.h"
#include "Utilities.h"

/************  Assumptions  ************/
/*     characters are 8-bit            */
/*     words are 4, 8-bit characters   */
/*     words are 32-bits               */
/*     blocks are 16 words             */
/*     Little Endian                   */
/***************************************/

// Initialize variables:
uint32_t a0 = 0x67452301;
uint32_t b0 = 0xefcdab89;
uint32_t c0 = 0x98badcfe;
uint32_t d0 = 0x10325476;

//  Initialize constants
uint32_t K[64] = { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee ,
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

int s[64] = { 7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
                  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
                  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
                  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21 };

int main()
{
 
    std::string message_string = "Brian Birmingham4";  // hash = 0f1b2acb2988f0af65b6f1153be7e273
    //std::string message_string = "This is a test of the MD5 hashing algorithm.  I will be using it to become rich.";
    //std::string message_string = "GenesisIG will read the configuration.ini file at launch; that determines the configuration. After that, we communicate with it via CIGI messages when running the sim. Changing the configuration file would produce a different image when the renderer is done loading because part of the configuration is providing an initial pose.  The simulated camera plugin and the image processor plugin (admittedly not very distinctive names) are similar, but they serve different purposes. Broadly, you can think of the simulated camera plugin as our SWIL plugin, while the IPP is our HWIL plugin. They both distort images created by Genesis, but the key difference is that the IPP displays two windows: one undistorted which is what Genesis created, and one distorted. We can display the distorted window live during the sim so that our camera can take pictures of it on the monitor.  FBO stands for either frame buffer output or frame buffer object. Frame buffer refers to the pixel data, or the image itself. ExternalFboProcessor.cpp (Image Processor Plugin) and ExternalFboCamera.cpp (Simulated Camera Plugin), are the bulk of the source code for their respective plugins.";
    std::vector<uint32_t> words;
    LoadStringMessageIntoMessageVector(message_string, words);
    
    uint32_t M[16];  // words for hashing
    // words is a vector of size = integer multiple of 16
    for (size_t block = 0; block < (words.size() / 16); block++) {
        
        //  build array M[] of the first 16 words
        for (int i = 0; i < 16; i++) {
            M[i] = words[block * 16 + i];
        }
        
        // std::cout << "Block " << block << std::endl;
        // for (int j = 0; j < 16; j++) {
        //     std::cout << OutputHex(M[j]) << std::endl;
        // }
        // std::cout << std::endl;


        uint32_t A = a0;
        uint32_t B = b0;
        uint32_t C = c0;
        uint32_t D = d0;

        for (int i = 0; i < 64; i++) {
            uint32_t F, g;
            if ((i >= 0) and (i <= 15)) {
                F = (B & C) | ((~B) & D);
                g = i;
            }
            else if ((i >= 16) and (i <= 31)) {
                F = (D & B) | ((~D) & C);
                g = (5 * i + 1) % 16;
            }
            else if ((i >= 32) and (i <= 47)) {
                F = B ^ C ^ D;
                g = (3 * i + 5) % 16;
            }
            else if ((i >= 48) and (i <= 63)) {
                F = C ^ (B | (~D));
                g = (7 * i) % 16;
            }

            F = F + A + K[i] + M[g];
            A = D;
            D = C;
            C = B;
            B = B + RotateLeft(F, s[i]);
        } // end 64-step loop

        a0 = a0 + A;
        b0 = b0 + B;
        c0 = c0 + C;
        d0 = d0 + D;

    }  //  end loop over blocks
 
    // a0 - d0 are in big endian
    //std::cout << "Big Endian = " << OutputHex(a0) << " " << OutputHex(b0) << " " << OutputHex(c0) << " " << OutputHex(d0) << std::endl;

    uint8_t digest[16];
    WordToBytes(a0, digest);
    WordToBytes(b0, digest + 4);
    WordToBytes(c0, digest + 8);
    WordToBytes(d0, digest + 12);

    std::cout << "Hash(" << message_string << ") = ";
    for (int i = 0; i < 16; i++) {
        printf("%2.2x", digest[i]);
    }
    std::cout << std::endl;

    return 0;
}

