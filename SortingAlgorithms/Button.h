#pragma once
#include <SFML/Graphics.hpp>
#include "StringU.h"

using namespace sf;

class Button {
public:
	void init(Vector2f pos, Vector2f size, std::string buttonMessage);
	void drawButton(RenderWindow& window);
	bool isPressed(RenderWindow &window, Mouse mouse, Event event);
private:
	RectangleShape buttonRect;
	StringU buttonText;
};

