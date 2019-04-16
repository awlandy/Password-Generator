//#include "pch.h"
#include <iostream>
#include <random> // for std::mt19937
#include <ctime> // for std::time
#include <cctype> // for std::isdigit
#include <iterator> // for std::size
#include <cstring> // for strcpy, strcat and strlen

char zerotonine[] = "0123456789";
const unsigned char option0 = 0x1; // hex for 0000 0001

char capAtoZ[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const unsigned char option1 = 0x2; // hex for 0000 0010

char lowerAtoZ[] = "abcdefghijklmnopqrstuvwxyz";
const unsigned char option2 = 0x4; // hex for 0000 0100

char specialChar[] = "!\"#$%&\'()*+,-./:;<=>\?@[\\]^_`{|}~";
const unsigned char option3 = 0x8; // hex for 0000 1000

int pwLength = 0;
char charset[] = "";

void askforPWlength() {	//ask user for password length for interact()
	char buffer[4] = "";
	std::cout << "What is the length of the password that you want? Enter a <integer number>.\n";
	std::cin >> buffer;
	pwLength = std::atoi(buffer);
	std::cout << "The entered length is " << pwLength << ".\n";
}

int getyn(){
	while (true)
	{
		char yn;
		std::cin >> yn;
		
		// Check user input
		if (yn == 'y' || yn == 'n')
			return yn;
		else
			std::cout << "Oops, that input is invalid.  Please try again.\n";
	} // and try again
}

int interact() {
	unsigned char options = 0x0; // hex for 0000 0000
	char yn = 'a';
	{	// 0-9 string (zerotonine)
		std::cout << "Do you want numbers in the password? Enter <y/n>.\n";
		yn = getyn();

		if (yn = 'y')
			options |= option0;
		char yn = 'a';
	}
	{	// A-Z string (capAtoZ)
		std::cout << "Do you want capital letters in the password? Enter <y/n>.\n";
		yn = getyn();

		if (yn = 'y')
			options |= option1;
		char yn = 'a';
	}
	{	// a-z string (lowerAtoZ)
		std::cout << "Do you want lower letters in the password? Enter <y/n>.\n";
		yn = getyn();

		if (yn = 'y')
			options |= option2;
		char yn = 'a';
	}
	{	// special characters string (specialChar)
		std::cout << "Do you want special characters in the password? Enter <y/n>.\n";
		yn = getyn();

		if (yn = 'y')
			options |= option3;
	}
	return options;
}

//void command(int argc, char *argv) {

//}

int poccessOptions(int options) {
	int len = sizeof zerotonine + sizeof capAtoZ + sizeof lowerAtoZ + sizeof specialChar;
	if (options & option0)
		strcat_s(charset, len, zerotonine);
	if (options & option1)
		strcat_s(charset, len, capAtoZ);
	if (options & option2)
		strcat_s(charset, len, lowerAtoZ);
	if (options & option3)
		strcat_s(charset, len, specialChar);
	return strlen(charset);
}



int main(int argc, char *argv[])
{
	//if (argc < 2)

	unsigned int result = interact(); // get charset options return

	//else
	//	command(argc, *argv);
	//if (pwLength == 0)

	askforPWlength(); // get desired password length from user

	srand(time(NULL)); // seed with time since epoch

	int charsetlength = poccessOptions(result);  // get array length for randomGenerater()::max
	for (int index = 0; index < pwLength; ++index) {
		auto random_number = (rand() % (charsetlength + 1)); // get a pseudo-random integer between 1 and 9
		std::cout << charset[random_number];
	}
	std::cout << "\n";
	return 0;
}
