#include "NewCurrentLevel.h"

// ----------------------------------------------------------------
// NewCurrentLevel constructor 
// ----------------------------------------------------------------
NewCurrentLevel::NewCurrentLevel()
{
	level = 0;
	highScore = 0;
	score = 0;
	iteratorPosition = 0;
}

// ----------------------------------------------------------------
// Clears the Orders
// ----------------------------------------------------------------
NewCurrentLevel::~NewCurrentLevel()
{
	orders.clear();
}

// ----------------------------------------------------------------
// Sets current level number
// ----------------------------------------------------------------
void NewCurrentLevel::setLevelNumber(int num) {
	level = num;
}

// ----------------------------------------------------------------
// Gets the current level number
// ----------------------------------------------------------------
int NewCurrentLevel::getLevelNumber() {
	return level;
}

// ----------------------------------------------------------------
// Sets the current level score
// ----------------------------------------------------------------
void NewCurrentLevel::setScore(int num) {
	score = num;
}

// ----------------------------------------------------------------
// Gets the current level score
// ----------------------------------------------------------------
int NewCurrentLevel::getScore() {
	return score;
}

// ----------------------------------------------------------------
// Sets the current level high score
// ----------------------------------------------------------------
void NewCurrentLevel::setHighScore(int num) {
	highScore = num;
}

// ----------------------------------------------------------------
// Gets the current level high score
// ----------------------------------------------------------------
int NewCurrentLevel::getHighScore() {
	return highScore;
}

// ----------------------------------------------------------------
// Sets the Order vector
// ----------------------------------------------------------------
void NewCurrentLevel::setOrderVector(std::vector<Order*> newLevelVector)
{
	orders = newLevelVector;
}

// ----------------------------------------------------------------
// Gets the Order vector
// ----------------------------------------------------------------
std::vector<Order*> NewCurrentLevel::getOrderVector() {
	return orders;
}

// ----------------------------------------------------------------
// Returns a boolean based on if there is another order
// ----------------------------------------------------------------
bool NewCurrentLevel::hasNext()
{
	if (iteratorPosition < orders.size())
		return true;
	return false;
}

// ----------------------------------------------------------------
// Returns the next Order 
// ----------------------------------------------------------------
Order* NewCurrentLevel::next()
{
	return orders[iteratorPosition++];
}

// ----------------------------------------------------------------
// Returns the current Order
// ----------------------------------------------------------------
Order* NewCurrentLevel::getCurrentOrder()
{
	return orders[iteratorPosition - 1];
}

// ----------------------------------------------------------------
// Increases the score by 1
// ----------------------------------------------------------------
void NewCurrentLevel::incrementScore()
{
	score++;
}

// ----------------------------------------------------------------
// decreases the score by 1
// ----------------------------------------------------------------
void NewCurrentLevel::decrementScore()
{
	score--;
}

// ----------------------------------------------------------------
// Resets the NewCurrentLevel information
// ----------------------------------------------------------------
void NewCurrentLevel::reset()
{
	score = 0;
	orders.clear();
	iteratorPosition = 0;
	highScore = 0;
	level = 0;
}