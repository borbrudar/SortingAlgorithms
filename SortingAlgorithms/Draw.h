#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include <vector>

class Game;
using namespace sf;
class Draw {
public:
	void init(RenderWindow& window, Vector2f screenSize);
	void drawGameState(RenderWindow& window, GameState& state);
private:
	void drawArray(RenderWindow& window, std::vector<int> array);

	int SCR_WIDTH, SCR_HEIGHT;
};
