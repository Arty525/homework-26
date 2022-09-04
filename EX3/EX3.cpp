#include <iostream>
#include <vector>

class Monitor {
public:
	std::vector<int> width;
};

class Window {
public:
	int width;
	int height;
	int posx;
	int posy;
};

class Control {
public:
	void build(std::vector<Monitor>& height, Window& window) {
		for (int i = 0; i < 50; ++i) {
			height.push_back(Monitor());
			for (int j = 0; j < 80; ++j) {
				if (i >= window.posy && i < window.posy + window.height && j >= window.posx && j < window.posx + window.width) {
					height[i].width[j] = 1;
				}
				else {
					height[i].width[j] = 0;
				}
			}
		}
	}

private:
	void move(std::vector<Monitor>& height, Window& window) {
		do {
			std::cout << "Input new position. x: ";
			std::cin >> window.posx;
			std::cout << "y: ";
			std::cin >> window.posy;
			if (window.posx < 0 || window.posx > 79 || window.posy < 0 || window.posy > 49 || window.posx + window.width > 80 || window.posy + window.height > 50) {
				std::cerr << "Invalid incorrect!" << std::endl;
			}
		} while (window.posx < 0 || window.posx > 79 || window.posy < 0 || window.posy > 49 || window.posx + window.width > 80 || window.posy + window.height > 50);
		build(height, window);
	}

	void resize(std::vector<Monitor>& height, Window& window) {
		do {
			std::cout << "Input new size. Width: ";
			std::cin >> window.width;
			std::cout << "height: ";
			std::cin >> window.height;
			if (window.posx + window.width > 80 || window.posy + window.height > 80 || window.width <= 0 || window.height <= 0) {
				std::cerr << "Incorrect size!" << std::endl;
			}
		} while (window.posx + window.width > 80 || window.posy + window.height > 80 || window.width <= 0 || window.height <= 0);
		build(height, window);
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

	void command(std::vector<Monitor>& height, Window& window) {
		std::string com;
		do {
			std::cout << "Command:";
			std::cin >> com;

			if (com == "move") {
				move(height, window);
			}
			else if (com == "resize") {
				resize(height, window);
			}
			else if (com == "display") {
				display(height);
			}
			else if (com == "close") {
				std::cout << "Window close" << std::endl;
			}
			else {
				std::cout << "Unknown command!" << std::endl;
			}
		} while (com != "close");
	}
};



int main() {
	std::vector<Monitor> height;
	Control control;
	Window window;
	window.height = 10;
	window.width = 10;
	window.posx = 33;
	window.posy = 18;

	height.resize(50);
	for (int i = 0; i < 50; ++i) {
		height[i].width.resize(80);
	}

	control.build(height, window);

	control.display(height);

	std::cout << "Current size: " << window.width << "x" << window.height << std::endl;
	std::cout << "Current position: (" << window.posx << ":" << window.posy << ")" << std::endl;

	control.command(height, window);

	return 0;
}