#pragma once
#include "PlayerBurger.h"
#include "Sides.h"
#include "IngredientsSimpleFactory.h"
#include <string>

//---------------------------------------------------------------------
// Name:    Adrian A., Aubrey S., Alex B., Noah N.
// Project: KeyBoardBurgers
// Purpose: This code is responsible for holding all information
//          for receiving user input
//---------------------------------------------------------------------
class PlayerActionController
{
private:
   PlayerBurger* playerBurger;
   Sides* playerSides;
   IngredientsSimpleFactory ingredientFactory;
public:
   PlayerActionController();
   bool addIngredient(char ingredient);
   PlayerBurger* getPlayerBurger();
   bool trashBurger();
   bool hasCorrectBuns();
   bool isEmpty();
   bool resetPlayerBurger();
   Sides* getSides();
   void setSides(Sides* newSides);
};