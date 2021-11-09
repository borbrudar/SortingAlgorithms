#include "SortingAlgorithm.h"

std::deque<int> SortingAlgorithm::getColorArray()
{
	return colorArray;
}

int SortingAlgorithm::getMaxColorArraySize()
{
	return maxColorArraySize;
}

int SortingAlgorithm::getStepDelay()
{
	return stepDelay;
}

void SortingAlgorithm::setStepDelay(int newStepDelay)
{
	if (newStepDelay < 0) return;
	stepDelay = newStepDelay;
}

void SortingAlgorithm::sleep()
{
	sf::Time time = sf::milliseconds(stepDelay);
	sf::sleep(time);
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

void SortingAlgorithm::updateStepDelay(Event event)
{
	if (!(event.type == Event::KeyPressed)) return;

	if (event.key.code == Keyboard::Left) stepDelay -= 5;
	if (event.key.code == Keyboard::Right) stepDelay += 5;

	if (stepDelay < 0) stepDelay = 0;
}
