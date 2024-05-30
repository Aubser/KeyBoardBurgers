#include "AddFriesCommand.h"

// ----------------------------------------------------------------
// Constructor
// ----------------------------------------------------------------
AddFriesCommand::AddFriesCommand(PlayerActionController* playerActionController) : Command(playerActionController)
{

}

// ----------------------------------------------------------------
// Exceutes a add fries to the order through Undo/Redo Command Pattern
// ----------------------------------------------------------------
void AddFriesCommand::execute()
{
   reciever->getSides()->setAddedFries(true);
}

// ----------------------------------------------------------------
// Unexceutes a add fries to the order through Undo/Redo Command Pattern
// ----------------------------------------------------------------
void AddFriesCommand::unexecute()
{
   reciever->getSides()->setAddedFries(false);
}