/*
CPTS 122 PA 9

Authors: Christopher Nathman, Tala Karaki, Erik Handeland, Nick Enriquez

*/


#include "GameWrapper.h"
#include "Test.h"


int main(int argc, char *argv[])
{
	//Test::testAddScore();
	//Test::testExportScores();
	//Test::testImportScores();
	//Test::testCollision();
	//Test::testFire();
	srand(time(NULL));

	GameWrapper g;
	g.runApp();
	return 0;
	
}
