#include "Order.h"

// ----------------------------------------------------------------
// Order Constructor
// ----------------------------------------------------------------
Order::Order()
{
	iteratorPosition = 0;
	hasDrink = false;
	hasFries = false;
}

// ----------------------------------------------------------------
// Adds an ingredient to the vector
// ----------------------------------------------------------------
bool Order::addIngredient(Ingredients* newIngredient)
{
	try {
		ingredients.push_back(newIngredient);
		return true;
	}
	catch (...)
	{
		return false;
	}
}

// ----------------------------------------------------------------
// Checks the vector if there is another ingredient
// ----------------------------------------------------------------
bool Order::hasNextIngredient()
{
	return (iteratorPosition < ingredients.size());
}

// ----------------------------------------------------------------
// Returns the next ingredient in the vector
// ----------------------------------------------------------------
Ingredients* Order::nextIngredient()
{
	return ingredients[iteratorPosition++];
}

// ----------------------------------------------------------------
// Goes through the order and returns the number of ingredients in the vector
// ----------------------------------------------------------------
int Order::numOfIngredient(std::string ingredientName)
{
	int numIngredient = 0;
	//loop through ingredients ignoring the buns
	for (int i = 1; i < ingredients.size() - 1; i++)
	{
		if (ingredients[i]->getName() == ingredientName)
		{
			numIngredient++;
		}
	}
	return numIngredient;
}

// ----------------------------------------------------------------
// Returns a bool if it has a drink
// ----------------------------------------------------------------
bool Order::getHasDrink()
{
	return hasDrink;
}

// ----------------------------------------------------------------
// Sets if it has a drink
// ----------------------------------------------------------------
void Order::setHasDrink(bool newHasDrink)
{
	hasDrink = newHasDrink;
}

// ----------------------------------------------------------------
// Returns a bool if it has fries
// ----------------------------------------------------------------
bool Order::getHasFries()
{
	return hasFries;
}

// ----------------------------------------------------------------
// Sets if it has fries
// ----------------------------------------------------------------
void Order::setHasFries(bool newHasFries)
{
	hasFries = newHasFries;
}