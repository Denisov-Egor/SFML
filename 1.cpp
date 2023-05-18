#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(640, 480), L"Отскоки");

	CircleShape ball(20.f);
	ball.setFillColor(Color::Red);
	ball.setOrigin(20, 20);

	float x = 50;
	float y = 150;
	float x_speed = 0.1f;
	float y_speed = 0.1f;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		x += x_speed;
		y += y_speed;
		if (x < 0 + ball.getRadius() || window.getSize().x - ball.getRadius() < x)
		{
			x_speed *= -1;
		}

		if (y < 0 + ball.getRadius() || window.getSize().y - ball.getRadius() < y)
		{
			y_speed *= -1;
		}

		ball.setPosition(x, y);

		window.clear(Color::White);
		window.draw(ball);
		window.display();
	}
	return 0;
}
