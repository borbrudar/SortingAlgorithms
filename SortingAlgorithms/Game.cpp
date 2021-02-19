#include "Game.h"

Game::Game()
{
	window.create(VideoMode(SCR_WIDTH, SCR_HEIGHT), "Sorting Algorithms");
	draw.init(Vector2f(SCR_WIDTH, SCR_HEIGHT));

	randomize.init(Vector2f(380, 10), Vector2f(90, 25), "Randomize");
}

void Game::run()
{
	while (window.isOpen()) {
		updateGame();
		drawGame();
	}
}

void Game::drawGame()
{
	Color backgroundColor = Color(64, 64, 64);
	window.clear(backgroundColor);

	draw.drawArray(window, gameState);
	std::string algName = "Using: " + gameState.getSortingAlgorithm()->getAlgorithmName() + " Sort";
	draw.drawString(window, Vector2f(20, 10), algName);

	randomize.drawButton(window);

	window.display();
}

void Game::updateGame()
{
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) window.close();
	}

	if (randomize.isPressed(window, mouse)) gameState.init();
	gameState.sortArray();
}



