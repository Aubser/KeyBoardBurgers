#pragma once
#include "NewCurrentLevel.h"
#include "DatabaseController.h"
#include "Order.h"

//---------------------------------------------------------------------
// Name:    Adrian A., Aubrey S., Alex B., Noah N.
// Project: KeyBoardBurgers
// Purpose: This code is responsible for holding information about 
//          Level Controller to unlock further levels
//---------------------------------------------------------------------
class LevelController{
private:
	int numUnlocked;
	NewCurrentLevel* currentLevel;
	DatabaseController* database;
public:
	LevelController();
	void unlockNextLevel();
	bool checkStatus();
	void setCurrentLevelNum(int levelNum);
	int getCurrentLevelNum();
	void populateCurrentLevel();
	bool hasNextOrder();
	Order* nextOrder();
	Order* getCurrentOrder();
	void incrementScore();
	int getScore();
	int getHighScore();
	bool isBeat();
	bool setIfHighScore();
	void decrementScore();
	void reset();
};