#pragma once
#include <SFML/Graphics.hpp>
#include "Draw.h"
#include "Update.h"

using namespace sf;
class Game {
public:
	Game();
	void run();

	const int SCR_WIDTH = 512, SCR_HEIGHT = SCR_WIDTH / 4 * 3;
private:
	void drawGame();

	Draw draw;
	Update update;
	RenderWindow window;
	GameState gameState;
};

