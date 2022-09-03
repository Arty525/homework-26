#include <iostream>
#include <fstream>
#include <string>

class Data {
public:
	std::string number;
	std::string name;
};

class Phone {
	Data contact;
	std::fstream phoneBook;
	std::string command;
	std::string inNumber;
	std::string inName;

	void search() {
		phoneBook.open("phonebook.txt", std::ios::in);
		if (phoneBook.is_open()) {
			while (!phoneBook.eof()) {
				phoneBook >> contact.number >> contact.name;
				if (inNumber == contact.number) {
					std::cout << contact.number << " " << contact.name << std::endl;
					break;
				}
				else if (inName == contact.name) {
					do {
						std::cout << "This name is already recorded with number " << contact.number << std::endl;
						std::cout << "Chose another name:";
						std::getline(std::cin, inName);
					} while (inName == contact.name);
					std::cin.clear();
					break;
				}
			}
		}
		std::cin.clear();
		phoneBook.close();
	}

	void sms() {
		std::string text;
		if (contact.number.empty()) {
			std::cout << "Enter number: ";
			std::cin >> inNumber;
		}
		search();
		std::cout << "SMS to ";
		if (!contact.name.empty()) {
			std::cout << contact.name << std::endl;
		}
		else {
			std::cout << inNumber << std::endl;
		}
		std::cout << "Text: ";
		std::getline(std::cin >> std::ws, text);
		std::cout << "SMS sent." << std::endl;
		contact.number.clear();
		contact.name.clear();
	}

	void call() {
		if (contact.number.empty()) {
			std::cout << "Enter number: ";
			std::cin >> inNumber;
		}
		search();
		std::cout << "Call to ";
		if (!contact.name.empty()) {
			std::cout << contact.name << std::endl;
		}
		else {
			std::cout << inNumber << std::endl;
		}
		std::cout << "Call ended." << std::endl;
		contact.number.clear();
		contact.name.clear();
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
		search();
		phoneBook.open("phonebook.txt", std::ios::app);
		phoneBook << inNumber << " " << inName << std::endl;
		phoneBook.close();
		contact.number.clear();
		contact.name.clear();
	}

	void list() {
		phoneBook.open("phonebook.txt", std::ios::in);
		std::string line;
		if (phoneBook.is_open()) {
			while (!phoneBook.eof()) {
				std::getline(phoneBook, line);
				std::cout << line << std::endl;
			}
		}
	}

public:
	void com() {
		do {
			std::cout << "Command: ";
			std::cin >> command;
			if (command == "add") {
				add();
			}
			else if (command == "call") {
				call();
			}
			else if (command == "sms") {
				sms();
			}
			else if (command == "list") {
				list();
			}
		} while (command != "exit");
	}
};

int main() {
	Phone phone;
	phone.com();
}