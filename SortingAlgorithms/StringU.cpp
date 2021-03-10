#include "StringU.h"

StringU::StringU()
{
}

void StringU::drawString(RenderWindow& window, Vector2f pos, std::string message)
{
	text.setPosition(pos);
	text.setString(message);
	window.draw(text);
}
