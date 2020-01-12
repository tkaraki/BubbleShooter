#include "GameWrapper.h"

GameWrapper::GameWrapper() {
	if (false) {
		int wellHelloThere;
	}
}
GameWrapper::~GameWrapper() {
}

void GameWrapper::runApp() {

	this->scores.importScore();
	this->difficulty = 4;
	this->scorePerBall = 2;

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Clickie Boi");
	window.setPosition(sf::Vector2i(560, 0));

	//Buttons 
	sf::Texture exitButton;
	sf::Sprite exitButtonImage;
	if (!exitButton.loadFromFile("Exit.png"))
		std::cout << "Can't find the image" << std::endl;
	exitButtonImage.setPosition(((WINDOW_WIDTH / 2) - (exitButton.getSize().x / 2)), (WINDOW_HEIGHT / 7) * 5);

	float exitButtonWidth = exitButton.getSize().x;
	float exitButtonHeight = exitButton.getSize().y;

	exitButtonImage.setTexture(exitButton);

	sf::Texture playButton;
	sf::Sprite playButtonImage;
	if (!playButton.loadFromFile("Play.png"))
		std::cout << "Can't find the image" << std::endl;
	playButtonImage.setPosition(((WINDOW_WIDTH / 2) - (playButton.getSize().x / 2)), (WINDOW_HEIGHT / 7));

	float playButtonWidth = playButton.getSize().x;
	float playButtonHeight = playButton.getSize().y;

	playButtonImage.setTexture(playButton);


	sf::Texture instructionsButton;
	sf::Sprite instructionsButtonImage;
	if (!instructionsButton.loadFromFile("Instructions.png"))
		std::cout << "Can't find the image" << std::endl;
	instructionsButtonImage.setPosition(((WINDOW_WIDTH / 2) - (instructionsButton.getSize().x / 2)), (WINDOW_HEIGHT / 7) * 2);

	float InstructionsButtonWidth = instructionsButton.getSize().x;
	float InstructionsButtonHeight = instructionsButton.getSize().y;

	instructionsButtonImage.setTexture(instructionsButton);

	sf::Texture difficultyButton;
	sf::Sprite difficultyButtonImage;
	if (!difficultyButton.loadFromFile("Difficulty.png"))
		std::cout << "Can't find the image" << std::endl;
	difficultyButtonImage.setPosition(((WINDOW_WIDTH / 2) - (difficultyButton.getSize().x / 2)), (WINDOW_HEIGHT / 7) * 3);

	float difficultyButtonWidth = difficultyButton.getSize().x;
	float difficultyButtonHeight = difficultyButton.getSize().y;

	difficultyButtonImage.setTexture(difficultyButton);

	sf::Texture scoresButton;
	sf::Sprite scoresButtonImage;
	if (!scoresButton.loadFromFile("Scores.png"))
		std::cout << "Can't find the image" << std::endl;
	scoresButtonImage.setPosition(((WINDOW_WIDTH / 2) - (scoresButton.getSize().x / 2)), (WINDOW_HEIGHT / 7) * 4);

	float scoresButtonWidth = scoresButton.getSize().x;
	float scoresButtonHeight = scoresButton.getSize().y;

	scoresButtonImage.setTexture(scoresButton);



	sf::Texture background;
	background.loadFromFile("background.png");
	sf::Sprite backgroundpic;
	sf::Vector2u size = background.getSize();
	backgroundpic.setTexture(background);

	float ScaleX = (float)((float)WINDOW_WIDTH / (float)size.x);
	float ScaleY = (float)((float)WINDOW_HEIGHT / (float)size.y);     //Calculate scale.

	backgroundpic.setScale(ScaleX, ScaleY);

	backgroundpic.setPosition(0, 0);

	bool exit = false;

	while (!exit) {

		while (window.isOpen())
		{
			sf::Event Event;
			while (window.pollEvent(Event))
			{

				switch (Event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseMoved:
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

					//play
					if (playButtonImage.getGlobalBounds().contains(mousePosF))
					{
						playButtonImage.setColor(sf::Color(20, 20, 250));
					}
					else
					{
						playButtonImage.setColor(sf::Color(255, 255, 255));
					}

					//instructions
					if (instructionsButtonImage.getGlobalBounds().contains(mousePosF))
					{
						instructionsButtonImage.setColor(sf::Color(20, 20, 250));
					}
					else
					{
						instructionsButtonImage.setColor(sf::Color(255, 255, 255));
					}

					//difficulty
					if (difficultyButtonImage.getGlobalBounds().contains(mousePosF))
					{
						difficultyButtonImage.setColor(sf::Color(20, 20, 250));
					}
					else
					{
						difficultyButtonImage.setColor(sf::Color(255, 255, 255));
					}


					//scores
					if (scoresButtonImage.getGlobalBounds().contains(mousePosF))
					{
						scoresButtonImage.setColor(sf::Color(20, 20, 250));
					}
					else
					{
						scoresButtonImage.setColor(sf::Color(255, 255, 255));
					}


					//exit
					if (exitButtonImage.getGlobalBounds().contains(mousePosF))
					{
						exitButtonImage.setColor(sf::Color(250, 20, 20));
					}
					else
					{
						exitButtonImage.setColor(sf::Color(255, 255, 255));
					}
				}
				break;
				case sf::Event::MouseButtonPressed:
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));


					if (playButtonImage.getGlobalBounds().contains(mousePosF))
					{
						std::cout << "Playing Game" << std::endl;
						this->playGame(window);
						break;
					}

					if (instructionsButtonImage.getGlobalBounds().contains(mousePosF))
					{
						system("cls");
						this->printInstructions();
						system("pause");
						break;
					}

					if (difficultyButtonImage.getGlobalBounds().contains(mousePosF))
					{
						system("cls");
						this->setDifficulty();
						break;
					}

					if (scoresButtonImage.getGlobalBounds().contains(mousePosF))
					{
						system("cls");
						this->scores.printScores();
						system("pause");
						break;
					}

					if (exitButtonImage.getGlobalBounds().contains(mousePosF))
					{
						std::cout << "Exited Game" << std::endl;
						exit = true;
						window.close();
						break;
					}

				}
				break;
				}

			}

			window.clear();

			window.draw(backgroundpic);
			window.draw(exitButtonImage);
			window.draw(playButtonImage);
			window.draw(scoresButtonImage);
			window.draw(difficultyButtonImage);
			window.draw(instructionsButtonImage);


			window.display();

		}
	}

	this->scores.exportScore();

}

