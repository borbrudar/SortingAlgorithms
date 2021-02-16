#include "Update.h"

void Update::update(RenderWindow &window)
{
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) window.close();
	}
}
