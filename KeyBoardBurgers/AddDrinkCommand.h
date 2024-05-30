#pragma once
#include "Command.h"

//---------------------------------------------------------------------
// Name:    Adrian A., Aubrey S., Alex B., Noah N.
// Project: KeyBoardBurgers
// Purpose: This code is responsible for adding a drink to the list 
//          when fulfilling an order.
//---------------------------------------------------------------------
class AddDrinkCommand : public Command
{
public:
   AddDrinkCommand(PlayerActionController* playerActionController);
   void execute();
   void unexecute();
};