#include "Game.h"

Game::Game()
{
	window.create(VideoMode(SCR_WIDTH, SCR_HEIGHT), "Sorting Algorithms");
	draw.init(Vector2f(SCR_WIDTH, SCR_HEIGHT));

	randomize.init(Vector2f(530, 10), Vector2f(90, 25), "Randomize");
	gameState.init(algorithmNumber);

	std::vector<std::string> names = { "Bubble","Selection", "Insertion","Cycle", "Merge","Quick",
	"Algorithms v" };
	algSelection.init(6, Vector2f(400, 10), Vector2f(100, 25), names);
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
	algSelection.drawDropdown(window);

	window.display();
}

void Game::updateGame()
{
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) window.close();

		int newAlgorithmNumber = algSelection.updateDropdown(window, mouse, event);
		if (newAlgorithmNumber != -1) {
			algorithmNumber = newAlgorithmNumber;
			gameState.init(algorithmNumber);
		}
	}

	if (randomize.isPressed(window, mouse, event)) gameState.init(algorithmNumber);
	gameState.sortArray();
}



