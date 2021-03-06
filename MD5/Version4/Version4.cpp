

#include <iostream>

#include "Input.h"
#include "Output.h"
#include "Utilities.h"
#include "Routine.h"



/*  full MD5
Hash(Brian Birmingham0) = 402d55700d50347dbe8302c2902545df
Hash(Brian Birmingham1) = 52d97689a0a6378e2d5a86d2b0b5d802
Hash(Brian Birmingham2) = 7544dbbcb814882e63885c695c6a82eb
Hash(Brian Birmingham3) = 8d4fe50109d1b0eaaf7118e64f41d061
Hash(Brian Birmingham4) = 0f1b2acb2988f0af65b6f1153be7e273

current version - note smaller message
Hash(Brian0) = 5366e17cca5501d1cab807242efd6916
Hash(Brian1) = 6f4af87823de8413ce7bc406aded5db3
Hash(Brian2) = 9277c77075ecff94fbd4c19768a945f3
Hash(Brian3) = 5fd449988819db3a2985c326ad95c161
Hash(Brian4) = 89661fa3c3d5746227e2563471c4836f
*/
int main()
{
    std::string message_base = "Brian";
    std::string message_string;
    int counter = 0;
    std::vector<uint32_t> words;
    uint8_t digest[8];  // was 16
    while (counter < 10) {
        words.clear();
        //  message string should be less than 24 characters
        message_string = message_base + std::to_string(counter);
        std::cout << "Message(" << message_string << ") = " << OutputHex(message_string) << std::endl;
        LoadStringMessageIntoMessageVector(message_string, words);

        GetMD5Hash(words, digest);

        std::cout << "   Hash(" << message_string << ") = ";
        for (int i = 0; i < 8; i++) { std::cout << std::setfill('0') << std::setw(2) << std::hex << +digest[i]; }
        std::cout << std::endl << std::endl;

        counter++;
    }
    return 0;
}

