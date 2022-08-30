﻿#include <iostream>
#include <fstream>
#include <string>

class Data {
public:
	std::string number;
	std::string name;
};

class Phone {
public:
	Data contact;
	std::fstream phoneBook;
	std::string command;
	std::string inNumber;
	std::string inName;

	void sms() {

	}

	void call() {

	}

	void add() {
		std::cout << "Enter phone number: ";
		do {
			std::cin >> inNumber;
			if (inNumber[0] != '+' || inNumber[1] != '7' || inNumber.length() != 12) {
				std::cout << "Invalid number format." << std::endl;
			}
		} while (inNumber[0] != '+' || inNumber[1] != '7' || inNumber.length() != 12);
		std::cin.clear();
		std::cout << "Enter contact name: ";
		std::getline(std::cin >> std::ws, inName);
		phoneBook.open("phonebook.txt", std::ios::in);
		if (phoneBook.is_open()) {
			std::string line;
			while (!phoneBook.eof()) {
				phoneBook >> contact.number >> contact.name;
				std::cout << contact.number << " | " << contact.name << std::endl;
				if (inNumber == contact.number) {
					
					std::cout << "This number is already recorded under the name " << contact.name << std::endl;
					std::cout << "Call this contact or send sms?" << std::endl;
					do {
						std::cin >> command;
						if (command == "sms") {
							sms();
						}
						else if (command == "call") {
							call();
						}
						else if (command == "exit") {
							break;
						}
						else {
							std::cout << "Uncknown command" << std::endl;
						}
					} while (command != "sms" || command != "call");
					break;
				}
				else if (inName == contact.name) {
					do {
						std::cout << "This name is already recorded with number " << contact.number << std::endl;
						std::cout << "Coose another name:";
						std::getline(std::cin, inName);
					} while (inName == contact.name);
					std::cin.clear();
					break;
				}
			}
		}
		std::cin.clear();
		phoneBook.close();
		phoneBook.open("phonebook.txt", std::ios::app);
		phoneBook << inNumber << " " << inName << std::endl;		
	}
};

int main() {
	Phone phone;
	do {
		std::cout << "Command: ";
		std::cin >> phone.command;
		if (phone.command == "add") {
			phone.add();
		}
		else if (phone.command == "call") {
			phone.call();
		}
		else if (phone.command == "sms") {
			phone.sms();
		}
	} while (phone.command != "exit");
}