void GameWrapper::playGame(sf::RenderWindow & window) {

	int currentScore = 0;
	int shotsRemaining = 30;

	// game window

	sf::RectangleShape borderLeft;
	borderLeft.setSize(sf::Vector2f(WINDOW_BORDER, WINDOW_HEIGHT - (4 * WINDOW_BORDER)));
	borderLeft.setFillColor(sf::Color(0, 0, 127, 225));
	borderLeft.setPosition(0, (WINDOW_BORDER * 3));

	sf::RectangleShape borderRight;
	borderRight.setSize(sf::Vector2f(WINDOW_BORDER, WINDOW_HEIGHT - (4 * WINDOW_BORDER)));
	borderRight.setFillColor(sf::Color(0, 0, 127, 225));
	borderRight.setPosition((WINDOW_WIDTH - WINDOW_BORDER), (WINDOW_BORDER * 3));

	sf::RectangleShape borderTop;
	borderTop.setSize(sf::Vector2f(WINDOW_WIDTH, 3 * WINDOW_BORDER));
	borderTop.setFillColor(sf::Color(0, 0, 127, 225));
	borderTop.setPosition(0, 0);

	sf::RectangleShape borderBottom;
	borderBottom.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_BORDER));
	borderBottom.setFillColor(sf::Color(0, 0, 127, 225));
	borderBottom.setPosition(0, (WINDOW_HEIGHT - WINDOW_BORDER));

	// moving part of the cannon
	Cannon shootyBoi(*(new sf::Vector2f(-50, -150)), sf::Color::Cyan,
		*(new sf::Vector2f(window.getSize().x/2, window.getSize().y)));
	shootyBoi.setOrigin(-25, 0);

	// decorative cannon base
	sf::CircleShape cannonStand(80.f);
	cannonStand.setFillColor(sf::Color::Cyan);
	cannonStand.setPosition(sf::Vector2f(window.getSize().x / 2 - cannonStand.getRadius(), window.getSize().y-cannonStand.getRadius()));
	
	// ball that gets fired
	Ball ammo(25.f);
	ammo.setOrigin(ammo.getRadius(), ammo.getRadius());
	this->resetAmmo(ammo, window.getSize().x, window.getSize().y);
	bool ammoFired = false; // flag for if game should look for user input

	// grid of all balls in play except ammo
	Grid grid(difficulty);

	//Sound files
	sf::SoundBuffer bAppears, bFire, bLose, bWin;
	bAppears.loadFromFile("Appears.wav");
	bFire.loadFromFile("Cannon_Fire.wav");
	bLose.loadFromFile("LoseSound.wav");
	bWin.loadFromFile("win_sound.wav");
	sf::Sound sAppears, sFire, sLose, sWin;
	sAppears.setBuffer(bAppears);
	sFire.setBuffer(bFire);
	sLose.setBuffer(bLose);
	sWin.setBuffer(bWin);

	sf::Font font;
	if (!font.loadFromFile("ariblk.ttf"))
	{
		std::cout << "Error Loading Font from file" << std::endl;
	}

	sf::Text currScore, remainingShots;

	// set the string to display
	currScore.setFont(font);
	currScore.setString("Current Score: " + std::to_string(currentScore));
	currScore.setCharacterSize(25);
	currScore.setFillColor(sf::Color::Yellow);
	//currScore.setStyle(sf::Text::Bold);
	currScore.setPosition(sf::Vector2f(10, 10));

	remainingShots.setFont(font);
	remainingShots.setString("Shots Remaining: " + std::to_string(shotsRemaining));
	remainingShots.setCharacterSize(25);
	remainingShots.setFillColor(sf::Color::Yellow);
	remainingShots.setPosition(sf::Vector2f(500, 10));

	bool returnToMenu = false;
	while (!returnToMenu && shotsRemaining > 0)
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				returnToMenu;
		}

		sf::Event event2;
		// waiting for user to fire
		if (!ammoFired) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				this->fireAmmo(ammo, shootyBoi);
				ammoFired = true;
				sFire.play();
			}
		}
		// ammo hit the grid so need to reset
		else if(ammo.isDestroyed()){
			this->resetAmmo(ammo, window.getSize().x, window.getSize().y);
			shotsRemaining--; // shots is decremented here so loop does not exit before final shot completes
			ammoFired = false;
		}
		// check position of ammo for collisions and update score
		else {
			grid.collideAmmo(ammo, window);
			currentScore = this->scorePerBall * grid.getPoppedBalls();
		}

		window.clear();

		shootyBoi.rotateCannon();

		window.draw(borderTop);
		window.draw(borderRight);
		window.draw(borderBottom);
		window.draw(borderLeft);
		currScore.setString("Current Score: " + std::to_string(currentScore));
		window.draw(currScore);
		remainingShots.setString("Shots Remaining: " + std::to_string(shotsRemaining));
		window.draw(remainingShots);
		grid.drawGrid(window);
		window.draw(cannonStand);
		window.draw(shootyBoi);
		window.draw(ammo);
		window.display();
	} 
	
	if (!returnToMenu) {
		sf::Texture t1,t2;
		t1.loadFromFile("lose.jpg");
		sf::Sprite s1,s2;
		s1.setTexture(t1);

		sf::SoundBuffer bMusic;
		bMusic.loadFromFile("win_sound.wav");
		sf::Sound sMusic;
		sMusic.setBuffer(bMusic);
		sMusic.play();

		s1.scale(0.4f, 0.4f);
		s1.setPosition(400.f, 500.f);
		s1.setOrigin(400.f / 0.4f, 500.f / 0.4f);

		sf::Text loser;
		// set the string to display
		loser.setFont(font);
		loser.setString(" GAME OVER LOSER ");
		loser.setCharacterSize(55);
		loser.setPosition(sf::Vector2f(WINDOW_WIDTH / 2 - 300, WINDOW_HEIGHT / 2 - 10));
		
		while (!returnToMenu) {
			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					returnToMenu = true;
			}

			time_t current_time = time(NULL);

			if (current_time % 2 == 0)
			{
				loser.setFillColor(sf::Color::Red);
			}
			else
			{
				loser.setFillColor(sf::Color::White);
			}

			s1.scale(1.0001f, 1.0001f);

			window.clear();
			s1.rotate(.1f);
			window.draw(s1);
			window.draw(loser);
			window.display();
		}
	}

	system("cls");

	this->scores.addScore(std::to_string(currentScore));

	std::cout << "You scored " << currentScore << " points!" << std::endl;
	system("pause");

}

