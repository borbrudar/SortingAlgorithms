#include "Draw.h"
#include "Game.h"

void Draw::init(RenderWindow& window, Vector2f screenSize)
{
	SCR_WIDTH = screenSize.x;
	SCR_HEIGHT = screenSize.y;
	window.create(VideoMode(screenSize.x, screenSize.y), "Sorting Algorithms");
}

void Draw::drawGameState(RenderWindow& window, GameState &state)
{
	Color backgroundColor = Color(64, 64, 64);

	window.clear(backgroundColor);
	drawArray(window, state.getUnsortedArray());
	window.display();
}

void Draw::drawArray(RenderWindow& window, std::vector<int> array)
{
	RectangleShape rect;
	rect.setFillColor(Color::White);

	for (int i = 0; i < array.size();i++) {
		rect.setSize(Vector2f(SCR_WIDTH / array.size(), array[i] * SCR_HEIGHT / array.size()));
		rect.setPosition(i * (SCR_WIDTH / array.size()), SCR_HEIGHT - (array[i] * SCR_HEIGHT / array.size()));
		window.draw(rect);
	}
}
