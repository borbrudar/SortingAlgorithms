#include "Main.h"

Main::Main()
{
	window.create(VideoMode(SCR_WIDTH, SCR_HEIGHT), "Sorting Algorithms");

	randomize.init(Vector2f(530, 10), Vector2f(90, 25), "Randomize");
	init();

	std::vector<std::string> names = { "Bubble","Selection", "Insertion","Cycle", "Merge","Quick",
	"Algorithms v" };
	algSelection.init(6, Vector2f(400, 10), Vector2f(100, 25), names);

}

void Main::run()
{
	while (window.isOpen()) {
		update();
		draw();
	}
}

void Main::draw()
{
	Color backgroundColor = Color(64, 64, 64);
	window.clear(backgroundColor);

	drawStrings();
	drawButtons();

	window.display();
}

void Main::update()
{
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) window.close();
		updateAlgorithmSelection();
	}

	if (randomize.isPressed(window, mouse, event)) init();

	sortingAlgorithm->sortArray();
}

void Main::init()
{
	int prevStepDelay;
	bool isPrevDelay;
	sortingAlgorithm ? isPrevDelay = true : isPrevDelay = false;


	switch (algorithmNumber) {
	case 0:
		sortingAlgorithm = std::make_unique<Bubble>();
		break;
	case 1:
		//sortingAlgorithm = std::make_unique<Selection>();
		break;
	case 2:
		//sortingAlgorithm = std::make_unique<Insertion>();
		break;
	case 3:
		//sortingAlgorithm = std::make_unique<Cycle>();
		break;
	case 4:
		//sortingAlgorithm = std::make_unique<Merge>();
		break;
	case 5:
		//sortingAlgorithm = std::make_unique<Quick>();
		break;
	}

	sortingAlgorithm->randomize();
}


void Main::drawButtons()
{
	randomize.drawButton(window);
	algSelection.drawDropdown(window);
}

void Main::drawStrings()
{
	/*std::string algName = "Using: " + sortingAlgorithm->getAlgorithmName() + " Sort";
	string.drawString(window, Vector2f(20, 10), algName);

	std::string sleep = "Step delay: " + std::to_string(
		sortingAlgorithm->getStepDelay()) + " ms";
	string.drawString(window, Vector2f(20, 30), sleep);
	*/
}

void Main::updateAlgorithmSelection()
{
	int newAlgorithmNumber = algSelection.updateDropdown(window, mouse, event);
	if (newAlgorithmNumber != -1) {
		algorithmNumber = newAlgorithmNumber;
		init();
	}
}
