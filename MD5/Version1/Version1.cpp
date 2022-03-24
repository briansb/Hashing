

#include <iostream>

#include "Input.h"
#include "Output.h"

/************  Assumptions  ************/
/*     characters are 8-bit            */
/*     words are 4, 8-bit characters   */
/*     words are 32-bits               */
/*     blocks are 16 words             */
/*     Little Endian                   */
/***************************************/


int main()
{
 
    std::string message_string = "Brian Birmingham";
    //std::string message_string = "Brian Birmingham is my name for the duration of this test.";
    std::vector<uint32_t> words;
    LoadStringMessageIntoMessageVector(message_string, words);
    // for (size_t i = 0; i < words.size(); i++) {
    //     std::cout << "Word " << std::setw(2) << i << ":  " << OutputHex(words[i]) << std::endl;
    // }


    // words is a vector of size = integer multiple of 16
    for (size_t block = 0; block < (words.size() / 16); block++) {
        //  build array M[] of the first 16 words





    }
 
    

    return 0;
}

