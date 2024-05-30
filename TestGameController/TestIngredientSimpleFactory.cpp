#include "pch.h"
#include "CppUnitTest.h"
#include "../KeyBoardBurgers/IngredientsSimpleFactory.h"
//#include "../KeyBoardBurgers/IngredientsSimpleFactory.cpp"
#include "../KeyBoardBurgers/Ingredients.h"
#include "../KeyBoardBurgers/Ingredients.cpp"
#include "../KeyBoardBurgers/BottomBun.h"
#include "../KeyBoardBurgers/BottomBun.cpp"
#include "../KeyBoardBurgers/TopBun.h"
#include "../KeyBoardBurgers/TopBun.cpp"
#include "../KeyBoardBurgers/Lettuce.h"
#include "../KeyBoardBurgers/Lettuce.cpp"
#include "../KeyBoardBurgers/Cheese.h"
#include "../KeyBoardBurgers/Cheese.cpp"
#include "../KeyBoardBurgers/Tomato.h"
#include "../KeyBoardBurgers/Tomato.cpp"
#include "../KeyBoardBurgers/Patty.h"
#include "../KeyBoardBurgers/Patty.cpp"
#include "../KeyBoardBurgers/Mustard.h"
#include "../KeyBoardBurgers/Mustard.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace TestSimpleIngredientFactory
{
	TEST_CLASS(TestSimpleIngredientFactory)
	{
	public:
		IngredientsSimpleFactory ingredientFactory;
		TEST_METHOD(AddKetchupTest)
		{

			Assert::IsNotNull(ingredientFactory.makeIngredient('K'));
		}
		TEST_METHOD(AddMustardTest)
		{
			Assert::IsNotNull(ingredientFactory.makeIngredient('M'));
		}
		TEST_METHOD(AddPattyTest)
		{
			Assert::IsNotNull(ingredientFactory.makeIngredient('P'));
		}
		TEST_METHOD(AddBottomBunTest)
		{
			Assert::IsNotNull(ingredientFactory.makeIngredient('B'));
		}
		TEST_METHOD(AddTopBunTest)
		{
			Assert::IsNotNull(ingredientFactory.makeIngredient('G'));
		}
		TEST_METHOD(AddCheeseTest)
		{
			Assert::IsNotNull(ingredientFactory.makeIngredient('C'));
		}
		TEST_METHOD(AddLettuceTest)
		{
			Assert::IsNotNull(ingredientFactory.makeIngredient('L'));
		}
		TEST_METHOD(AddTomatoTest)
		{
			Assert::IsNotNull(ingredientFactory.makeIngredient('T'));
		}
		TEST_METHOD(DontAddIngredientTest)
		{
			Assert::IsNull(ingredientFactory.makeIngredient('Q'));
		}
	};
}