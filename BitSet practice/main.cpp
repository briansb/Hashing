/* bitset practice */
//  https://www.geeksforgeeks.org/c-bitset-and-its-application/

//  https://www.cplusplus.com/reference/bitset/bitset/
//  https://www.educba.com/c-plus-plus-bitset/
//  https://docs.microsoft.com/en-us/cpp/standard-library/bitset-class?view=msvc-170

#include <iostream>
#include <bitset>

int main() {

    std::bitset<5> b1 ( 6 );

    std::cout << "The original bitset b1( 6 ) is: ( "<< b1 << " )"
        << std::endl;
       
    return 0;
}
