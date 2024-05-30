#pragma once
#include "Command.h"

//---------------------------------------------------------------------
// Name:    Adrian A., Aubrey S., Alex B., Noah N.
// Project: KeyBoardBurgers
// Purpose: This code is responsible for adding a ingredient to the 
//          list when fulfilling an order.
//---------------------------------------------------------------------
class AddIngredientCommand : public Command
{
private:
   //char addedIngredient;
   Ingredients* ingredientToBeAdded;
public:
   AddIngredientCommand(PlayerActionController* playerActionController, Ingredients* ingredientToBeAdded);
   void execute();
   void unexecute();
};