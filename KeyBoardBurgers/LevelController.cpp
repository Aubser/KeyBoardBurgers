#include "LevelController.h"

// ----------------------------------------------------------------
// LevelController contructor
// ----------------------------------------------------------------
LevelController::LevelController()
{
	currentLevel = new NewCurrentLevel();
	database = new DatabaseController();
	numUnlocked = 1;
}
// ----------------------------------------------------------------
// unlocks the next level
// ----------------------------------------------------------------
void LevelController::unlockNextLevel() {
	database->unlockLevel(currentLevel->getLevelNumber() + 1);
}

// ----------------------------------------------------------------
// Returns a boolean based on if the level is unlocked
// ----------------------------------------------------------------
bool LevelController::checkStatus() {
	return database->isUnlocked(currentLevel->getLevelNumber());
}

// ----------------------------------------------------------------
// Sets the current level number
// ----------------------------------------------------------------
void LevelController::setCurrentLevelNum(int levelNum)
{
	currentLevel->setLevelNumber(levelNum);
}

// ----------------------------------------------------------------
// Returns the level number
// ----------------------------------------------------------------
int LevelController::getCurrentLevelNum()
{
	return currentLevel->getLevelNumber();
}

// ----------------------------------------------------------------
// Gets the level information from the XML file and puts it in a vector
// ----------------------------------------------------------------
void LevelController::populateCurrentLevel()
{
	currentLevel->setOrderVector(database->defineOrders(currentLevel->getLevelNumber()));
}

// ----------------------------------------------------------------
// Returns a boolean based on if it has another order
// ----------------------------------------------------------------
bool LevelController::hasNextOrder()
{
	return currentLevel->hasNext();
}

// ----------------------------------------------------------------
// Returns the next Order
// ----------------------------------------------------------------
Order* LevelController::nextOrder()
{
	return currentLevel->next();
}

// ----------------------------------------------------------------
// Returns the current Order
// ----------------------------------------------------------------
Order* LevelController::getCurrentOrder()
{
	return currentLevel->getCurrentOrder();
}

// ----------------------------------------------------------------
// Increases the Score 
// ----------------------------------------------------------------
void LevelController::incrementScore()
{
	currentLevel->incrementScore();
}

// ----------------------------------------------------------------
// Decreases the Score
// ----------------------------------------------------------------
void LevelController::decrementScore()
{
	currentLevel->decrementScore();
}

// ----------------------------------------------------------------
// Returns the current level Score
// ----------------------------------------------------------------
int LevelController::getScore()
{
	return currentLevel->getScore();
}

// ----------------------------------------------------------------
// Returns the High Score
// ----------------------------------------------------------------
int LevelController::getHighScore()
{
	return database->getHighScore(currentLevel->getLevelNumber());
}

// ----------------------------------------------------------------
// Returns a boolean based on if the level is beat
// ----------------------------------------------------------------
bool LevelController::isBeat()
{
	int scoreToBeat = database->getBeatScore(currentLevel->getLevelNumber());
	return (scoreToBeat <= currentLevel->getScore());
}

// ----------------------------------------------------------------
// Returns a boolean based on if the old high score was beaten
// ----------------------------------------------------------------
bool LevelController::setIfHighScore()
{
	int storedHighScore = database->getHighScore(currentLevel->getLevelNumber());
	int submittedHighScore = currentLevel->getScore();
	// compares the potential high score to the old high score
	if (submittedHighScore > storedHighScore)
	{
		database->setHighScore(currentLevel->getLevelNumber(), submittedHighScore);
		return true;
	}
	return false;
}

// ----------------------------------------------------------------
// Resets the CurrentLevel
// ----------------------------------------------------------------
void LevelController::reset()
{
	currentLevel->reset();
}