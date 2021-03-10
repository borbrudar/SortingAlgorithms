#include "SortingAlgorithm.h"

std::deque<int> SortingAlgorithm::getColorArray()
{
	return colorArray;
}

int SortingAlgorithm::getMaxColorArraySize()
{
	return maxColorArraySize;
}

void SortingAlgorithm::init(Vector2f screenSize)
{
	SCR_WIDTH = screenSize.x;
	SCR_HEIGHT = screenSize.y;
}

void SortingAlgorithm::drawVector(RenderWindow &window)
{
	RectangleShape rect;

	for (int i = 0; i < vector.size(); i++) {
		rect.setFillColor(chooseLineColor(i));
		Vector2f size = Vector2f((float)SCR_WIDTH / vector.size(), vector[i] * (SCR_HEIGHT * 0.75) / vector.size());

		rect.setSize(size);
		rect.setPosition(i * size.x, SCR_HEIGHT - size.y);
		window.draw(rect);
	}
}

std::string SortingAlgorithm::getAlgorithmName()
{
	return algorithmName;
}

int SortingAlgorithm::getSleepInMiliseconds()
{
	return sleepForInMiliseconds;
}

void SortingAlgorithm::setSleepInMiliseconds(int miliseconds)
{
	if (miliseconds >= 0) sleepForInMiliseconds = miliseconds;
}

void SortingAlgorithm::sortingSlowDown()
{
	sf::Time time = sf::milliseconds(sleepForInMiliseconds);
	sf::sleep(time);
}

void SortingAlgorithm::updateColorArray(int indexToAdd)
{
	colorArray.push_back(indexToAdd);
	if (colorArray.size() >= maxColorArraySize) colorArray.pop_front();
}

Color SortingAlgorithm::chooseLineColor(int arrayValue)
{
	int place = -1;

	for (int i = 0; i < colorArray.size(); i++) {
		if (arrayValue == colorArray[i]) {
			place = i;
			break;
		}
	}


	if (place == -1) return Color::White;
	else if (place == (colorArray.size() - 1)) return Color::Green;
	//choose shades of red depending on place in colorArray
	else {
		float temp = 255 / (place + 1);
		return  Color(255, temp, temp);
	}
}

void SortingAlgorithm::randomizeUnsortedVector()
{
	std::vector<int> sortedArray;
	sortedArray.resize(vectorSize);
	vector.resize(vectorSize);

	std::random_device rd;
	std::default_random_engine engine(rd());

	for (int i = 0; i < sortedArray.size(); i++) sortedArray[i] = i;
	for (int i = 0; i < vector.size(); i++) {
		std::uniform_int_distribution<int> dist(0, sortedArray.size() - 1);
		int randomValueFromSortedArray = dist(engine);

		vector[i] = sortedArray[randomValueFromSortedArray];
		sortedArray.erase(sortedArray.begin() + randomValueFromSortedArray);
	}
}
