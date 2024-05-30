#pragma once
#include "Ingredients.h"
#include <vector>
#include <string>

//---------------------------------------------------------------------
// Name:    Adrian A., Aubrey S., Alex B., Noah N.
// Project: KeyBoardBurgers
// Purpose: This code is responsible for holding information about 
//          playerBurger and what it holds
//---------------------------------------------------------------------
class PlayerBurger
{
private:
   std::vector<Ingredients*> burger;
public:
   //List
   PlayerBurger();
   ~PlayerBurger();

   bool addIngredient(Ingredients* newIngredient);
   bool ClearBurger();
   int sizeOfBurger();
   Ingredients* getIngredient(int index);
   bool hasBuns();
   int numOfIngredient(std::string ingredientName);
   bool isEmpty();
   void removeTopIngredient();
};