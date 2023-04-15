#include "Dropdown.h"

void Dropdown::init(int numberOfButtons,Vector2f pos, Vector2f size, std::vector<std::string> names)
{
	if (numberOfButtons != (names.size() - 1)) return;
	buttons.resize(numberOfButtons);

	for (int i = 0; i < numberOfButtons;  i++) buttons[i].init(Vector2f(pos.x, pos.y + size.y* i), size, names[i]);
	cover.init(pos, size, names.back());
}

void Dropdown::drawDropdown(RenderWindow& window)
{
	if (!isDropped) drawClosed(window);
	else drawOpen(window);
}

int Dropdown::updateDropdown(RenderWindow& window, Mouse mouse, Event event)
{
	if (!isDropped && cover.isPressed(window, mouse, event)) {
		isDropped = true;
		return -1;
	}
	else {
		for (int i = 0; i < buttons.size(); i++) {
			if (buttons[i].isPressed(window, mouse, event)) {
				isDropped = false;
				return i;
			}
		}

		if (mouse.isButtonPressed(Mouse::Left)) isDropped = false;
	}

	return -1;
}

void Dropdown::drawClosed(RenderWindow& window)
{
	cover.drawButton(window);
}

void Dropdown::drawOpen(RenderWindow& window)
{
	for (int i = 0; i < buttons.size(); i++) buttons[i].drawButton(window);
}
