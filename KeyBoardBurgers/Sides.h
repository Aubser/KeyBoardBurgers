#pragma once

//---------------------------------------------------------------------
// Name:    Adrian A., Aubrey S., Alex B., Noah N.
// Project: KeyBoardBurgers
// Purpose: This code is responsible for holding information about 
//          Sides
//---------------------------------------------------------------------
class Sides
{
private:
   bool addedDrink;
   bool addedFries;
public:
   Sides();
   void setAddedDrink(bool newAddedDrink);
   bool getAddedDrink();
   void setAddedFries(bool newAddedFries);
   bool getAddedFries();
   bool reset();
};