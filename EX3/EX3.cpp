#include <iostream>
#include <vector>

class Monitor {
public:
	std::vector<int> width;
};

class Window {

};

class Control {
	
public:
	void display(std::vector<Monitor> height) {
		for (int i = 0; i < 50; ++i) {
			for (int j = 0; j < 80; ++j) {
				std::cout << height[i].width[j];
			}
		}
	}

	void command() {
		std::string com;
	}
	
};

void initialization(std::vector<Monitor> height) {
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

	return 0;
}