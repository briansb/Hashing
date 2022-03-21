#include "pch.h"
#include "transform.h"
#include "output.h"


// Different operations used in SHA1
// SHA1_ROL rotates left (not shift) "value" by "bits"
#define SHA1_ROL(value, bits) (           ((value) << (bits))       |           (    ((value) & 0xffffffff) >> (32 - (bits)))         )
#define SHA1_BLK(i) (block[i&15] = SHA1_ROL(block[(i+13)&15] ^ block[(i+8)&15] ^ block[(i+2)&15] ^ block[i&15],1))
#define SHA1_R0(v,w,x,y,z,i) z += ((w&(x^y))^y)     + block[i]    + 0x5a827999 + SHA1_ROL(v,5); w=SHA1_ROL(w,30);
#define SHA1_R1(v,w,x,y,z,i) z += ((w&(x^y))^y)     + SHA1_BLK(i) + 0x5a827999 + SHA1_ROL(v,5); w=SHA1_ROL(w,30);
#define SHA1_R2(v,w,x,y,z,i) z += (w^x^y)           + SHA1_BLK(i) + 0x6ed9eba1 + SHA1_ROL(v,5); w=SHA1_ROL(w,30);
#define SHA1_R3(v,w,x,y,z,i) z += (((w|x)&y)|(w&x)) + SHA1_BLK(i) + 0x8f1bbcdc + SHA1_ROL(v,5); w=SHA1_ROL(w,30);
#define SHA1_R4(v,w,x,y,z,i) z += (w^x^y)           + SHA1_BLK(i) + 0xca62c1d6 + SHA1_ROL(v,5); w=SHA1_ROL(w,30);

uint32 RotateLeft(uint32 word, int number_of_bits) {
	uint32 first = word << number_of_bits;
	uint32 second = (word & 0xffffffff) >> (32 - number_of_bits);
	return first | second;
}

