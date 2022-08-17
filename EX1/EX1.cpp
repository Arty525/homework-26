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
	int pos = 1;

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
			std::cout << "Input number of track: ";
			std::cin >> pos;
			std::cout << "now pyaling:" << trackList[pos].name << " " << trackList[pos].duration / 60 << ":" << trackList[pos].duration - (trackList[pos].duration / 60 * 60) << std::endl;
			status = "play";
		}
		else if (status == "pause") {
			status = "play";
			std::cout << "now pyaling:" << trackList[pos].name << " " << trackList[pos].duration / 60 << ":" << trackList[pos].duration - (trackList[pos].duration / 60 * 60) << std::endl;
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
			pos = 1;
		}
	}
	void next() {
		int nextPos;
		nextPos == trackList.size() - (rand() % trackList.size() - 1);
		if (nextPos == pos) {
			if()
		}
		status = "pause";
		play();
	}
};

int main() {
	Player* player = new Player();
	player->getList();
	player->showList();
	std::string command;
	do {
		std::cout << "Enter command: ";
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
			player->next();
		}
	} while (command != "exit");
	delete player;
	player = nullptr;
	return 0;
}