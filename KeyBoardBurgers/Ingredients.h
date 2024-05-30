#pragma once
#include <string>

//---------------------------------------------------------------------
// Name:    Adrian A., Aubrey S., Alex B., Noah N.
// Project: KeyBoardBurgers
// Purpose: This code is responsible for holding information about 
//          Ingredients
//---------------------------------------------------------------------
class Ingredients
{
public:
	// destructor
	virtual ~Ingredients() { }
	std::string getName() { return ingredientName; };

protected:
	std::string ingredientName;
};