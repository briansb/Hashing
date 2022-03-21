#include "pch.h"
#include "SHA1-algorithm.h"
#include "BitGroup.h"
#include "run_data.h"
#include <iostream>

std::string SHA1(std::string message, int run_number, bool test) {

	// load constants
	BitGroup h0 = BitGroup("h67452301", 32);
	BitGroup h1 = BitGroup("hefcdab89", 32);
	BitGroup h2 = BitGroup("h98badcfe", 32);
	BitGroup h3 = BitGroup("h10325476", 32);
	BitGroup h4 = BitGroup("hc3d2e1f0", 32);
	if (test) Datamatch(run_number, h0, "initial_h0"); 
	if (test) Datamatch(run_number, h1, "initial_h1"); 
	if (test) Datamatch(run_number, h2, "initial_h2");
	if (test) Datamatch(run_number, h3, "initial_h3"); 
	if (test) Datamatch(run_number, h4, "initial_h4");
	
	// message to hash
	BitGroup message_1 = BitGroup("c" + message, "msg");
	//std::cout << message_1.text() << std::endl;
	if (test) Datamatch(run_number, message_1, "message_1");
	// append 1
	BitGroup message_2 = message_1.append(BitGroup("b1"));
	if (test) Datamatch(run_number, message_2, "message_2");
	// if using Baseline as source of test, must subtract seven zeros

	// append zeros...see http://www.metamorphosite.com/one-way-hash-encryption-sha1-data-software
	//   and https://en.wikipedia.org/wiki/SHA-1 
	int additional_zeros = 448 - (message_2.size() % 512);
	if (additional_zeros < 0) { additional_zeros += 512; }
	std::string zeros(additional_zeros, '0');
	BitGroup message_3 = message_2.append(BitGroup("b" + zeros, additional_zeros));
	if (test) Datamatch(run_number, message_3, "message_3");

	// append original message size
	BitGroup original_size = BitGroup("d" + std::to_string(message_1.size()), 64);
	BitGroup message_final = message_3.append(original_size);
	if (test) Datamatch(run_number, message_final, "message_final");

	// ready to chunk
	size_t NumberOfChunks = message_final.size() / 512;
	BitGroup message_chunk = BitGroup();
	BitGroup Block[80];
	BitGroup a = BitGroup("b", 32);
	BitGroup b = BitGroup("b", 32);
	BitGroup c = BitGroup("b", 32);
	BitGroup d = BitGroup("b", 32);
	BitGroup e = BitGroup("b", 32);
	BitGroup f = BitGroup("b", 32);
	BitGroup k = BitGroup("b", 32);
	BitGroup temp = BitGroup("b", 32);
	// break message_final into chunks of 512 bits each
	for (int chunk_number = 0; chunk_number < NumberOfChunks; ++chunk_number) {
		message_chunk = message_final.subword((NumberOfChunks - chunk_number - 1) * 512, 512);
		if (test) Datamatch(run_number, message_chunk, "message_chunk", chunk_number);

		std::cout << "Chunk " << chunk_number << "...." << std::endl;
		std::cout << "Generating 80 32-bit words.... " << std::endl;
		// break message_chunk into 16 32-bit words
		for (int i = 0; i < 16; ++i) {
			Block[i] = message_chunk.subword((16 - i - 1) * 32, 32);
			if (test) Datamatch(run_number, Block[i], "Block", chunk_number, i); 
		}
		// generate 64 additional 32-bit words
		for (int i = 16; i < 80; ++i) {
			Block[i] = (Block[i - 3] ^ Block[i - 8] ^ Block[i - 14] ^ Block[i - 16]) <= 1;
			if (test) Datamatch(run_number, Block[i], "Block", chunk_number, i);
		}
		std::cout << "Completed 80 32-bit words.... " << std::endl;

		a = h0;
		b = h1;
		c = h2;
		d = h3;
		e = h4;

		for (int i = 0; i<80; ++i) {
			if ((i >= 0) & (i <= 19)) {
				f = (b & c) | ((!b) & d);
				k = BitGroup("h5A827999");	}
			else if ((i >= 20) & (i <= 39)) {
				f = b ^ c ^ d;
				k = BitGroup("H6ED9EBA1"); }
			else if ((i >= 40 ) & (i <= 59)) {
				f = (b & c) | (b & d) | (c & d);
				k = BitGroup("h8F1BBCDC"); }
			else if ((i >= 60) & (i <= 79)) {
				f = b ^ c ^ d;
				k = BitGroup("hCA62C1D6"); }

			temp = ((a <= 5) + f + e + k + Block[i]).lsb(32);
			e = d;
			d = c;
			c = b <= 30;
			b = a;
			a = temp;

			if (test) Datamatch(run_number, a, "a", chunk_number, i);
			if (test) Datamatch(run_number, b, "b", chunk_number, i);
			if (test) Datamatch(run_number, c, "c", chunk_number, i);
			if (test) Datamatch(run_number, d, "d", chunk_number, i);
			if (test) Datamatch(run_number, e, "e", chunk_number, i);
			//std::cout << "Chunk = " << chunk_number << ", index = " << i << std::endl;
			//std::cout << "a = " << a.text_ext() << std::endl << "b = " << b.text_ext() << std::endl << "c = " << c.text_ext() << std::endl << "d = " << d.text_ext() << std::endl << "e = " << e.text_ext() << std::endl;
		}

		h0 = (h0 + a).lsb(32);
		h1 = (h1 + b).lsb(32);
		h2 = (h2 + c).lsb(32);
		h3 = (h3 + d).lsb(32);
		h4 = (h4 + e).lsb(32);
		if (test) Datamatch(run_number, h0, "h0", chunk_number);
		if (test) Datamatch(run_number, h1, "h1", chunk_number);
		if (test) Datamatch(run_number, h2, "h2", chunk_number);
		if (test) Datamatch(run_number, h3, "h3", chunk_number);
		if (test) Datamatch(run_number, h4, "h4", chunk_number);
		std::cout << "End of chunk = " << chunk_number << "...." << std::endl;
		//std::cout << "h0 = " << h0.text_ext() << std::endl << "h1 = " << h1.text_ext() << std::endl << "h2 = " << h2.text_ext() << std::endl << "h3 = " << h3.text_ext() << std::endl << "h4 = " << h4.text_ext() << std::endl;

	}
	// combine h's into one 160-bit word.  Use append.
	BitGroup digest = (((h0.append(h1)).append(h2)).append(h3)).append(h4);
	if (test) Datamatch(run_number, digest, "digestinbinary");
	if (test) Datamatch(run_number, digest, "digestinhex");
	//std::cout << digest.htext() << std::endl;
	//std::cout << digest.htext_ext() << std::endl;

	return digest.htext();
}