#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <memory>
#include "Button.h"
#include "Dropdown.h"
#include "SortingAlgorithm.h"
#include "Bubble.h"
#include "Selection.h"
#include "Insertion.h"
#include "Cycle.h"
#include "Merge.h"
#include "Quick.h"
#include "StringU.h"
#include "AlgoDraw.h"


using namespace sf;
class Main {
public:
	Main();
	void run();

private:
	void draw();
	void update();
	void init();

	void drawButtons();
	void drawStrings();

	void updateAlgorithmSelection();
	void sortingInit();


	RenderWindow window;
	Event event;
	Mouse mouse;

	StringU string;
	std::unique_ptr<SortingAlgorithm> sortingAlgorithm;

	Button randomize;
	Dropdown algSelection;
	int algorithmNumber = 0,delay = 0;

	AlgoDraw adraw;
};

