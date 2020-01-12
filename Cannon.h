#ifndef CANNON_H
#define CANNON_H
#pragma once
#include <SFML/Graphics.hpp>

class Cannon : public sf::RectangleShape
{
private:
	double rotation1; 
	double rotation2;

public:
	Cannon(sf::Vector2f &size, const sf::Color &myColor,
		sf::Vector2f &pos);

	void rotateCannon();
};


#endif