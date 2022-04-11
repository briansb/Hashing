

#include <iostream>

#include "Input.h"
#include "Output.h"
#include "Utilities.h"
#include "Routine.h"



/* current version - note smaller message and smaller digest
Message(Brian0) = 427269616e30
   Hash(Brian0) = 92261027c3d5ce30
Message(Brian1) = 427269616e31
   Hash(Brian1) = c0abd5e9c7582d28
Message(Brian2) = 427269616e32
   Hash(Brian2) = 70f4f8074289a5bf
Message(Brian3) = 427269616e33
   Hash(Brian3) = 9bd1fc2654a7b5ec
Message(Brian4) = 427269616e34
   Hash(Brian4) = 9b0b753d4c0ed222
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
      //  message string should be <= 27 characters
      message_string = message_base + std::to_string(counter);
      std::cout << "Message(" << message_string << ") = " << OutputHex(message_string) << std::endl;
      LoadStringMessageIntoMessageVector(message_string, words);
      //for (size_t i = 0; i<words.size(); i++) { std::cout << OutputHex(words[i]) << " "; } std::cout << std::endl;

      GetMD5Hash(words, digest);

      std::cout << "   Hash(" << message_string << ") = ";
      for (int i = 0; i < 8; i++) { std::cout << std::setfill('0') << std::setw(2) << std::hex << +digest[i]; }
      std::cout << std::endl << std::endl;

      counter++;
    }
    return 0;
}

