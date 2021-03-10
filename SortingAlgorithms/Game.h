#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <memory>
#include "Draw.h"
#include "Button.h"
#include "Dropdown.h"
#include "SortingAlgorithm.h"
#include "Bubble.h"
#include "Selection.h"
#include "Insertion.h"
#include "Cycle.h"
#include "Merge.h"
#include "Quick.h"

using namespace sf;
class Game {
public:
	Game();
	void run();

	const int SCR_WIDTH = 640, SCR_HEIGHT = SCR_WIDTH / 4 * 3;
private:
	void drawGame();
	void updateGame();
	void init();

	void sortArray();
	void randomizeUnsortedArray();

	void drawButtons();
	void drawStrings();

	void updateStepDelay();
	void updateAlgorithmSelection();

	RenderWindow window;
	Event event;
	Mouse mouse;

	Draw draw;
	std::vector<int> unsortedArray;
	std::unique_ptr<SortingAlgorithm> sortingAlgorithm;

	Button randomize;
	Dropdown algSelection;
	int algorithmNumber = 0;

	int stepDelay = 0;
	int arraySize = 80;
};

