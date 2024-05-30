#include "TrashBurgerCommand.h"

// ----------------------------------------------------------------
// TrashBurgerCommand Constructor
// ----------------------------------------------------------------
TrashBurgerCommand::TrashBurgerCommand(PlayerActionController* playerActionController) : Command(playerActionController)
{

}

// ----------------------------------------------------------------
// Exceutes a TrashBurger command to order through Undo/Redo Command Pattern
// ----------------------------------------------------------------
void TrashBurgerCommand::execute() {
	// trashes and stores the burger that has been trashed
	trashedBurger.clear();
	Sides* tempSides = reciever->getSides();
	PlayerBurger* tempBurger = reciever->getPlayerBurger();
	hasDrink = tempSides->getAddedDrink();
	hasFries = tempSides->getAddedFries();
	for (int i = 0; i < tempBurger->sizeOfBurger(); i++)
	{
		trashedBurger.push_back(tempBurger->getIngredient(i));
	}
	reciever->getSides()->reset();
	tempBurger->ClearBurger();
}

// ----------------------------------------------------------------
// Unexecutes a TrashBurger command to order through Undo/Redo Command Pattern
// ----------------------------------------------------------------
void TrashBurgerCommand::unexecute() {
	PlayerBurger* tempBurger = reciever->getPlayerBurger();
	Sides* tempSides = reciever->getSides();
	for (int i = 0; i < trashedBurger.size(); i++)
	{
		tempBurger->addIngredient(trashedBurger[i]);
	}
	tempSides->setAddedDrink(hasDrink);
	tempSides->setAddedFries(hasFries);
}