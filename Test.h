#ifndef TEST_H
#define TEST_H
#pragma once
#include "Scores.h"
#include "Grid.h"
#include "GameWrapper.h"

class Test {
public:
	static void testAddScore();
	static void testExportScores();
	static void testImportScores();
	static void testCollision();
	static void testFire();
};

#endif