// resets ammo so that it is ready to be fired again
void GameWrapper::resetAmmo(Ball & ammo, int windowXSize, int windowYSize){

	ammo.setPosition(windowXSize/2, windowYSize);

	int nextAmmoColor = rand() % difficulty;
	ammo.setFillColor(Grid::samples[nextAmmoColor]);

	ammo.unDestroy();
}

// fires the ammo based on cannon angle
void GameWrapper::fireAmmo(Ball & ammo, Cannon & kanone) {
	float rotation = 3.14159265358979/180 * kanone.getRotation(); //convert rotation to radians
	float xVel = sin(rotation);
	float yVel = -cos(rotation);
	ammo.setVelocity(xVel, yVel);
}

// prints out the game instructions
void GameWrapper::printInstructions() {
	std::cout << "Bubble Shooter" << std::endl
		<< "Your goal is to clear all the bubble from the screen, scoring as many points as possible." << std::endl
		<< "You shoot at them with more bubbles, and when three or more of the same color come together, they all explode." << std::endl
		<< "The cannon holds the shooter bubble, and rotates on an axis."<< std::endl
		<< "When the cannon is pointing to where you want to shoot, press the space key and the bubble will be released." << std::endl
		<< "The more bubbles you blow up with one shot, the more points you can gain." << std::endl
		<< "If your shot fails to detonate any bubbles, you are given a strike.You lose the game when you reach your fifth strike." << std::endl
		<< "Your high score will automatically be saved, and will be displayed at the end of every game." << std::endl;
}

