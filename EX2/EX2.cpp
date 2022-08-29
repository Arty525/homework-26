#include <iostream>
#include <fstream>
#include <string>

class Contact {
	std::string number;
	std::string name;
};

class Phone {
	std::fstream phoneBook;
	std::string command;
	std::string input;

	void add() {
		std::cout << "Enter phone number: ";
		do {
			std::cin >> input;
			if (input[0] != '+' || input[1] != '7' || input.length() != 10) {
				std::cout << "Invalid number format." << std::endl;
			}
		} while (input[0] != '+' || input[1] != '7' || input.length() != 10);

	}
};