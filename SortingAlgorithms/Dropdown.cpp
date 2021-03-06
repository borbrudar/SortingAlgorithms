#include "Dropdown.h"

void Dropdown::init(int numberOfButtons,Vector2f pos, Vector2f size, std::vector<std::string> names)
{
	if (numberOfButtons != (names.size() - 1)) return;
	buttons.resize(numberOfButtons);

	for (int i = 0; i < numberOfButtons;  i++) buttons[i].init(pos, size, names[i]);
	cover.init(pos, size, names[names.size() - 1]);
}

void Dropdown::drawDropdown(RenderWindow& window)
{
	if (!isDropped) drawClosed(window);
	else drawOpen(window);
}

void Dropdown::drawClosed(RenderWindow& window)
{
	cover.drawButton(window);
}

void Dropdown::drawOpen(RenderWindow& window)
{
}
