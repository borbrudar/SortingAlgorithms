#include "Main.h"

Main::Main()
{
	sortingAlgorithm = std::make_unique<Bubble>();
	sortingInit();

	window.create(VideoMode(SCR_WIDTH, SCR_HEIGHT), "Sorting Algorithms");

	randomize.init(Vector2f(530, 10), Vector2f(90, 25), "Randomize");
	init();

	std::vector<std::string> pass = names;
	pass.push_back("Algorithms v");
	algSelection.init(6, Vector2f(400, 10), Vector2f(100, 25), pass);

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

	adraw.draw(window);
	drawStrings();
	drawButtons();

	window.display();
}

void Main::update()
{
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) window.close();
		if(event.type == Event::KeyPressed){
			if(event.key.code == Keyboard::Left) delay -= 5, delay = std::max(delay,0);
			if(event.key.code == Keyboard::Right) delay += 5;
		}

		updateAlgorithmSelection();
	}

	if (randomize.isPressed(window, mouse, event)) init();
	adraw.update();
	
	Time time = sf::milliseconds(delay);
	sleep(time);
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
		//sortingAlgorithm = std::make_unique<Quick>();
		break;
	}


	sortingInit();
}


void Main::drawButtons()
{
	randomize.drawButton(window);
	algSelection.drawDropdown(window);
}

void Main::drawStrings()
{
	std::string algName = "Using: " + names[algorithmNumber] + " Sort";
	string.drawString(window, Vector2f(20, 10), algName);

	std::string sleep = "Step delay: " + std::to_string(delay) + " ms";
	string.drawString(window, Vector2f(20, 30), sleep);
}

void Main::updateAlgorithmSelection()
{
	int newAlgorithmNumber = algSelection.updateDropdown(window, mouse, event);
	if (newAlgorithmNumber != -1) {
		algorithmNumber = newAlgorithmNumber;
		init();
	}
}

void Main::sortingInit()
{
	sortingAlgorithm->randomize();
	auto vec = sortingAlgorithm->getVec();
	sortingAlgorithm->sortArray();
	auto swaps = sortingAlgorithm->getSwaps();
	adraw.setup(std::move(vec),std::move(swaps));
}
