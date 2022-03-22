

#include <iostream>
#include <bitset>
#include <sstream>
#include <iomanip>

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
    uint8_t  a8;
    uint16_t a16;
    uint32_t a32;
    uint64_t a64;

    a8 = 17;
    a16 = 19;
    a32 = 21;
    a64 = 23;

    //std::cout << "a8 = " << int_to_binary(a8) << std::endl;
    //std::cout << "a16 = " << int_to_binary(a16) << std::endl;
    //std::cout << "a32= " << int_to_binary(a32) << std::endl;
    //std::cout << "a64 = " << int_to_binary(a64) << std::endl;
    //std::cout << std::endl;

    //
    //std::cout << "a8 = " << int_to_hex(a8) << std::endl;
    //std::cout << "a16 = " << int_to_hex(a16) << std::endl;
    //std::cout << "a32 = " << int_to_hex(a32) << std::endl;
    //std::cout << "a64 = " << int_to_hex(a64) << std::endl;
    //std::cout << std::endl;


    //  need spacing between bytes
    //  a block is 16 32-bit words
    //  use a vector for the collection of blocks

    std::string message_string = "Brian Birmingham";
    uint32_t single_character;
    uint32_t word = 0;
    int shift_amount = 24;
    for (int i = 0; i < 4; i++) {
        single_character = char(message_string[i]);
        single_character = single_character << shift_amount;
        word = word + single_character;
        shift_amount -= 8;
    }


    std::cout << "word= " << int_to_binary(word) << std::endl;
    std::cout << "word = " << int_to_hex(word) << std::endl;

    return 0;
}

