#pragma once
#include "PlayerActionController.h"

//---------------------------------------------------------------------
// Name:    Adrian A., Aubrey S., Alex B., Noah N.
// Project: KeyBoardBurgers
// Purpose: This code is responsible for holding information about the 
//          Command Pattern
//---------------------------------------------------------------------
class Command
{
protected:
   PlayerActionController* reciever;
public:
   Command(PlayerActionController* newReciever) { reciever = newReciever; }
   virtual void execute() = 0;
   virtual void unexecute() = 0;
};