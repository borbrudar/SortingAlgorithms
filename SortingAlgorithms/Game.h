#pragma once
#include <SFML/Graphics.hpp>
#include "Draw.h"
#include "GameState.h"
#include "Button.h"
#include "Dropdown.h"

using namespace sf;
class Game {
public:
	Game();
	void run();

	const int SCR_WIDTH = 640, SCR_HEIGHT = SCR_WIDTH / 4 * 3;
private:
	void drawGame();
	void updateGame();

	RenderWindow window;
	Event event;
	Mouse mouse;

	Draw draw;
	GameState gameState;

	Button randomize;
	Dropdown algSelection;
	int algorithmNumber = 0;
};

