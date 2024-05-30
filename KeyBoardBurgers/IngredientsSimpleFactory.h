#pragma once
#include "Ingredients.h"
#include "Ketchup.h"
#include "BottomBun.h"
#include "Lettuce.h"
#include "Cheese.h"
#include "TopBun.h"
#include "Mustard.h"
#include "Patty.h"
#include "Tomato.h"

//---------------------------------------------------------------------
// Name:    Adrian A., Aubrey S., Alex B., Noah N.
// Project: KeyBoardBurgers
// Purpose: This code is responsible for constructing ingredients
//          when asked by the user
//---------------------------------------------------------------------
class IngredientsSimpleFactory
{
public:
   static Ingredients* makeIngredient(char ingredient);
};