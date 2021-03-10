#include "Game.h"

Game::Game()
{
	window.create(VideoMode(SCR_WIDTH, SCR_HEIGHT), "Sorting Algorithms");
	draw.init(Vector2f(SCR_WIDTH, SCR_HEIGHT));

	randomize.init(Vector2f(530, 10), Vector2f(90, 25), "Randomize");
	init();

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

	draw.drawVector(window, unsortedArray, sortingAlgorithm->getColorArray());
	drawStrings();
	drawButtons();

	window.display();
}

void Game::updateGame()
{
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) window.close();
		if (event.type == Event::KeyPressed) updateStepDelay();

		updateAlgorithmSelection();
	}

	if (randomize.isPressed(window, mouse, event)) init();
	sortArray();
}

void Game::init()
{
	randomizeUnsortedArray();

	switch (algorithmNumber) {
	case 0:
		sortingAlgorithm = std::make_unique<Bubble>();
		break;
	case 1:
		sortingAlgorithm = std::make_unique<Selection>();
		break;
	case 2:
		sortingAlgorithm = std::make_unique<Insertion>();
		break;
	case 3:
		sortingAlgorithm = std::make_unique<Cycle>();
		break;
	case 4:
		sortingAlgorithm = std::make_unique<Merge>();
		break;
	case 5:
		sortingAlgorithm = std::make_unique<Quick>();
		break;
	}

	sortingAlgorithm->setSleepInMiliseconds(stepDelay);
}

void Game::sortArray()
{
	sortingAlgorithm->sortArray(unsortedArray);
}

void Game::randomizeUnsortedArray()
{
	std::vector<int> sortedArray;
	sortedArray.resize(arraySize);
	unsortedArray.resize(arraySize);

	std::random_device rd;
	std::default_random_engine engine(rd());

	for (int i = 0; i < sortedArray.size(); i++) sortedArray[i] = i;
	for (int i = 0; i < unsortedArray.size(); i++) {
		std::uniform_int_distribution<int> dist(0, sortedArray.size() - 1);
		int randomValueFromSortedArray = dist(engine);

		unsortedArray[i] = sortedArray[randomValueFromSortedArray];
		sortedArray.erase(sortedArray.begin() + randomValueFromSortedArray);
	}
}

void Game::drawButtons()
{
	randomize.drawButton(window);
	algSelection.drawDropdown(window);
}

void Game::drawStrings()
{
	std::string algName = "Using: " + sortingAlgorithm->getAlgorithmName() + " Sort";
	draw.drawString(window, Vector2f(20, 10), algName);

	std::string sleep = "Step delay: " + std::to_string(
		sortingAlgorithm->getSleepInMiliseconds()) + " ms";
	draw.drawString(window, Vector2f(20, 30), sleep);
}

void Game::updateStepDelay()
{
	float currentSleep = sortingAlgorithm->getSleepInMiliseconds();

	if (event.key.code == Keyboard::Left) stepDelay -= 5;
	if (event.key.code == Keyboard::Right) stepDelay += 5;

	sortingAlgorithm->setSleepInMiliseconds(stepDelay);
	stepDelay = sortingAlgorithm->getSleepInMiliseconds();
}

void Game::updateAlgorithmSelection()
{
	int newAlgorithmNumber = algSelection.updateDropdown(window, mouse, event);
	if (newAlgorithmNumber != -1) {
		algorithmNumber = newAlgorithmNumber;
		init();
	}
}
