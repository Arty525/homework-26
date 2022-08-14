#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>

class Track {
public:
	std::string name;
	std::time_t duration;
	std::time_t date;
};

class Player {
	Track file;
	std::fstream list;
	std::string status = "stop";
	int pos;
public:
	void showList() {
		std::string line;
		list.open("list.txt");
		while (!list.eof()) {
			std::getline(list, line);
			std::cout << line << std::endl;
		}
		list.close();
	}

	void play() {
		if (status == "stop") {
			std::string line;
			list.open("list.txt");
			//list >> pos >> file.name >> file.duration >> file.date;
			//Распарсить строку на подстроки
			std::cout << "now pyaling: " << file.name << std::endl;
			status = "play";
		}
		else if (status == "pause") {
			status = "play";
			std::cout << "now playing: " << file.name << std::endl;
		}
	}

	void pause() {
		if (status == "play") {
			status = "pause";
			std::cout << "Pause" << std::endl;
		}
	}

	void stop() {
		if (status != "stop") {
			status = "stop";
			std::cout << "Stop" << std::endl;
		}
	}
};

int main() {
	Player* player = new Player();
	std::string command;
	std::cin >> command;
	if (command == "play") {
		player->play();
	}
	else if (command == "pause") {
		player->pause();
	}
	else if (command == "stop") {
		player->stop();
	}
	else if (command == "list") {
		player->showList();
	}
	delete player;
	player = nullptr;
	return 0;
}