#include "pch.h"
#include "sha1.h"
#include <fstream>
#include <sstream>

int main(int argc, char *argv[])
{
	std::string message;
	std::string verified;
	std::string hash;

	if (argc > 1) {
		// argc = number of arguments, but 1 is the program itself
		//  and argv[0] is the program name
		std::cout << "Message is from file " << argv[1] << std::endl;
		std::ifstream t(argv[1]);
		std::stringstream buffer;
		buffer << t.rdbuf();
		message = buffer.str();
		std::cout << "Original message = " << message << std::endl;
		hash = sha1(message);
		std::cout << std::endl << "Digest = " << hash << std::endl;
		std::cout << std::endl;
	}



	//message = "This message is exactly fifty-four bytes long. Yep. 54";  //one block
	//std::cout << "Original message = " << message << std::endl;
	//hash = sha1(message);
	//std::cout << "Digest = " << hash << std::endl;
	//verified = "df8a5587664012f025110d86994a14aa106e5da0";
	//if (hash == verified) { std::cout << "Hash verified" << std::endl; }
	//else { std::cout << "Hash incorrect" << std::endl; }
	//std::cout << std::endl;

	//message = "This message is exactly fifty-five bytes long. 55 bytes";  // one block
	//std::cout << "Original message = " << message << std::endl;
	//hash = sha1(message);
	//std::cout << "Digest = " << hash << std::endl;
	//verified = "4a2df2f1cc9a6afb1057ac7d279825d4e5c7e0ea";
	//if (hash == verified) { std::cout << "Hash verified" << std::endl; }
	//else { std::cout << "Hash incorrect" << std::endl; }
	//std::cout << std::endl;

	//message = "This message is precisely fifty-six bytes long. 56 bytes";  // two blocks
	//std::cout << "Original message = " << message << std::endl;
	//hash = sha1(message);
	//std::cout << "Digest = " << hash << std::endl;
	//verified = "02bda46bc5343cb7f68412f59e30f159172c6b7b";
	//if (hash == verified) { std::cout << "Hash verified" << std::endl; }
	//else { std::cout << "Hash incorrect" << std::endl; }
	//std::cout << std::endl;

	message = "This message is precisely sixty-three bytes long. Yep,63 bytes.";  // two blocks
	std::cout << "Original message = " << message << std::endl;
	hash = sha1(message);
	std::cout << "Digest = " << hash << std::endl;
	verified = "c7fbb5cffadb0aa45572d48d70926d6d053f90c0";
	if (hash == verified) { std::cout << "Hash verified" << std::endl; }
	else { std::cout << "Hash incorrect" << std::endl; }
	std::cout << std::endl;

	//message = "This message is precisely sixty-four bytes long. Yep...64 bytes.";  // two blocks
	//std::cout << "Original message = " << message << std::endl;
	//hash = sha1(message);
	//std::cout << "Digest = " << hash << std::endl;
	//verified = "784ad57971323d6fd7f94c6a9a99aa79efdfe0f4";
	//if (hash == verified) { std::cout << "Hash verified" << std::endl; }
	//else { std::cout << "Hash incorrect" << std::endl; }
	//std::cout << std::endl;

	//message = "This message is precisely sixty-five bytes long. Yep....65 bytes.";  // two blocks
	//std::cout << "Original message = " << message << std::endl;
	//hash = sha1(message);
	//std::cout << "Digest = " << hash << std::endl;
	//verified = "955eef6a68df020e5da35689d8d68beea9c9a866";
	//if (hash == verified) { std::cout << "Hash verified" << std::endl; }
	//else { std::cout << "Hash incorrect" << std::endl; }
	//std::cout << std::endl;

	// message = "The quick brown fox jumped over the lazy dog.  Now is the time for all good men to come to the aid of their country.  Jackdaws love my big sphinx of quartz.";  // three blocks
	// std::cout << "Original message = " << message << std::endl;
	// hash = sha1(message);
	// std::cout << "Digest = " << hash << std::endl;
	// verified = "52d2f3843cc09d18166d2cded1469b269df43296";
	// if (hash == verified) { std::cout << "Hash verified" << std::endl; }
	// else { std::cout << "Hash incorrect" << std::endl; }
	// std::cout << std::endl;


	return 0;
}


