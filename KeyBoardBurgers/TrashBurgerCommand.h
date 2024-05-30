#pragma once
#include "Command.h"
#include <vector>

//---------------------------------------------------------------------
// Name:    Adrian A., Aubrey S., Alex B., Noah N.
// Project: KeyBoardBurgers
// Purpose: This code is responsible for trashing a burger from a list
//---------------------------------------------------------------------
class TrashBurgerCommand : public Command
{
private:
   std::vector<Ingredients*> trashedBurger;
   bool hasDrink;
   bool hasFries;
public:
	TrashBurgerCommand(PlayerActionController* playerActionController);
   void execute();
   void unexecute();
};