// changes possible colors and score multiplier based on selected difficulty
void GameWrapper::setDifficulty() {
	std::cout << "Select a difficulty:" << std::endl
		<< "1. Easy   (4 colors, 1x score)" << std::endl
		<< "2. Medium (5 colors, 1.5x score)" << std::endl
		<< "3. Hard   (6 colors, 2x score)" << std::endl;
	this->difficulty = getMenuOption(1, 3) + 3; // add 3 to get number of colors
	this->scorePerBall = this->difficulty - 2; // 2 for easy, 3 for medium, 4 for hard
}

// gets an integer from the user between the given values, usually used for selecting menu options
int GameWrapper::getMenuOption(int min, int max) {
	int choice = 0;
	std::cout << "enter your choice:" << std::endl;
	std::cin >> choice;

	while (std::cin.fail()) { // user did not enter an integer
		std::cin.clear();
		std::cin.ignore();
		std::cout << "invalid input, try again:" << std::endl;
		std::cin >> choice;
	}

	while (choice < min || choice > max) { // user did not enter a valid choice
		std::cout << "invalid choice, try again:" << std::endl;

		std::cin >> choice;

		while (std::cin.fail()) { // user did not enter an integer
			std::cin.clear();
			std::cin.ignore();
			std::cout << "invalid input, try again:" << std::endl;
			std::cin >> choice;
		}
	}

	return choice;
}