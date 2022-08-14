#include <iostream>
#include <ctime>
#include <fstream>
#include <map>
#include <iomanip>
#include <string>

class Track {
public:
	std::string name;
	std::time_t duration = std::time(nullptr);
	std::time_t date = std::time(nullptr);
	std::tm* b = std::localtime(&date);
};

class Player {
	Track file;
	std::fstream list;
	std::string status = "stop";

public:

	std::map <int, Track> trackList;

	void getList() {
		std::string line;
		list.open("list.txt");
		for (int i = 1; !list.eof(); ++i) {
			list >> file.duration >> std::get_time(file.b, "%d.%m.%Y");
			std::getline(list, file.name);
			trackList.insert(std::pair<int, Track>(i, file));
		}
		list.close();
	}

	void showList() {
		for (std::map<int, Track>::iterator it = trackList.begin(); it != trackList.end(); ++it) {
			std::cout << it->first << it->second.name << " " << it->second.duration / 60 << ":" << it->second.duration - ((it->second.duration / 60) * 60) << " " << std::put_time(it->second.b, "%d.%m.%Y") << std::endl;
		}
	}

	void play() {
		if (status == "stop") {
			std::string line;
			list.open("list.txt");
			do {
				if (line != "|") {
					list >> line;
					file.name += line;
				}
			} while (line != "|");
			list >> file.duration >> file.date;
			std::cout << "now pyaling: " << file.name << file.duration << file.date<< std::endl;
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
	void next() {

	}
};

int main() {
	Player* player = new Player();
	player->getList();
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
	else if (command == "next") {

	}
	else if (command == "list") {
		player->showList();
	}
	delete player;
	player = nullptr;
	return 0;
}