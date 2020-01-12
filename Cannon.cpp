#include "Cannon.h"

Cannon::Cannon(sf::Vector2f &size, const sf::Color &myColor,
	sf::Vector2f &pos) : sf::RectangleShape(size)
{
	this->setFillColor(myColor);
	this->setPosition(pos);

	this->rotation1 = 0.0;
	this->rotation2 = 0.0;
}

// controls the cannon rotation
void Cannon::rotateCannon() {
	if (rotation1 <= 75)
	{
		rotation1 += .06;
		this->rotate(.06);
		if (rotation1 >= 75)
		{
			rotation2 = 75;
		}
	}
	else if (rotation2 >= -75)
	{
		rotation2 -= .06;
		this->rotate(-.06);
		if (rotation2 <= -75)
		{
			rotation1 = -75;
		}
	}
}