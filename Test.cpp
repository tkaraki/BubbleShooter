#include "Test.h"

void Test::testAddScore() {
	score scores;
	scores.addScore("100");
	scores.addScore("200");
	scores.addScore("50");
	scores.addScore("75");
	scores.printScores();
}

void Test::testExportScores() {
	score scores;
	scores.addScore("100");
	scores.addScore("50");
	scores.addScore("75");
	scores.addScore("200");
	scores.exportScore();
}

void Test::testImportScores() {
	score scores;
	scores.importScore();
	scores.printScores();
}

void Test::testCollision() {
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Clickie Boi");
	window.setPosition(sf::Vector2i(560, 0));

	Ball ammo(25.f);
	ammo.setOrigin(ammo.getRadius(), ammo.getRadius());

	ammo.setPosition(window.getSize().x / 2, window.getSize().y);

	ammo.setFillColor(Grid::samples[0]);

	ammo.setVelocity(0, -1.f);

	Grid grid(4);

	while (window.isOpen() && ammo.getYVel() < -0.1f)
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		grid.drawGrid(window);
		window.draw(ammo);
		window.display();

		grid.collideAmmo(ammo, window);

	}
	system("pause");
	if (window.isOpen()) window.close();
}

void Test::testFire() {

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Clickie Boi");
	window.setPosition(sf::Vector2i(560, 0));

	Ball ammo(25.f);
	ammo.setOrigin(ammo.getRadius(), ammo.getRadius());

	ammo.setPosition(window.getSize().x / 2, window.getSize().y);

	ammo.setFillColor(Grid::samples[0]);

	GameWrapper g;

	Cannon shootyBoi(*(new sf::Vector2f(-50, -150)), sf::Color::Cyan,
		*(new sf::Vector2f(window.getSize().x / 2, window.getSize().y)));
	shootyBoi.setOrigin(-25, 0);

	sf::CircleShape cannonStand(80.f);
	cannonStand.setFillColor(sf::Color::Cyan);
	cannonStand.setPosition(sf::Vector2f(window.getSize().x / 2 - cannonStand.getRadius(), window.getSize().y - cannonStand.getRadius()));

	shootyBoi.rotate(30.f);

	g.fireAmmo(ammo, shootyBoi);

	while (window.isOpen() && ammo.getYVel() < -0.1f)
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(cannonStand);
		window.draw(shootyBoi);
		window.draw(ammo);
		ammo.move(ammo.getXVel(), ammo.getYVel());
		window.display();

	}
	system("pause");
	if (window.isOpen()) window.close();
}
