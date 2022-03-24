
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

    // Do we have enough room left for the size....we need two words...64-bits
    size_t index = words.size() % 16;
    word = 0;
    if ( index <= 14 ) {
        //  size can go into this block
        //  fill up vector with zero-value words
        while (index < 14) {
            words.push_back(word);
            index++;
        }
    } else {
        //  need another block
        index = 0;
        // 14 plus the unused one from the previous block
        while (index < 14 + 1) {
            words.push_back(word);
            index++;
        }
    }
    //  add the size - assumes message length is < 2^32 characters,  (4,294,967,296)
    word = message_length;
    words.push_back(word);
    words.push_back(0);

    return;
}