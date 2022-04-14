
#include <iostream>

#include "Input.h"
#include "Output.h"
#include "Utilities.h"
#include "Routine.h"

int main()
{
    std::string message_base = "Brian";
    std::string message_string;
    int counter = 0;
    std::vector<uint32_t> words;
    uint8_t digest[8];  // was 16
    while (counter < 10000000) {
      words.clear();
      //  message string should be <= 27 characters
      message_string = message_base + std::to_string(counter);
      std::cout << "Message(" << message_string << ") = " << OutputHex(message_string) << std::endl;
      LoadStringMessageIntoMessageVector(message_string, words);
      //for (size_t i = 0; i<words.size(); i++) { std::cout << OutputHex(words[i]) << " "; } std::cout << std::endl;

      GetMD5Hash(words, digest);

      std::cout << "   Hash(" << message_string << ") = ";
      for (int i = 0; i < 8; i++) { std::cout << std::setfill('0') << std::setw(2) << std::hex << +digest[i]; }
      std::cout << std::endl << std::endl;

      if (digest[0] == 0x01 and digest[1] == 0x02 and digest[2] == 0x01) {
        std::cout << "Found it!" << std::endl;
        return 0;
      }

      counter++;
    }
    return 0;
}

