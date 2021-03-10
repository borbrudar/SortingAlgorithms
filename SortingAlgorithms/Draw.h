#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <deque>

using namespace sf;
class Draw {
public:
	void init(Vector2f screenSize);
	void drawVector(RenderWindow& window, std::vector<int> vector, std::deque<int> colorVector);
private:
	Color chooseLineColor(int array, std::deque<int> colorVector);
	int SCR_WIDTH, SCR_HEIGHT;
};

