#include "Draw.h"
#include "Game.h"

void Draw::init(Vector2f screenSize)
{
	SCR_WIDTH = screenSize.x;
	SCR_HEIGHT = screenSize.y;

	arial.loadFromFile("font/arial.ttf");

	text.setFont(arial);
	text.setCharacterSize(16);
	text.setFillColor(Color::White);
	text.setOutlineColor(Color::Black);
	text.setOutlineThickness(1.5f);
}

void Draw::drawString(RenderWindow& window, Vector2f pos, std::string message)
{
	text.setPosition(pos);
	text.setString(message);
	window.draw(text);
}

void Draw::drawArray(RenderWindow& window, GameState &state)
{
	std::vector<int> array = state.getUnsortedArray();
	RectangleShape rect;

	for (int i = 0; i < array.size();i++) {
		rect.setFillColor(chooseLineColor(i,state));
		rect.setSize(Vector2f(SCR_WIDTH / array.size(), array[i] * SCR_HEIGHT / array.size()));
		rect.setPosition(i * (SCR_WIDTH / array.size()), SCR_HEIGHT - (array[i] * SCR_HEIGHT / array.size()));
		window.draw(rect);
	}
}

Color Draw::chooseLineColor(int arrayValue, GameState &state)
{
	std::deque<int> tempColorVector = state.getSortingAlgorithm()->getColorArray();
	int place = -1;

	for (int i = 0; i < tempColorVector.size(); i++) {
		if (arrayValue == tempColorVector[i]) {
			place = i;
			break;
		}
	}


	if (place == -1) return Color::White;
	else if (place == (tempColorVector.size() - 1)) return Color::Green;
	//choose shades of red depending on place colorArray
	else {
		float temp = 255 / (place + 1);
		return  Color(255, temp, temp);
	}
}
