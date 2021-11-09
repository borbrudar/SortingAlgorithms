#pragma once
#include <vector>
#include <deque>
#include <SFML/Graphics.hpp>
#include <random>

using namespace sf;
class SortingAlgorithm {
public:
	virtual void sortArray() = 0;
	void init(Vector2f screenSize);
	void drawVector(RenderWindow &window);
	void randomizeUnsortedVector();
	void updateStepDelay(Event event);

	std::string getAlgorithmName();

	std::deque<int> getColorArray();
	int getMaxColorArraySize();
	
	int getStepDelay();
	void setStepDelay(int newStepDelay);
	void sleep();
private:
	Color chooseLineColor(int arrayValue);

protected:
	void updateColorArray(int indexToAdd);
	std::vector<int> vector;

	std::deque<int> colorArray;
	int maxColorArraySize = 10;
	std::string algorithmName;

	int SCR_WIDTH, SCR_HEIGHT;
private:
	int vectorSize = 80;
	
	int stepDelay = 0;
};