#include "pch.h"
#include "sha1.h"
#include "output.h"
#include "transform.h"
#include <limits>
#include <iomanip>
#include <fstream>

std::string message_block;  // this is to distinguish it from the message string

// initial number of 32-bit integers in block = 16
// final number of 32-bit integers in block = 80
// number of 32-bit integers in the digest (output) = 5
uint32 block[FINAL_BLOCK_INTS]; // 
uint32 digest[DIGEST_INTS];


// This follows the SHA-1 pseudocode in Wikipedia
// Also, much of the code is from Steve Reid <steve@edmweb.com>, Bruce Guenter <bruce@untroubled.org>, Volker Grabsch <vog@notjusthosting.com> on zedwood.com
std::string sha1(const std::string &message) {
	Initialize();

	message_block = message;

	// original message length in bits
	if ((message_block.size() * 8) > std::numeric_limits<unsigned long long>::max()) {
		std::cout << "Message block too long" << std::endl;
		exit(1);
	}
	//std::cout << print_bits(message, 'z') << std::endl;
	uint64 original_message_length_in_bits = message_block.size() * 8;

	// add a 1 to the end
	message_block += (char)0x80;
	
	// add zeros so that length is congruent to 448 mod 512
	while (((message_block.size() * 8) % 512) != 448) {
		message_block += (char)0x00;
	}

	// add 64-bit word containing original_message_length
	// 0xff always evaluates to an int
	for (int i = 0; i < 8; ++i) {
		char b = (original_message_length_in_bits >> (56 - i * 8)) & 0xff;
		message_block += b;
	}

	// write data to file
	std::ofstream myfile("run_data.txt");
	if (myfile.is_open()) {
		myfile << "run_data\n";
	}
	else std::cout << "Unable to open file";
	// https://ask.libreoffice.org/en/question/29191/how-do-i-convert-rows-into-columns-or-vice-versa-in-calc/


	// loop on every block...512 bits per block
	// and message_block is a string, so 512 / 8 = 64
	std::string buffer;
	for (size_t i = 0; i < message_block.size(); i += 64) {
		// buffer is 512 bits long... 64 * 8
		// buffer is the individual chunk that gets sent to transform
		buffer = message_block.substr(i, 64);

		// put message_block (64 bytes) into block (16 32-bit words)
		buffer_to_block(buffer);
		myfile << "Chunk number " << i << std::endl;
		// main algorithm
		transform(block, digest, myfile);
		
		buffer.clear();
	}

	myfile.close();

	// convert 5-integer digest to hex
	// understand this
	std::ostringstream result;
	for (unsigned int i = 0; i < DIGEST_INTS; i++) 	{
		// 0xffffffff is 32 bits worth of ones...we only need the right 32 bits of digest
		// then, convert to hex.  Will be converted to characters
		result << std::hex << std::setfill('0') << std::setw(8) << (digest[i] & 0xffffffff);
	}
	

	return result.str();
}

void buffer_to_block(const std::string &buffer)
{
	// 0xff is always a literal of type int
	// https://stackoverflow.com/questions/46246411/why-does-shifting-0xff-left-by-24-bits-result-in-an-incorrect-value
	
	// The loop below grabs the rightmost 8 bits of buffer[3], which is probably the entire thing (a character)
	// BUT, and this is important, it puts those 8 bits into the rightmost byte of a 32-bit integer,
	//    since 0xff always evaluates to an int
	// Next, it gets the bits of buffer[2], which is the next character and puts them into the rightmost byte of another 32-bit integer
	// Then, it shifts this 32-bit integer 8 bits to the left.  
	// So now you have a 32-bit integer with the leftmost byte = 0, the next byte = 0, 
	//             the next byte = buffer[2], and the rightmost byte = buffer[3]

	// Convert the std::string (byte buffer) to a uint32 array (big endian)
	for (unsigned int i = 0; i < INITIAL_BLOCK_INTS; i++) {
	// 	// the masking with ff makes sure we get only 8 bits
		block[i] = (buffer[4 * i + 3] & 0xff)
				 | (buffer[4 * i + 2] & 0xff) << 8
				 | (buffer[4 * i + 1] & 0xff) << 16
				 | (buffer[4 * i + 0] & 0xff) << 24;
	}
}

void Initialize() {
	/* SHA1 initialization constants */
	// use digest[] in place of h
	digest[0] = 0x67452301;
	digest[1] = 0xefcdab89;
	digest[2] = 0x98badcfe;
	digest[3] = 0x10325476;
	digest[4] = 0xc3d2e1f0;

	message_block = "";
}