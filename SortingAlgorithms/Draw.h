#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <memory>

using namespace sf;
class Draw {
public:
	void init(RenderWindow& window, Vector2f screenSize);
	void drawString(RenderWindow& window, Vector2f pos, std::string message);
	void drawArray(RenderWindow& window, std::vector<int> &array, std::deque<int> tempColorVector);
private:
	Color chooseLineColor(int array, std::deque<int> tempColorVector);

	int SCR_WIDTH, SCR_HEIGHT;
	Font font;
};
