#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(605, 505), "SFML works!");
	window.setFramerateLimit(75);

	Texture t1,t2;
	t1.loadFromFile("ogre.png");
	t2.loadFromFile("medieval.png");
	Sprite enemy(t1), sbackground(t2);
	enemy.setOrigin(200, 100);
	enemy.setTextureRect(IntRect(0, 0, 107.5, 145));
	int location_x = 200, location_y = 200;
	int counter = 0;
	while (window.isOpen() && !Keyboard::isKeyPressed(Keyboard::Escape))
	{
		counter++;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(Color::White);
		window.draw(sbackground);
		window.draw(enemy);
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			enemy.setTextureRect(IntRect(counter / 10 % 4 * 107.5, 145, 107.5, 145));
			enemy.move(-1.0f, 0.0f);
			location_x--;

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			enemy.setTextureRect(IntRect(counter / 10 % 4 * 107.5, 2 * 145, 107.5, 145));
			enemy.move(1.0f, 0.0f);
			location_x++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			enemy.setTextureRect(IntRect(counter / 10 % 4 * 107.5, 3 * 145, 107.5, 145));
			enemy.move(0.0f, -1.0f);
			location_y--;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			enemy.setTextureRect(IntRect(counter / 10 % 4 * 107.5, 0, 107.5, 145));
			enemy.move(0.0f, 1.0f);
			location_y++;
		}
		
		if (location_x >= 693) { location_x--; }
		if (location_x < 200) { location_x++; }
		if (location_y >= 456){location_y--;}
		if (location_y < 100) { location_y++; }
		printf("x: %d\n", location_x);
		printf("y: %d\n", location_y);
		enemy.setPosition(location_x, location_y);
	}

	return 0;
}