#pragma once
#include "Ingredients.h"
#include <string>
#include <vector>

//---------------------------------------------------------------------
// Name:    Adrian A., Aubrey S., Alex B., Noah N.
// Project: KeyBoardBurgers
// Purpose: This code is responsible for holding information about 
//          an Order on what it holds and is how it's affected
//---------------------------------------------------------------------
class Order {
private:
	std::vector<Ingredients*> ingredients;
	bool hasDrink;
	bool hasFries;
	int iteratorPosition;
public:
	Order();
	bool addIngredient(Ingredients* newIngredient);
	bool hasNextIngredient();
	Ingredients* nextIngredient();
	int numOfIngredient(std::string ingredientName);
	bool getHasDrink();
	void setHasDrink(bool newHasDrink);
	bool getHasFries();
	void setHasFries(bool newHasDrink);
};