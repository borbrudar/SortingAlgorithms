#include "Game.h"

Game::Game()
{
	gameState.init(window, Vector2f(SCR_WIDTH, SCR_HEIGHT));
}

void Game::run()
{
	while (window.isOpen()) {
		update.update(window);
		gameState.drawGameState(window);
		gameState.sortArray();
	}
}
