#pragma once
#include "Command.h"

//---------------------------------------------------------------------
// Name:    Adrian A., Aubrey S., Alex B., Noah N.
// Project: KeyBoardBurgers
// Purpose: This code is responsible for adding fries to the list 
//          when fulfilling an order.
//---------------------------------------------------------------------
class AddFriesCommand : public Command
{
private:

public:
   AddFriesCommand(PlayerActionController* playerActionController);
   void execute();
   void unexecute();
};