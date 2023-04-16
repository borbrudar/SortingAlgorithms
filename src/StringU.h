#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "config.h"

using namespace sf;

class StringU {
public:
	StringU();
	void drawString(RenderWindow& window, Vector2f pos, std::string message);
	void drawString(RenderWindow& window);

	void setPosition(Vector2f pos);
	void setMessage(std::string message);
private:
	Font font;
	Text text;
	config *conf;
};