#include <iostream>
#include <vector>

class Monitor {
public:
	std::vector<int> width;
};

class Window {

};

class Control {
	void move() {

	}

	void resize() {

	}
	
public:
	void display(std::vector<Monitor>& height) {
		for (int i = 0; i < 50; ++i) {
			for (int j = 0; j < 80; ++j) {
				std::cout << height[i].width[j];
			}
			std::cout << std::endl;
		}
	}

	void command(std::vector<Monitor>& height) {
		std::string com;
		do {
			std::cout << "Command:";
			std::cin >> com;

			if (com == "move") {
				move();
			}
			else if (com == "resize") {
				resize();
			}
			else if (com == "display") {
				display(height);
			}
			else if (com == "close") {
				std::cout << "Window close" << std::endl;
			}
		} while (com != "close");
	}
};

void initialization(std::vector<Monitor>& height) {
	for (int i = 0; i < 50; ++i) {
		height.push_back(Monitor());
		for (int j = 0; j < 80; ++j) {
			height[i].width.push_back(0);
		}
	}
}

int main() {
	std::vector<Monitor> height;
	Control control;

	initialization(height);

	control.display(height);

	std::cout << std::endl;

	control.command(height);

	return 0;
}