#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <deque>

using namespace sf;
class Draw {
public:
	void init(Vector2f screenSize);
	void drawArray(RenderWindow& window, std::vector<int> array, std::deque<int> colorVector);
	void drawString(RenderWindow& window, Vector2f pos, std::string message);
private:
	Color chooseLineColor(int array, std::deque<int> colorVector);
	int SCR_WIDTH, SCR_HEIGHT;
	Font arial;
	Text text;
};

