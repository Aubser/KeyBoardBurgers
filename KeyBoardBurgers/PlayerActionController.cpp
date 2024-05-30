#include "PlayerActionController.h"

// ----------------------------------------------------------------
// PlayerActionController construtor
// ----------------------------------------------------------------
PlayerActionController::PlayerActionController()
{
   playerBurger = new PlayerBurger();
   playerSides = new Sides();
}

// ----------------------------------------------------------------
// Returns a boolean based on if an ingredient was correctly added
// ----------------------------------------------------------------
bool PlayerActionController::addIngredient(char ingredient)
{
   bool added = false;
   Ingredients* temp;
   // Checks if it is fries
   if (ingredient == 'F')
   {
      playerSides->setAddedFries(true);
      added = true;
   }
   // checks if it is a drink
   else if (ingredient == 'D')
   {
      playerSides->setAddedDrink(true);
      added = true;
   }
   // checking if it is an actual ingredient
   else
   {
      //create new ingredient
      temp = ingredientFactory.makeIngredient(ingredient);

      //check if the input wasn't an ingredient since factory returns a nullptr in that case
      if (temp != nullptr)
         added = playerBurger->addIngredient(temp);
      else
         added = false;
   }
   return added;
}

// ----------------------------------------------------------------
// Returns the PlayerBurger
// ----------------------------------------------------------------
PlayerBurger* PlayerActionController::getPlayerBurger()
{
   return playerBurger;
}

// ----------------------------------------------------------------
// Clears the PlayerBurger
// ----------------------------------------------------------------
bool PlayerActionController::trashBurger()
{
   return playerBurger->ClearBurger();
}
// ----------------------------------------------------------------
// Returns a boolean based on if the player has the correct buns
// ----------------------------------------------------------------
bool PlayerActionController::hasCorrectBuns()
{
   return playerBurger->hasBuns();
}

// ----------------------------------------------------------------
// Returns a boolean based on if the PlayerBurger is empty
// ----------------------------------------------------------------
bool PlayerActionController::isEmpty()
{
   return playerBurger->isEmpty();
}

// ----------------------------------------------------------------
// Resets the PlayerBurger
// ----------------------------------------------------------------
bool PlayerActionController::resetPlayerBurger()
{
   bool burgerReset, sidesReset;
   burgerReset = playerBurger->ClearBurger();
   sidesReset = playerSides->reset();
   return true;
}

// ----------------------------------------------------------------
// Returns the playerSides
// ----------------------------------------------------------------
Sides* PlayerActionController::getSides()
{
   return playerSides;
}

// ----------------------------------------------------------------
// Returns the playerSides
// ----------------------------------------------------------------
void PlayerActionController::setSides(Sides* newSides)
{
   playerSides = newSides;
}