#ifndef GAMEWRAPPER_H
#define GAMEWRAPPER_H
#pragma once
#include "Cannon.h"
#include "Scores.h"
#include <SFML/Window.hpp>
#include "Grid.h"

enum MenuOptions { Play = 1, Instructions = 2, Difficulty = 3, Highscores = 4, Exit = 5};

class GameWrapper {
private:
	score scores;
	int difficulty; //4 easy 5 mid 6 hard | score modifers *1, *1.5 *2
	int scorePerBall; 

	void resetAmmo(Ball & ammo, int windowXSize, int windowYSize);

public:
	GameWrapper();
	~GameWrapper();

	void runApp();
	void playGame(sf::RenderWindow & window);
	void printInstructions();
	void setDifficulty();
	int getMenuOption(int min, int max);
	void fireAmmo(Ball & ammo, Cannon & kanone);
};

#endif