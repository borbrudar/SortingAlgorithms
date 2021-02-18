#include "Game.h"

Game::Game()
{
	draw.init(window, Vector2f(SCR_WIDTH, SCR_HEIGHT));
}

void Game::run()
{
	while (window.isOpen()) {
		update.update(window);
		draw.drawGameState(window,gameState);
		gameState.sortArray();
	}
}
