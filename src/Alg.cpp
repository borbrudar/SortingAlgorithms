#include "Alg.h"
#include <cassert>
#include <chrono>

Alg::Alg()
{
	conf = config::get();
	sortingAlgorithm = std::make_unique<Bubble>();
	sortingInit();

	window.create(VideoMode(SCR_WIDTH, SCR_HEIGHT), "Sorting Algorithms", Style::Titlebar | Style::Close);

	randomize.init(Vector2f(SCR_WIDTH-100-10, 10), Vector2f(100, 25), "Randomize");
	init();

	std::vector<std::string> pass = names;
	pass.push_back("Algorithms v");
	algSelection.init(6, Vector2f(SCR_WIDTH-2*100 - 20, 10), Vector2f(100, 25), pass);

	sloader.loadStyle("styles/style0.conf");
}

void Alg::run()
{
	while (window.isOpen()) {
		update();
		draw();
	}
}

void Alg::draw()
{
	window.clear(conf->getBackgroundCol());

	adraw.draw(window);
	drawStrings();
	drawButtons();

	window.display();
}

void Alg::update()
{
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) window.close();
		if(event.type == Event::KeyPressed){
			//inc/dec delay and/or vector size 
			if(event.key.code == Keyboard::Left) delay -= dStep, delay = std::max(delay,0);
			if(event.key.code == Keyboard::Right) delay += dStep;
			if(event.key.code == Keyboard::Up){
				if(vectorSize != maxVectorSize) vectorSize += dSize, sortingInit();
			}	
			if(event.key.code == Keyboard::Down){
				if(vectorSize != minVectorSize) vectorSize -= dSize, sortingInit();
			}

			//cycle through styles
			if(event.key.code == Keyboard::N) {
				curStyle++;
				std::string path = stylesDir + "style" + std::to_string(curStyle) + ".conf";
				if(!sloader.loadStyle(path)) {
					curStyle = 0;
					path = stylesDir + "style" + std::to_string(curStyle) + ".conf";
					sloader.loadStyle(path);
				}
				randomize.setStyle();
				algSelection.setStyle();
				string.setStyle();
			}

			//randomize with r
			if(event.type == Event::KeyPressed && event.key.code == Keyboard::R) init();
		}

		updateAlgorithmSelection();
	}

	if (randomize.isPressed(window, mouse, event)) init();

	if(clock.getElapsedTime().asMilliseconds() >= delay){
		adraw.update();
		clock.restart();
	}
}

void Alg::init()
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
		sortingAlgorithm = std::make_unique<Quick>();
		break;
	}


	sortingInit();
}


void Alg::drawButtons()
{
	randomize.drawButton(window);
	algSelection.drawDropdown(window);
}

void Alg::drawStrings()
{
	std::string algName = "Using: " + names[algorithmNumber] + " Sort";
	string.drawString(window, Vector2f(20, 10), algName);

	std::string sleep = "Step delay: " + std::to_string(delay) + " ms";
	string.drawString(window, Vector2f(20, 30), sleep);

	std::string siz = "Array size is " + std::to_string(vectorSize);
	string.drawString(window, Vector2f(20, 50), siz);
	
	std::string write = "Buffer writes: " + std::to_string(writes);
	string.drawString(window, Vector2f(20, 70), write);

	std::string time = "Execution time: " + std::to_string(etime) + " microseconds";
	string.drawString(window, Vector2f(20, 90), time);

	std::string style = "Current style: " + conf->getStyleName();
	string.drawString(window, Vector2f(20, 110), style);
}

void Alg::updateAlgorithmSelection()
{
	int newAlgorithmNumber = algSelection.updateDropdown(window, mouse, event);
	if (newAlgorithmNumber != -1) {
		algorithmNumber = newAlgorithmNumber;
		init();
	}
}

void Alg::sortingInit()
{
	sortingAlgorithm->randomize(vectorSize);
	auto vec = sortingAlgorithm->getVec();


	auto start = std::chrono::high_resolution_clock::now();	
	sortingAlgorithm->sortArray();
	auto stop = std::chrono::high_resolution_clock::now();
	etime = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();

	//assert(sortingAlgorithm->verify());

	auto swaps = sortingAlgorithm->getSwaps();
	writes = swaps.size();
	adraw.setup(std::move(vec),std::move(swaps));
}
