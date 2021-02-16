#include <SFML/Graphics.hpp>


using namespace sf;

int main() {
	RenderWindow window;
	window.create(VideoMode(640, 480),"Sorting Algortihms");
	Event e;


	while (window.isOpen()) {
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) window.close();
		}

		window.clear(Color(64,64,64));

		window.display();
	}


	return 0;
}