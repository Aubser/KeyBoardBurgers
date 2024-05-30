#include "Sides.h"

// ----------------------------------------------------------------
// This is the sides constructor
// ----------------------------------------------------------------
Sides::Sides()
{
   addedDrink = false;
   addedFries = false;
}

// ----------------------------------------------------------------
// Sets boolean of addedDrink
// ----------------------------------------------------------------
void Sides::setAddedDrink(bool newAddedDrink)
{
   addedDrink = newAddedDrink;
}

// ----------------------------------------------------------------
// Returns boolean of addedDrink
// ----------------------------------------------------------------
bool Sides::getAddedDrink()
{
   return addedDrink;
}

// ----------------------------------------------------------------
// Sets boolean of addedFries
// ----------------------------------------------------------------
void Sides::setAddedFries(bool newAddedFries)
{
   addedFries = newAddedFries;
}

// ----------------------------------------------------------------
// Returns boolean of addedFries
// ----------------------------------------------------------------
bool Sides::getAddedFries()
{
   return addedFries;
}

// ----------------------------------------------------------------
// Resets the sides to false
// ----------------------------------------------------------------
bool Sides::reset()
{
   addedDrink = false;
   addedFries = false;
   return (addedDrink == false && addedFries == false);
}