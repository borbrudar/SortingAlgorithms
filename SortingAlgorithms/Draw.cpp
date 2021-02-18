#include "Draw.h"
#include "Game.h"

void Draw::init(RenderWindow& window, Vector2f screenSize)
{
	SCR_WIDTH = screenSize.x;
	SCR_HEIGHT = screenSize.y;
	window.create(VideoMode(screenSize.x, screenSize.y), "Sorting Algorithms");

	font.loadFromFile("res/font/arial.ttf");
}

void Draw::drawString(RenderWindow &window, Vector2f pos, std::string message)
{
	Text text;
	text.setFont(font);
	text.setString(message);
	text.setFillColor(Color::White);
	text.setOutlineColor(Color::Black);
	text.setOutlineThickness(2.f);
	text.setPosition(pos);

	window.draw(text);
	
}


void Draw::drawArray(RenderWindow& window, std::vector<int> &array, std::deque<int> tempColorVector)
{
	RectangleShape rect;

	for (int i = 0; i < array.size();i++) {
		rect.setFillColor(chooseLineColor(i,tempColorVector));
		rect.setSize(Vector2f(SCR_WIDTH / array.size(), array[i] * SCR_HEIGHT / array.size()));
		rect.setPosition(i * (SCR_WIDTH / array.size()), SCR_HEIGHT - (array[i] * SCR_HEIGHT / array.size()));
		window.draw(rect);
	}
}

Color Draw::chooseLineColor(int arrayValue, std::deque<int> tempColorVector)
{
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
