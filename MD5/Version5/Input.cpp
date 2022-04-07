
#include "Input.h"

void LoadStringMessageIntoMessageVector(std::string s, std::vector<uint32_t> &words) {
    // this loads word in little endian...
    //   first character is right-most byte, then next 3 from right to left
    //  then, push into vector and start over
    uint32_t single_character;
    uint32_t word = 0;
    uint32_t message_length = 0;
    int shift_amount = 0;
    for (size_t i = 0; i < s.length(); i++) {
        single_character = char(s[i]);
        single_character = single_character << shift_amount;
        word = word + single_character;
        message_length += 8;
        shift_amount += 8;

        if (shift_amount == 32) {
            words.push_back(word);
            shift_amount = 0;
            word = 0;
        }
    }
    //  Now load the "1"
    if (shift_amount != 0) {
        single_character = 0x80;
        single_character = single_character << shift_amount;
        word = word + single_character;
    } else {
        word = 0x80;
    }
    words.push_back(word);

    // Only one block - 8 words big - 256 bits
    size_t index = words.size() % 8;
    word = 0;
    if ( index <= 7 ) {
        //  fill up vector with zero-value words
        while (index < 7) {
            words.push_back(word);
            index++;
        }
    } 
    //  add the size - assumes message length is < 2^16 characters,  (65,536)
    word = message_length;
    words.push_back(word);

    return;
}