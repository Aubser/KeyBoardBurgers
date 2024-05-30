#pragma once
#include "PlayerActionController.h"
#include "LevelController.h"
#include "Order.h"
#include "PlayerBurger.h"
#include "Sides.h"

//---------------------------------------------------------------------
// Name:    Adrian A., Aubrey S., Alex B., Noah N.
// Project: KeyBoardBurgers
// Purpose: This code is responsible for starting the game and
//          instantiating a playerBuger and newOrder
//---------------------------------------------------------------------
class GameController
{
public:
   GameController();
   bool compareOrders(PlayerActionController* newPlayerBurger, Order* newOrder);
};