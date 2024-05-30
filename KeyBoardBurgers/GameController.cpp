#include "GameController.h"

// ----------------------------------------------------------------
// GameController Constructor
// ----------------------------------------------------------------
GameController::GameController()
{
}
// ----------------------------------------------------------------
// Returns a boolean based on if the playerBurger is correct
// ----------------------------------------------------------------
bool GameController::compareOrders(PlayerActionController* submittedBurger, Order* storedOrder)
{
   if (submittedBurger->isEmpty())
      return false;

   //check if the burger starts with a bottom bun and ends with a top bun
   if (!submittedBurger->hasCorrectBuns())
      return false;


   PlayerBurger* tempBurger = submittedBurger->getPlayerBurger();
   Sides* tempPlayerSides = submittedBurger->getSides();
   //check if the order has the correct sides
   if (storedOrder->getHasDrink() != tempPlayerSides->getAddedDrink())
      return false;
   if (storedOrder->getHasFries() != tempPlayerSides->getAddedFries())
      return false;

   //count the number and types of ingredients in the stored burger
   if (!(tempBurger->numOfIngredient("Ketchup") == storedOrder->numOfIngredient("Ketchup")))
   {
      return false;
   }
   if (!(tempBurger->numOfIngredient("Bottom bun") == storedOrder->numOfIngredient("Bottom bun")))
   {
      return false;
   }
   if (!(tempBurger->numOfIngredient("Lettuce") == storedOrder->numOfIngredient("Lettuce")))
   {
      return false;
   }
   if (!(tempBurger->numOfIngredient("Tomato") == storedOrder->numOfIngredient("Tomato")))
   {
      return false;
   }
   if (!(tempBurger->numOfIngredient("Cheese") == storedOrder->numOfIngredient("Cheese")))
   {
      return false;
   }
   if (!(tempBurger->numOfIngredient("Top bun") == storedOrder->numOfIngredient("Top bun")))
   {
      return false;
   }
   if (!(tempBurger->numOfIngredient("Patty") == storedOrder->numOfIngredient("Patty")))
   {
      return false;
   }
   if (!(tempBurger->numOfIngredient("Mustard") == storedOrder->numOfIngredient("Mustard")))
   {
      return false;
   }
   //should only reach here if the burgers are correct
   return true;
}