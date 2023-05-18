#include <SFML/Graphics.hpp>
#include <cstdlib> 
#include <ctime> 

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(640, 480), "SFML window");

	srand(time(NULL));

	RectangleShape block;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (rand() % 200 == 1)
		{
			int blockSize = rand() % 100 + 50;
			int xPos = rand() % (window.getSize().x - blockSize);

			block.setSize(Vector2f(blockSize, blockSize));
			block.setPosition(xPos, 0);
			block.setFillColor(Color::Green);
		}

		block.move(0, 5);

		window.clear();
		window.draw(block);
		window.display();
	}
	return 0;
}
