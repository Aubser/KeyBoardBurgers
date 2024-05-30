#include "IngredientsSimpleFactory.h"
// ----------------------------------------------------------------
// Is in charge of returning the ingredient based upon the char that has been sent
// ----------------------------------------------------------------
Ingredients* IngredientsSimpleFactory::makeIngredient(char ingredient)
{
   Ingredients* newIngredient = nullptr;
   switch (ingredient)
   {
   case 'K':
      newIngredient = new Ketchup();
      break;
   case 'B':
      newIngredient = new BottomBun();
      break;
   case 'L':
      newIngredient = new Lettuce();
      break;
   case 'T':
      newIngredient = new Tomato();
      break;
   case 'C':
      newIngredient = new Cheese();
      break;
   case 'G':
      newIngredient = new TopBun();
      break;
   case 'P':
      newIngredient = new Patty();
      break;
   case 'M':
      newIngredient = new Mustard();
      break;
   default:
      newIngredient = nullptr;
      break;
   }

   return newIngredient;
}
