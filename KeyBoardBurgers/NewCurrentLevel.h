#pragma once
#include "Order.h"
#include <vector>

//---------------------------------------------------------------------
// Name:    Adrian A., Aubrey S., Alex B., Noah N.
// Project: KeyBoardBurgers
// Purpose: This code is responsible for holding information about 
//          NewCurrentLevel
//---------------------------------------------------------------------
class NewCurrentLevel
{
private:
	std::vector<Order*> orders;
	int level;
	int highScore;
	int score;
	int iteratorPosition;	//points to the next order
public:
	NewCurrentLevel();
	~NewCurrentLevel();

	void setLevelNumber(int num);
	int getLevelNumber();
	void setScore(int num);
	int getScore();
	void setHighScore(int num);
	int getHighScore();
	void setOrderVector(std::vector<Order*>);
	std::vector<Order*> getOrderVector();
	bool hasNext();
	Order* next();
	Order* getCurrentOrder();
	void incrementScore();
	void decrementScore();
	void reset();
};