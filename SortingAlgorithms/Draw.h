#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include <vector>

using namespace sf;
class Draw {
public:
	void init(Vector2f screenSize);
	void drawArray(RenderWindow& window, GameState& state);
	void drawString(RenderWindow& window, Vector2f pos, std::string message);
private:
	Color chooseLineColor(int array, GameState& state);
	int SCR_WIDTH, SCR_HEIGHT;
	Font arial;
	Text text;
};

