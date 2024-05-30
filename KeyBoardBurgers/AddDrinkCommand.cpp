#include "AddDrinkCommand.h"

// ----------------------------------------------------------------
// Constructor
// ----------------------------------------------------------------
AddDrinkCommand::AddDrinkCommand(PlayerActionController* playerActionController) : Command(playerActionController)
{

}

// ----------------------------------------------------------------
// Exceutes a add drink to the order through Undo/Redo Command Pattern
// ----------------------------------------------------------------
void AddDrinkCommand::execute()
{
   reciever->getSides()->setAddedDrink(true);
}

// ----------------------------------------------------------------
// Unexceutes a add drink to the order through Undo/Redo Command Pattern
// ----------------------------------------------------------------
void AddDrinkCommand::unexecute()
{
   reciever->getSides()->setAddedDrink(false);
}