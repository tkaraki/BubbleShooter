#include "Ball.h"


Ball::Ball(float radius) : sf::CircleShape(radius){
	this->destroyed = false;
	this->xVel = 0.0f;
	this->yVel = 0.0f;
}
Ball::Ball(float radius, const sf::Color &c, float posX, float posY) : sf::CircleShape(radius)
{
	this->destroyed = false;
	this->setFillColor(c);
	this->setPosition(posX, posY);
	this->xVel = 0.0f;
	this->yVel = 0.0f;
}

bool Ball::isDestroyed() {
	return this->destroyed;
}

void Ball::destroy() {
	this->destroyed = true;
}

void Ball::unDestroy() {
	this->destroyed = false;
}

void Ball::setVelocity(float newXVel, float newYVel) {
	this->xVel = newXVel;
	this->yVel = newYVel;
}

float Ball::getXVel() {
	return this->xVel;
}
float Ball::getYVel() {
	return this->yVel;
}