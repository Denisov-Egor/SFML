#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(640, 480), "SFML window");

	CircleShape ball(20.f);
	ball.setFillColor(Color::Red);
	ball.setPosition(100.f, 100.f);

	Vector2f velocity(0.1f, 0.1f);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		ball.move(velocity);

		if (ball.getPosition().x + ball.getRadius() > window.getSize().x ||
			ball.getPosition().x - ball.getRadius() < 0)
			velocity.x = -velocity.x;
		if (ball.getPosition().y + ball.getRadius() > window.getSize().y ||
			ball.getPosition().y - ball.getRadius() < 0)
			velocity.y = -velocity.y;

		window.clear();
		window.draw(ball);
		window.display();
	}
	return 0;
}