

#include <iostream>
#include <bitset>
#include <sstream>
#include <iomanip>

#include "Input.h"

template< typename T >
std::string int_to_hex(T i)
{
    std::stringstream stream;
    stream << "0x"
           << std::setfill('0') 
           << std::setw(sizeof(T) * 2)
           << std::hex << i;
    return stream.str();
}

template< typename T >
std::string int_to_binary(T i)
{
    std::stringstream stream;
    stream << std::bitset<sizeof(T) * 8>(i);
    return stream.str();
}

int main()
{
 
    //  need spacing between bytes
    //  a block is 16 32-bit words
    //  use a vector for the collection of blocks

    std::string message_string = "Brian Birmingham";
    uint32_t single_character;
    uint32_t word = 0;
    uint32_t block[16];
    int shift_amount = 24;
    int word_index = 0;
    for (size_t i = 0; i < message_string.length(); i++) {
        single_character = char(message_string[i]);
        single_character = single_character << shift_amount;
        word = word + single_character;
        shift_amount -= 8;

        if (shift_amount < 0) {
            shift_amount = 24;
            block[word_index] = word;
            word = 0;
            word_index++;
        }

    }


    std::cout << "word= " << int_to_binary(block[0]) << std::endl;
    std::cout << "word = " << int_to_hex(block[0]) << std::endl;
    std::cout << "word= " << int_to_binary(block[1]) << std::endl;
    std::cout << "word = " << int_to_hex(block[1]) << std::endl;
    std::cout << "word= " << int_to_binary(block[2]) << std::endl;
    std::cout << "word = " << int_to_hex(block[2]) << std::endl;

    return 0;
}

