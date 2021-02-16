#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Update {
public:
	Update() = default;
	void update(RenderWindow& window);
private:
	Event event;
};