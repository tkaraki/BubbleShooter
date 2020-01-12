#ifndef SCORES_H
#define SCORES_H
#pragma once

#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::fstream;
using std::cout;
#include "List.h"

class score
{
public:
	score();
	~score();

	void importScore();
	void exportScore();
	void addScore(string score);
	void printScores();
	
private:

	ScoreList highScore;

};

#endif