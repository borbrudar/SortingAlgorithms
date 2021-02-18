#include "Game.h"

Game::Game()
{
	window.create(VideoMode(SCR_WIDTH, SCR_HEIGHT), "Sorting Algorithms");
	draw.init(Vector2f(SCR_WIDTH, SCR_HEIGHT));
}

void Game::run()
{
	while (window.isOpen()) {
		update.update(window);
		drawGame();
		gameState.sortArray();
	}
}

void Game::drawGame()
{
	Color backgroundColor = Color(64, 64, 64);
	window.clear(backgroundColor);

	draw.drawArray(window, gameState);

	window.display();
}



