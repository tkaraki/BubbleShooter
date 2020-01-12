#include "Grid.h"

sf::Color Grid::samples[] = { sf::Color::Yellow, sf::Color::Red, sf::Color::Blue,
										  sf::Color::Green, sf::Color::Magenta, sf::Color::White };

Grid::Grid(int colors) {

	this->bBonk.loadFromFile("bonk.wav");
	this->sBonk.setBuffer(this->bBonk);

	this->bPop.loadFromFile("Balloon_Pop.wav");
	this->sPop.setBuffer(bPop);

	this->rows = ((WINDOW_HEIGHT - (4 * WINDOW_BORDER)) / 100);
	this->columns = (WINDOW_WIDTH - (2 * WINDOW_BORDER)) / 50;

	this->poppedBalls = 0;

	int k = 0;

	int j = 0;
	while (j < 2 * this->rows) 
	{
		std::vector<Ball> newVector;
		
		for (int i = 0; i < this->columns; i++)
		{

			k = rand() % colors;

			Ball newBall(25.f, Grid::samples[k], (i * 50) + (WINDOW_BORDER)+25, (j * 50) + (3 * WINDOW_BORDER) + 25);
			newBall.setOrigin(newBall.getRadius(), newBall.getRadius());
			if (j >= this->rows) newBall.destroy(); // set destroyed flag so that balls below the row count are not drawn
			newVector.push_back(newBall);
			
		}
		this->arr.push_back(newVector);
		j++;

	}

}
Grid::~Grid() {
	if (false) {
		int imSoBoredLol = 0;
	}
}

// displays all of the balls in the grid that are not destroyed
void Grid::drawGrid(sf::RenderWindow & window) {
	for (int i = 0; i < 2 * this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			if (!this->arr[i][j].isDestroyed()) {
				window.draw(this->arr[i][j]);
			}
		}
	}
}

// controls all collision detection in the game
void Grid::collideAmmo(Ball & ammo, sf::RenderWindow & window) {
	ammo.move(ammo.getXVel(), ammo.getYVel());
	if ((ammo.getPosition().x < WINDOW_BORDER + ammo.getRadius() && ammo.getXVel() < 0) // ammo is touching the left side of the screen
		|| ammo.getPosition().x > window.getSize().x - (WINDOW_BORDER + ammo.getRadius()) && ammo.getXVel() > 0) { // ammo is touching the right side 
		ammo.setVelocity(-ammo.getXVel(), ammo.getYVel()); // switch sign of x velocity
		this->sBonk.play();
	}

	for (int i = 0; i < 2 * this->rows; i++) {

		for (int j = 0; j < this->columns; j++) {

			if (!this->arr[i][j].isDestroyed()) {

				float distance = sqrtf(powf((ammo.getPosition().x - arr[i][j].getPosition().x),2) +
					powf((ammo.getPosition().y - arr[i][j].getPosition().y), 2)); // distance between centers of ammo and i,j ball in grid

				if (distance < ammo.getRadius() + arr[i][j].getRadius()) { // ammo has collided with current ball
					ammo.setVelocity(0, 0); // stop the ball
				
					float closestDistance = 1000.0; // arbitrary number that should be larger than any calculated distances
					int closestRow = i, closestColumn = j;
					float nextDistance;
					if (i < 2 * rows - 1 && arr[i + 1][j].isDestroyed()) { // slot below current ball is available
						nextDistance = sqrtf(powf((ammo.getPosition().x - arr[i + 1][j].getPosition().x), 2) +
							powf((ammo.getPosition().y - arr[i + 1][j].getPosition().y), 2));
						if (closestDistance > nextDistance) { // slot below current ball is closest 
							closestDistance = nextDistance;
							closestRow = i + 1;
							closestColumn = j;
						}
					}
					if (j > 0 && arr[i][j - 1].isDestroyed()) { // slot left of current ball is available
						nextDistance = sqrtf(powf((ammo.getPosition().x - arr[i][j - 1].getPosition().x), 2) +
							powf((ammo.getPosition().y - arr[i][j - 1].getPosition().y), 2));
						if (closestDistance > nextDistance) { // slot left of current ball is closest 
							closestDistance = nextDistance;
							closestRow = i;
							closestColumn = j - 1;
						}
					}
					if (j < columns - 1 && arr[i][j + 1].isDestroyed()) { // slot right of current ball is available
						nextDistance = sqrtf(powf((ammo.getPosition().x - arr[i][j + 1].getPosition().x), 2) +
							powf((ammo.getPosition().y - arr[i][j + 1].getPosition().y), 2));
						if (closestDistance > nextDistance) { // slot right of current ball is closest 
							closestDistance = nextDistance;
							closestRow = i;
							closestColumn = j + 1;
						}
					}

					ammo.setPosition(this->arr[closestRow][closestColumn].getPosition());
					if (this->arr[i][j].getFillColor() == ammo.getFillColor() && this->destroyCluster(i, j)) {
						ammo.destroy();
					}
					else {
						this->arr[closestRow][closestColumn] = ammo;
						ammo.destroy();
					}
				}

			}

		} // end inner for loop
	} // end outer for loop
}

// destroys a cluster of balls if there are enough of the same color, returns true if it succesfully destroys a cluster
// requires the row and column of the position to start destroying from, given position cannot be destroyed already
bool Grid::destroyCluster(int row, int column) {
	sf::Color targetColor = this->arr[row][column].getFillColor();
	
	// if cluster contains at least 2 balls of the same color, ammo will make it 3 so destroy that cluster
	if ((row > 0 && !arr[row - 1][column].isDestroyed() && arr[row - 1][column].getFillColor() == targetColor)
		|| (row < 2 * this->rows - 1 && !arr[row + 1][column].isDestroyed() && arr[row + 1][column].getFillColor() == targetColor)
		|| (column > 0 && !arr[row][column - 1].isDestroyed() && arr[row][column - 1].getFillColor() == targetColor)
		|| (column < this->columns - 1 && !arr[row][column + 1].isDestroyed() && arr[row][column + 1].getFillColor() == targetColor)) {

		this->destroyCluster(row, column, targetColor);
		this->sPop.play();

		return true;
	}
	return false;
}

// recursively destroys all balls in a cluster
void Grid::destroyCluster(int row, int column, sf::Color & targetColor) {
	if (row < 0) return;
	if (row >= 2 * this->rows) return;
	if (column < 0) return;
	if (column >= this->columns) return;
	if (this->arr[row][column].isDestroyed()) return;
	if (this->arr[row][column].getFillColor() != targetColor) return;
	// if function is still going after these if statements then current ball is part of the cluster

	this->arr[row][column].destroy();
	this->destroyCluster(row, column + 1, targetColor);
	this->destroyCluster(row, column - 1, targetColor);
	this->destroyCluster(row + 1, column, targetColor);
	this->destroyCluster(row - 1, column, targetColor);
	this->poppedBalls++;
}

int Grid::getPoppedBalls() {
	return this->poppedBalls;
}