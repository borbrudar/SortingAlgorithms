#include "StringU.h"
#include "config.h"

StringU::StringU() 
{
	font.loadFromFile(usedFont);

	text.setFont(font);
	text.setCharacterSize(fontSize);
	text.setFillColor(fontInner);
	text.setOutlineColor(outlineColor);
	text.setOutlineThickness(outlineThickness);
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

