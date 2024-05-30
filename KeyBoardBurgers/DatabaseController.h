#pragma once
#include "Order.h"
#include <vector>
#include "IngredientsSimpleFactory.h"

using namespace System;
using namespace System::Xml;

//---------------------------------------------------------------------
// Name:    Adrian A., Aubrey S., Alex B., Noah N.
// Project: KeyBoardBurgers
// Purpose: This code is responsible for holding information about the 
//          DatabaseController and set anything for levels
//---------------------------------------------------------------------
class DatabaseController
{
public:
   DatabaseController();
   std::vector<Order*> DatabaseController::defineOrders(int levelNum);
   bool isUnlocked(int levelNum);
   bool setHighScore(int levelNum, int highScore);
   int getHighScore(int levelNum);
   int getBeatScore(int levelNum);
   bool unlockLevel(int levelNum);
};