//ifstream infile, table;
//fstream.open("Convert.txt");
//table.open("dictionary.txt");
//string a; //convert to char;
//string b;
//while (!table.eof())
//{
//	getline(table, a, ';');
//	getline(table, b);
//	morse.insert(a[0], b);
//}
#include "Scores.h"


score::score()
{

}	
score::~score()
{

}

void score::importScore()
{
	fstream input;

	input.open("scores.csv");

	while (!input.eof())
	{
		string readString;
		node* temp_node = new node;

		//name,score
		getline(input, readString, ',');//name
		temp_node->mName = readString;

		if (input.eof()) break; 

		getline(input, readString);
		temp_node->mScore = readString;

		highScore.insert(temp_node);
	}

	input.close();

}
void score::exportScore()
{
	// following 3 lines are used to completely erase the previous contents of scores.csv
	std::ofstream clearFile;
	clearFile.open("scores.csv", std::ofstream::out | std::ofstream::trunc);
	clearFile.close();


	std::fstream output;
	output.open("scores.csv");

	node *temp = this->highScore.getNode();

	while (temp != nullptr)
	{
		output << temp->mName << "," << temp->mScore << std::endl;
		temp = temp->mpNext;
	}

	output.close();
}

void score::addScore(string score)
{
	string name;
	cout << "Enter your Name" << std::endl;
	std::cin >> name;
	
	node* temp = new node;
	temp->mName = name;
	temp->mScore = score;

	highScore.insert(temp);
}

void score::printScores() {
	this->highScore.printList();
}