#include "StringU.h"

StringU::StringU() 
{
	conf = config::get();
	font.loadFromFile(conf->getUsedFont());

	text.setFont(font);
	text.setCharacterSize(fontSize);
	text.setFillColor(conf->getFontCol());
	text.setOutlineColor(conf->getOutlineCol());
	text.setOutlineThickness(conf->getOutlineThickness());
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

