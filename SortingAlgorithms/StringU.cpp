#include "StringU.h"

StringU::StringU() 
{
	font.loadFromFile("font/arial.ttf");

	text.setFont(font);
	text.setCharacterSize(16);
	text.setFillColor(Color::White);
	text.setOutlineColor(Color::Black);
	text.setOutlineThickness(1.5f);
}


void StringU::drawString(RenderWindow& window, Vector2f pos, std::string message)
{
	text.setPosition(pos);
	text.setString(message);
	window.draw(text);
}

void StringU::drawString(RenderWindow& window)
{
	window.draw(text);
}

void StringU::setPosition(Vector2f pos)
{
	text.setPosition(pos);
}

void StringU::setMessage(std::string message)
{
	text.setString(message);
}

