#pragma once
#include "Ingredients.h"
#include <iostream>

//---------------------------------------------------------------------
// Name:    Adrian A., Aubrey S., Alex B., Noah N.
// Project: KeyBoardBurgers
// Purpose: This code is responsible for holding information about 
//          Patty
//---------------------------------------------------------------------
class Patty : public Ingredients
{
private:
   int ingredientScore; //Used later for score

public:
   Patty();     //Implement score for later use
};