void transform(uint32(&block)[FINAL_BLOCK_INTS], uint32(&digest)[DIGEST_INTS], std::ofstream& outputfile) {




    // Hash a single 512-bit block. This is the core of the algorithm

	/* Copy digest[] to working vars */
	// digest[] used in place of h
	uint32 a = digest[0];
	uint32 b = digest[1];
	uint32 c = digest[2];
	uint32 d = digest[3];
	uint32 e = digest[4];

	
	//SHA1_R0(a, b, c, d, e, 0);  // this was the original line.  Everything below was added by moi
	//        v, w, x, y, z, i
	// & = bitwise AND     | = bitwise OR    ^ = bitwise XOR  ~ = bitwise NOT
	//  see https://en.wikipedia.org/wiki/Exclusive_or  
	// I think this is the algorithm he used for e+= .....
	//   https://brilliant.org/wiki/secure-hashing-algorithms/
	//e += ( (b  & (c^d) ) ^ d) + block[0] + 0x5a827999 + RotateLeft(a, 5);
	e += (    (b  &  c) | ( (~b) & d)   ) + block[0] + 0x5a827999 + RotateLeft(a, 5);
	b = RotateLeft(b, 30);
	// must be mindful of order
	// instead of setting a = e after this step, he sends e to the a argument of the next routine
	// std::cout << "Index = 0 " << std::endl << print_abcde_bits(e,a,b,c,d) << std::endl;
	outputfile << dump_to_csv(e,a,b,c,d) << std::endl;

	SHA1_R0(e, a, b, c, d, 1);
	// std::cout << "Index = 1 " << std::endl << print_abcde_bits(d,e,a,b,c) << std::endl;
	outputfile << dump_to_csv(d,e,a,b,c) << std::endl;

	SHA1_R0(d, e, a, b, c, 2);
	// std::cout << "Index = 2 " << std::endl << print_abcde_bits(c, d, e, a, b) << std::endl;
	outputfile << dump_to_csv(c, d, e, a, b) << std::endl;

	SHA1_R0(c, d, e, a, b, 3);
	// std::cout << "Index = 3 " << std::endl << print_abcde_bits(b, c, d, e, a) << std::endl;
	outputfile << dump_to_csv(b, c, d, e, a) << std::endl;

	SHA1_R0(b, c, d, e, a, 4);
	// std::cout << "Index = 4 " << std::endl << print_abcde_bits(a, b, c, d, e) << std::endl;
	outputfile << dump_to_csv(a, b, c, d, e) << std::endl;

	SHA1_R0(a, b, c, d, e, 5);
	// std::cout << "Index = 5 " << std::endl << print_abcde_bits(e, a, b, c, d) << std::endl;
	outputfile << dump_to_csv(e, a, b, c, d) << std::endl;

	SHA1_R0(e, a, b, c, d, 6);
	// std::cout << "Index = 6 " << std::endl << print_abcde_bits(d, e, a, b, c) << std::endl;
	outputfile << dump_to_csv(d, e, a, b, c) << std::endl;

	SHA1_R0(d, e, a, b, c, 7);
	// std::cout << "Index = 7 " << std::endl << print_abcde_bits(c, d, e, a, b) << std::endl;
	outputfile << dump_to_csv(c, d, e, a, b) << std::endl;

	SHA1_R0(c, d, e, a, b, 8);
	// std::cout << "Index = 8 " << std::endl << print_abcde_bits(b, c, d, e, a) << std::endl;
	outputfile << dump_to_csv(b, c, d, e, a) << std::endl;

	SHA1_R0(b, c, d, e, a, 9);
	// std::cout << "Index = 9 " << std::endl << print_abcde_bits(a, b, c, d, e) << std::endl;
	outputfile << dump_to_csv(a, b, c, d, e) << std::endl;

	SHA1_R0(a, b, c, d, e, 10);
	// std::cout << "Index = 10 " << std::endl << print_abcde_bits(e, a, b, c, d) << std::endl;
	outputfile << dump_to_csv(e, a, b, c, d) << std::endl;

	SHA1_R0(e, a, b, c, d, 11);
	// std::cout << "Index = 11 " << std::endl << print_abcde_bits(d, e, a, b, c) << std::endl;
	outputfile << dump_to_csv(d, e, a, b, c) << std::endl;

	SHA1_R0(d, e, a, b, c, 12);
	// std::cout << "Index = 12 " << std::endl << print_abcde_bits(c, d, e, a, b) << std::endl;
	outputfile << dump_to_csv(c, d, e, a, b) << std::endl;

	SHA1_R0(c, d, e, a, b, 13);
	// std::cout << "Index = 13 " << std::endl << print_abcde_bits(b, c, d, e, a) << std::endl;
	outputfile << dump_to_csv(b, c, d, e, a) << std::endl;

	SHA1_R0(b, c, d, e, a, 14);
	// std::cout << "Index = 14 " << std::endl << print_abcde_bits(a, b, c, d, e) << std::endl;
	outputfile << dump_to_csv(a, b, c, d, e) << std::endl;

	SHA1_R0(a, b, c, d, e, 15);
	// std::cout << "Index = 15 " << std::endl << print_abcde_bits(e, a, b, c, d) << std::endl;
	outputfile << dump_to_csv(e, a, b, c, d) << std::endl;

	SHA1_R1(e, a, b, c, d, 16);
	// std::cout << "Index = 16 " << std::endl << print_abcde_bits(d, e, a, b, c) << std::endl;
	outputfile << dump_to_csv(d, e, a, b, c) << std::endl;

	SHA1_R1(d, e, a, b, c, 17);
	// std::cout << "Index = 17 " << std::endl << print_abcde_bits(c, d, e, a, b) << std::endl;
	outputfile << dump_to_csv(c, d, e, a, b) << std::endl;

	SHA1_R1(c, d, e, a, b, 18);
	// std::cout << "Index = 18 " << std::endl << print_abcde_bits(b, c, d, e, a) << std::endl;
	outputfile << dump_to_csv(b, c, d, e, a) << std::endl;

	SHA1_R1(b, c, d, e, a, 19);
	// std::cout << "Index = 19 " << std::endl << print_abcde_bits(a, b, c, d, e) << std::endl;
	outputfile << dump_to_csv(a, b, c, d, e) << std::endl;

	SHA1_R2(a, b, c, d, e, 20);
	// std::cout << "Index = 20 " << std::endl << print_abcde_bits(e, a, b, c, d) << std::endl;
	outputfile << dump_to_csv(e, a, b, c, d) << std::endl;

	SHA1_R2(e, a, b, c, d, 21);
	// std::cout << "Index = 21 " << std::endl << print_abcde_bits(d, e, a, b, c) << std::endl;
	outputfile << dump_to_csv(d, e, a, b, c) << std::endl;

	SHA1_R2(d, e, a, b, c, 22);
	// std::cout << "Index = 22 " << std::endl << print_abcde_bits(c, d, e, a, b) << std::endl;
	outputfile << dump_to_csv(c, d, e, a, b) << std::endl;

	SHA1_R2(c, d, e, a, b, 23);
	// std::cout << "Index = 23 " << std::endl << print_abcde_bits(b, c, d, e, a) << std::endl;
	outputfile << dump_to_csv(b, c, d, e, a) << std::endl;

	SHA1_R2(b, c, d, e, a, 24);
	// std::cout << "Index = 24 " << std::endl << print_abcde_bits(a, b, c, d, e) << std::endl;
	outputfile << dump_to_csv(a, b, c, d, e) << std::endl;

	SHA1_R2(a, b, c, d, e, 25);
	// std::cout << "Index = 25 " << std::endl << print_abcde_bits(e, a, b, c, d) << std::endl;
	outputfile << dump_to_csv(e, a, b, c, d) << std::endl;

	SHA1_R2(e, a, b, c, d, 26);
	// std::cout << "Index = 26 " << std::endl << print_abcde_bits(d, e, a, b, c) << std::endl;
	outputfile << dump_to_csv(d, e, a, b, c) << std::endl;

	SHA1_R2(d, e, a, b, c, 27);
	// std::cout << "Index = 27 " << std::endl << print_abcde_bits(c, d, e, a, b) << std::endl;
	outputfile << dump_to_csv(c, d, e, a, b) << std::endl;

	SHA1_R2(c, d, e, a, b, 28);
	// std::cout << "Index = 28 " << std::endl << print_abcde_bits(b, c, d, e, a) << std::endl;
	outputfile << dump_to_csv(b, c, d, e, a) << std::endl;

	SHA1_R2(b, c, d, e, a, 29);
	// std::cout << "Index = 29 " << std::endl << print_abcde_bits(a, b, c, d, e) << std::endl;
	outputfile << dump_to_csv(a, b, c, d, e) << std::endl;

	SHA1_R2(a, b, c, d, e, 30);
	// std::cout << "Index = 30 " << std::endl << print_abcde_bits(e, a, b, c, d) << std::endl;
	outputfile << dump_to_csv(e, a, b, c, d) << std::endl;

	SHA1_R2(e, a, b, c, d, 31);
	// std::cout << "Index = 31 " << std::endl << print_abcde_bits(d, e, a, b, c) << std::endl;
	outputfile << dump_to_csv(d, e, a, b, c) << std::endl;

	SHA1_R2(d, e, a, b, c, 32);
	// std::cout << "Index = 32 " << std::endl << print_abcde_bits(c, d, e, a, b) << std::endl;
	outputfile << dump_to_csv(c, d, e, a, b) << std::endl;

	SHA1_R2(c, d, e, a, b, 33);
	// std::cout << "Index = 33 " << std::endl << print_abcde_bits(b, c, d, e, a) << std::endl;
	outputfile << dump_to_csv(b, c, d, e, a) << std::endl;

	SHA1_R2(b, c, d, e, a, 34);
	// std::cout << "Index = 34 " << std::endl << print_abcde_bits(a, b, c, d, e) << std::endl;
	outputfile << dump_to_csv(a, b, c, d, e) << std::endl;

	SHA1_R2(a, b, c, d, e, 35);
	// std::cout << "Index = 35 " << std::endl << print_abcde_bits(e, a, b, c, d) << std::endl;
	outputfile << dump_to_csv(e, a, b, c, d) << std::endl;

	SHA1_R2(e, a, b, c, d, 36);
	// std::cout << "Index = 36 " << std::endl << print_abcde_bits(d, e, a, b, c) << std::endl;
	outputfile << dump_to_csv(d, e, a, b, c) << std::endl;

	SHA1_R2(d, e, a, b, c, 37);
	// std::cout << "Index = 37 " << std::endl << print_abcde_bits(c, d, e, a, b) << std::endl;
	outputfile << dump_to_csv(c, d, e, a, b) << std::endl;

	SHA1_R2(c, d, e, a, b, 38);
	// std::cout << "Index = 38 " << std::endl << print_abcde_bits(b, c, d, e, a) << std::endl;
	outputfile << dump_to_csv(b, c, d, e, a) << std::endl;

	SHA1_R2(b, c, d, e, a, 39);
	// std::cout << "Index = 39 " << std::endl << print_abcde_bits(a, b, c, d, e) << std::endl;
	outputfile << dump_to_csv(a, b, c, d, e) << std::endl;

	SHA1_R3(a, b, c, d, e, 40);
	// std::cout << "Index = 40 " << std::endl << print_abcde_bits(e, a, b, c, d) << std::endl;
	outputfile << dump_to_csv(e, a, b, c, d) << std::endl;

	SHA1_R3(e, a, b, c, d, 41);
	// std::cout << "Index = 41 " << std::endl << print_abcde_bits(d, e, a, b, c) << std::endl;
	outputfile << dump_to_csv(d, e, a, b, c) << std::endl;

	SHA1_R3(d, e, a, b, c, 42);
	// std::cout << "Index = 42 " << std::endl << print_abcde_bits(c, d, e, a, b) << std::endl;
	outputfile << dump_to_csv(c, d, e, a, b) << std::endl;

	SHA1_R3(c, d, e, a, b, 43);
	// std::cout << "Index = 43 " << std::endl << print_abcde_bits(b, c, d, e, a) << std::endl;
	outputfile << dump_to_csv(b, c, d, e, a) << std::endl;

	SHA1_R3(b, c, d, e, a, 44);
	// std::cout << "Index = 44 " << std::endl << print_abcde_bits(a, b, c, d, e) << std::endl;
	outputfile << dump_to_csv(a, b, c, d, e) << std::endl;

	SHA1_R3(a, b, c, d, e, 45);
	// std::cout << "Index = 45 " << std::endl << print_abcde_bits(e, a, b, c, d) << std::endl;
	outputfile << dump_to_csv(e, a, b, c, d) << std::endl;

	SHA1_R3(e, a, b, c, d, 46);
	// std::cout << "Index = 46 " << std::endl << print_abcde_bits(d, e, a, b, c) << std::endl;
	outputfile << dump_to_csv(d, e, a, b, c) << std::endl;

	SHA1_R3(d, e, a, b, c, 47);
	// std::cout << "Index = 47 " << std::endl << print_abcde_bits(c, d, e, a, b) << std::endl;
	outputfile << dump_to_csv(c, d, e, a, b) << std::endl;

	SHA1_R3(c, d, e, a, b, 48);
	// std::cout << "Index = 48 " << std::endl << print_abcde_bits(b, c, d, e, a) << std::endl;
	outputfile << dump_to_csv(b, c, d, e, a) << std::endl;

	SHA1_R3(b, c, d, e, a, 49);
	// std::cout << "Index = 49 " << std::endl << print_abcde_bits(a, b, c, d, e) << std::endl;
	outputfile << dump_to_csv(a, b, c, d, e) << std::endl;

	SHA1_R3(a, b, c, d, e, 50);
	// std::cout << "Index = 50 " << std::endl << print_abcde_bits(e, a, b, c, d) << std::endl;
	outputfile << dump_to_csv(e, a, b, c, d) << std::endl;

	SHA1_R3(e, a, b, c, d, 51);
	// std::cout << "Index = 51 " << std::endl << print_abcde_bits(d, e, a, b, c) << std::endl;
	outputfile << dump_to_csv(d, e, a, b, c) << std::endl;

	SHA1_R3(d, e, a, b, c, 52);
	// std::cout << "Index = 52 " << std::endl << print_abcde_bits(c, d, e, a, b) << std::endl;
	outputfile << dump_to_csv(c, d, e, a, b) << std::endl;

	SHA1_R3(c, d, e, a, b, 53);
	// std::cout << "Index = 53 " << std::endl << print_abcde_bits(b, c, d, e, a) << std::endl;
	outputfile << dump_to_csv(b, c, d, e, a) << std::endl;

	SHA1_R3(b, c, d, e, a, 54);
	// std::cout << "Index = 54 " << std::endl << print_abcde_bits(a, b, c, d, e) << std::endl;
	outputfile << dump_to_csv(a, b, c, d, e) << std::endl;

	SHA1_R3(a, b, c, d, e, 55);
	// std::cout << "Index = 55 " << std::endl << print_abcde_bits(e, a, b, c, d) << std::endl;
	outputfile << dump_to_csv(e, a, b, c, d) << std::endl;

	SHA1_R3(e, a, b, c, d, 56);
	// std::cout << "Index = 56 " << std::endl << print_abcde_bits(d, e, a, b, c) << std::endl;
	outputfile << dump_to_csv(d, e, a, b, c) << std::endl;

	SHA1_R3(d, e, a, b, c, 57);
	// std::cout << "Index = 57 " << std::endl << print_abcde_bits(c, d, e, a, b) << std::endl;
	outputfile << dump_to_csv(c, d, e, a, b) << std::endl;

	SHA1_R3(c, d, e, a, b, 58);
	// std::cout << "Index = 58 " << std::endl << print_abcde_bits(b, c, d, e, a) << std::endl;
	outputfile << dump_to_csv(b, c, d, e, a) << std::endl;

	SHA1_R3(b, c, d, e, a, 59);
	// std::cout << "Index = 59 " << std::endl << print_abcde_bits(a, b, c, d, e) << std::endl;
	outputfile << dump_to_csv(a, b, c, d, e) << std::endl;

	SHA1_R4(a, b, c, d, e, 60);
	// std::cout << "Index = 60 " << std::endl << print_abcde_bits(e, a, b, c, d) << std::endl;
	outputfile << dump_to_csv(e, a, b, c, d) << std::endl;

	SHA1_R4(e, a, b, c, d, 61);
	// std::cout << "Index = 61 " << std::endl << print_abcde_bits(d, e, a, b, c) << std::endl;
	outputfile << dump_to_csv(d, e, a, b, c) << std::endl;
	
	SHA1_R4(d, e, a, b, c, 62);
	// std::cout << "Index = 62 " << std::endl << print_abcde_bits(c, d, e, a, b) << std::endl;
	outputfile << dump_to_csv(c, d, e, a, b) << std::endl;
	
	SHA1_R4(c, d, e, a, b, 63);
	// std::cout << "Index = 63 " << std::endl << print_abcde_bits(b, c, d, e, a) << std::endl;
	outputfile << dump_to_csv(b, c, d, e, a) << std::endl;
	
	SHA1_R4(b, c, d, e, a, 64);
	// std::cout << "Index = 64 " << std::endl << print_abcde_bits(a, b, c, d, e) << std::endl;
	outputfile << dump_to_csv(a, b, c, d, e) << std::endl;
	
	SHA1_R4(a, b, c, d, e, 65);
	// std::cout << "Index = 65 " << std::endl << print_abcde_bits(e, a, b, c, d) << std::endl;
	outputfile << dump_to_csv(e, a, b, c, d) << std::endl;
	
	SHA1_R4(e, a, b, c, d, 66);
	// std::cout << "Index = 66 " << std::endl << print_abcde_bits(d, e, a, b, c) << std::endl;
	outputfile << dump_to_csv(d, e, a, b, c) << std::endl;
	
	SHA1_R4(d, e, a, b, c, 67);
	// std::cout << "Index = 67" << std::endl << print_abcde_bits(c, d, e, a, b) << std::endl;
	outputfile << dump_to_csv(c, d, e, a, b) << std::endl;
	
	SHA1_R4(c, d, e, a, b, 68);
	// std::cout << "Index = 68" << std::endl << print_abcde_bits(b, c, d, e, a) << std::endl;
	outputfile << dump_to_csv(b, c, d, e, a) << std::endl;
	
	SHA1_R4(b, c, d, e, a, 69);
	// std::cout << "Index = 69" << std::endl << print_abcde_bits(a, b, c, d, e) << std::endl;
	outputfile << dump_to_csv(a, b, c, d, e) << std::endl;
	
	SHA1_R4(a, b, c, d, e, 70);
	// std::cout << "Index = 70 " << std::endl << print_abcde_bits(e, a, b, c, d) << std::endl;
	outputfile << dump_to_csv(e, a, b, c, d) << std::endl;
	
	SHA1_R4(e, a, b, c, d, 71);
	// std::cout << "Index = 71 " << std::endl << print_abcde_bits(d, e, a, b, c) << std::endl;
	outputfile << dump_to_csv(d, e, a, b, c) << std::endl;
	
	SHA1_R4(d, e, a, b, c, 72);
	// std::cout << "Index = 72 " << std::endl << print_abcde_bits(c, d, e, a, b) << std::endl;
	outputfile << dump_to_csv(c, d, e, a, b) << std::endl;
	
	SHA1_R4(c, d, e, a, b, 73);
	// std::cout << "Index = 73 " << std::endl << print_abcde_bits(b, c, d, e, a) << std::endl;
	outputfile << dump_to_csv(b, c, d, e, a) << std::endl;
	
	SHA1_R4(b, c, d, e, a, 74);
	// std::cout << "Index = 74 " << std::endl << print_abcde_bits(a, b, c, d, e) << std::endl;
	outputfile << dump_to_csv(a, b, c, d, e) << std::endl;
	
	SHA1_R4(a, b, c, d, e, 75);
	// std::cout << "Index = 75 " << std::endl << print_abcde_bits(e, a, b, c, d) << std::endl;
	outputfile << dump_to_csv(e, a, b, c, d) << std::endl;
	
	SHA1_R4(e, a, b, c, d, 76);
	// std::cout << "Index = 76 " << std::endl << print_abcde_bits(d, e, a, b, c) << std::endl;
	outputfile << dump_to_csv(d, e, a, b, c) << std::endl;
	
	SHA1_R4(d, e, a, b, c, 77);
	// std::cout << "Index = 77 " << std::endl << print_abcde_bits(c, d, e, a, b) << std::endl;
	outputfile << dump_to_csv(c, d, e, a, b) << std::endl;
	
	SHA1_R4(c, d, e, a, b, 78);
	// std::cout << "Index = 78 " << std::endl << print_abcde_bits(b, c, d, e, a) << std::endl;
	outputfile << dump_to_csv(b, c, d, e, a) << std::endl;
	
	SHA1_R4(b, c, d, e, a, 79);
	// std::cout << "Index = 79 " << std::endl << print_abcde_bits(a, b, c, d, e) << std::endl;
	outputfile << dump_to_csv(a, b, c, d, e) << std::endl;
	

	outputfile << "End of inner loop..." << std::endl;
	


    /* Add the working vars back into digest[] */
	digest[0] += a;
	digest[1] += b;
	digest[2] += c;
	digest[3] += d;
	digest[4] += e;

	std::cout << "End of inner loop..." << std::endl;
	std::cout << print_bits(digest, 5) << std::endl;

	return;
}
