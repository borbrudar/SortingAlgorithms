#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class StringU {
public:
	StringU();
	void drawString(RenderWindow &window, Vector2f pos, std::string message);
private:	
	Font arial;
	Text text;
};