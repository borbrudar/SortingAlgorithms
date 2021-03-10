#include "Draw.h"

void Draw::init(Vector2f screenSize)
{
	SCR_WIDTH = screenSize.x;
	SCR_HEIGHT = screenSize.y;
}


void Draw::drawVector(RenderWindow& window, std::vector<int> vector, std::deque<int> colorVector)
{
	RectangleShape rect;

	for (int i = 0; i < vector.size();i++) {
		rect.setFillColor(chooseLineColor(i,colorVector));
		Vector2f size = Vector2f((float)SCR_WIDTH / vector.size(), vector[i] * (SCR_HEIGHT * 0.75) / vector.size());
		
		rect.setSize(size);
		rect.setPosition(i * size.x, SCR_HEIGHT - size.y);
		window.draw(rect);
	}
}

Color Draw::chooseLineColor(int arrayValue,std::deque<int> colorVector)
{
	int place = -1;

	for (int i = 0; i < colorVector.size(); i++) {
		if (arrayValue == colorVector[i]) {
			place = i;
			break;
		}
	}


	if (place == -1) return Color::White;
	else if (place == (colorVector.size() - 1)) return Color::Green;
	//choose shades of red depending on place in colorArray
	else {
		float temp = 255 / (place + 1);
		return  Color(255, temp, temp);
	}
}
