#include "PlayerBurger.h"

// ----------------------------------------------------------------
// PlayerBurger constructor
// ----------------------------------------------------------------
PlayerBurger::PlayerBurger()
{
}

// ----------------------------------------------------------------
// Resets the PlayerBurger
// ----------------------------------------------------------------
PlayerBurger::~PlayerBurger()
{
   burger.clear();
}

// ----------------------------------------------------------------
// Adds an ingredient to the players burger
// ----------------------------------------------------------------
bool PlayerBurger::addIngredient(Ingredients* newIngredient)
{
    // Only allows for the player to add 15 ingredients to the burger
    burger.push_back(newIngredient);
    return (burger[burger.size() - 1] == newIngredient);
}

// ----------------------------------------------------------------
// Clears the PlayerBurger
// ----------------------------------------------------------------
bool PlayerBurger::ClearBurger()
{
   try {
      burger.clear();
      return true;
   }
   catch (...)
   {
      return false;
   }
}

// ----------------------------------------------------------------
// Returns the size of the PlayerBurger
// ----------------------------------------------------------------
int PlayerBurger::sizeOfBurger()
{
   return burger.size();
}

// ----------------------------------------------------------------
// Gets an ingredient from a specific index in the PlayerBurger
// ----------------------------------------------------------------
Ingredients* PlayerBurger::getIngredient(int index)
{
   Ingredients* tempIngredient = nullptr;
   if (index < burger.size())
      tempIngredient = burger[index];
   return tempIngredient;
}

// ----------------------------------------------------------------
// Checks if the PlayerBurger has both top and bottom buns
// ----------------------------------------------------------------
bool PlayerBurger::hasBuns()
{
   if (burger[0]->getName() == "Bottom bun" && burger[burger.size() - 1]->getName() == "Top bun")
      return true;
   else
      return false;
}

// ----------------------------------------------------------------
// Returns the number of ingredients the PlayerBurger has
// ----------------------------------------------------------------
int PlayerBurger::numOfIngredient(std::string ingredientName)
{
   int numIngredient = 0;
   //loop through burger ignoring the buns
   for (int i = 1; i < burger.size() - 1; i++)
   {
      if (burger[i]->getName() == ingredientName)
      {
         numIngredient++;
      }
   }
   return numIngredient;
}

// ----------------------------------------------------------------
// Returns true if the player's burger is empty
// ----------------------------------------------------------------
bool PlayerBurger::isEmpty()
{
   return (burger.size() == 0);
}

// ----------------------------------------------------------------
// Removes the last ingredient inserted in the player's burger
// ----------------------------------------------------------------
void PlayerBurger::removeTopIngredient()
{
   burger.pop_back();
}