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

	std::string getAlgorithmName();

	std::deque<int> getColorArray();
	int getMaxColorArraySize();

	void setSleepInMiliseconds(int miliseconds);
	int getSleepInMiliseconds();

protected:
	void sortingSlowDown();
	void updateColorArray(int indexToAdd);
	Color chooseLineColor(int arrayValue);

	std::vector<int> vector;

	std::deque<int> colorArray;
	int maxColorArraySize = 10;
	int sleepForInMiliseconds = 30;
	std::string algorithmName;

	int SCR_WIDTH, SCR_HEIGHT;
	int vectorSize = 80;
};