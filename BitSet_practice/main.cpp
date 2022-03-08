/* bitset practice */
//  https://www.geeksforgeeks.org/c-bitset-and-its-application/

//  https://www.cplusplus.com/reference/bitset/bitset/
//  https://www.educba.com/c-plus-plus-bitset/
//  https://docs.microsoft.com/en-us/cpp/standard-library/bitset-class?view=msvc-170

#include <iostream>
#include <bitset>

int main() {

    std::bitset<8> letters[5];
    letters[0] = 66;
    letters[1] = 114;
    letters[2] = 105;
    letters[3] = 97;
    letters[4] = 110;
    
    std::cout << letters[0] << " " << 
                 letters[1] << " " <<
                 letters[2] << " " <<
                 letters[3] << " " <<
                 letters[4] << std::endl;

    std::cout << letters[0].to_ulong() << " " << 
                 letters[1].to_ulong() << " " <<
                 letters[2].to_ulong() << " " <<
                 letters[3].to_ulong() << " " <<
                 letters[4].to_ulong() << std::endl;

    std::cout << char(letters[0].to_ulong()) << " " << 
                 char(letters[1].to_ulong()) << " " <<
                 char(letters[2].to_ulong()) << " " <<
                 char(letters[3].to_ulong()) << " " <<
                 char(letters[4].to_ulong()) << std::endl;

    // now combine into one 32-bit word
    std::bitset<32> lotsofletters;

    lotsofletters = letters[0].to_ulong();

    lotsofletters = lotsofletters << 8;
    lotsofletters = lotsofletters.to_ulong() + letters[1].to_ulong();
    
    lotsofletters = lotsofletters << 8;
    lotsofletters = lotsofletters.to_ulong() + letters[2].to_ulong();

    lotsofletters = lotsofletters << 8;
    lotsofletters = lotsofletters.to_ulong() + letters[3].to_ulong();

    lotsofletters = lotsofletters << 8;
    lotsofletters = lotsofletters.to_ulong() + letters[4].to_ulong();

    std::cout << lotsofletters << std::endl;

    return 0;
}
