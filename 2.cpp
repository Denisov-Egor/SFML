#include <SFML/Graphics.hpp>
#include <cstdlib> // для rand и srand
#include <ctime> // для time

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML window");

	srand(time(NULL));

	sf::RectangleShape block;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (rand() % 100 == 1)
		{
			int blockSize = rand() % 100 + 50;
			int xPos = rand() % (window.getSize().x - blockSize);

			block.setSize(sf::Vector2f(blockSize, blockSize));
			block.setPosition(xPos, 0);
			block.setFillColor(sf::Color::Green);
		}

		block.move(0, 1);

		window.clear();
		window.draw(block);
		window.display();
	}

	return 0;
}