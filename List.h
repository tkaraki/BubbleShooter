#ifndef LIST_H
#define LIST_H
#pragma once

#include <iostream>
#include <string>
using std::string;
using std::cout;


struct node
{
	string mScore;
	string mName;
	node *mpNext;

	node();
	bool isEmpty();
	
};



class ScoreList
{
public:
	ScoreList();//constructor for linked list
	ScoreList(string name, string score);//constructor for linked list
	~ScoreList();
	
	node* makeNode(string score, string name);//creates node for list
	void insert(node* newnode);//insert items into list
	
	void printList();
	bool isEmpty();

	node *getNode();
	

private:
	node *pHead;

};

#endif