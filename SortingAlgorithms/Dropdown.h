#pragma once
#include "Button.h"
#include <vector>

class Dropdown {
public:
	Dropdown() = default;
	void init(int numberOfButtons, Vector2f pos, Vector2f size, std::vector<std::string> names);
	void drawDropdown(RenderWindow&window);
	int updateDropdown(RenderWindow& window, Mouse mouse, Event event);
private:
	void drawClosed(RenderWindow& window);
	void drawOpen(RenderWindow& window);


	bool isDropped = false;
	std::vector<Button> buttons;
	Button cover;
};
