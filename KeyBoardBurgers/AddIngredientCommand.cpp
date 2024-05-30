#include "AddIngredientCommand.h"

// ----------------------------------------------------------------
// Constructor
// ----------------------------------------------------------------
AddIngredientCommand::AddIngredientCommand(PlayerActionController* playerActionController, Ingredients* newIngredientToBeAdded) : Command(playerActionController)
{
   ingredientToBeAdded = newIngredientToBeAdded;
}

// ----------------------------------------------------------------
// Exceutes a add ingredient to the order through Undo/Redo Command Pattern
// ----------------------------------------------------------------
void AddIngredientCommand::execute()
{
   reciever->getPlayerBurger()->addIngredient(ingredientToBeAdded);
}

// ----------------------------------------------------------------
// Unexceutes a add ingredient to the order through Undo/Redo Command Pattern
// ----------------------------------------------------------------
void AddIngredientCommand::unexecute()
{
   reciever->getPlayerBurger()->removeTopIngredient();
}