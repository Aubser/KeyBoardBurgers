#include "pch.h"
#include "CppUnitTest.h"
#include "../KeyBoardBurgers/PlayerActionController.h"
#include "../KeyBoardBurgers/PlayerActionController.cpp"
#include "../KeyBoardBurgers/IngredientsSimpleFactory.h"
#include "../KeyBoardBurgers/IngredientsSimpleFactory.cpp"
#include "../KeyBoardBurgers/Sides.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestPlayerActionController
{
	TEST_CLASS(TestPlayerActionController)
	{
	public:
		PlayerActionController* playerActionController = new PlayerActionController();
		PlayerActionController* playerActionController2 = new PlayerActionController();
		Sides* testSides = new Sides();
		TEST_METHOD(AddBurgerIngredient)
		{
			char input = 'K';
			Assert::IsTrue(playerActionController->addIngredient(input));
		}
		TEST_METHOD(DontAddBurgerIngredient)
		{
			char input2 = 'Q';  //not an ingredient
			Assert::IsFalse(playerActionController->addIngredient(input2));
		}
		TEST_METHOD(AddDrinkIngredient)
		{
			char input = 'D';
			Assert::IsTrue(playerActionController->addIngredient(input));
		}
		TEST_METHOD(AddFriesIngredient)
		{
			char input2 = 'F';
			Assert::IsTrue(playerActionController->addIngredient(input2));
		}
		TEST_METHOD(TrashBurgerTest)
		{
			Assert::IsTrue(playerActionController->trashBurger());
		}
		TEST_METHOD(ResetPlayerBurgerTest)
		{
			Assert::IsTrue(playerActionController->resetPlayerBurger());
		}
		TEST_METHOD(GetSidesTest)
		{
			playerActionController->setSides(testSides);
			Sides tempSides = *playerActionController->getSides();
			Assert::AreEqual(testSides->getAddedDrink(), tempSides.getAddedDrink());
			Assert::AreEqual(testSides->getAddedFries(), tempSides.getAddedFries());
		}
		TEST_METHOD(HasCorrectBunsTest)
		{
			playerActionController2->resetPlayerBurger();
			playerActionController2->addIngredient('B');
			playerActionController2->addIngredient('G');
			Assert::IsTrue(playerActionController2->hasCorrectBuns());
		}
		TEST_METHOD(OnlyTopBunHasCorrectBunsTest)
		{
			playerActionController2->resetPlayerBurger();
			playerActionController2->addIngredient('K');
			playerActionController2->addIngredient('G');
			Assert::IsFalse(playerActionController2->hasCorrectBuns());
		}
		TEST_METHOD(OnlyBottomBunHasCorrectBunsTest)
		{
			playerActionController2->resetPlayerBurger();
			playerActionController2->addIngredient('B');
			playerActionController2->addIngredient('K');
			Assert::IsFalse(playerActionController2->hasCorrectBuns());
		}
		TEST_METHOD(IsEmptyTest)
		{
			playerActionController2->resetPlayerBurger();
			Assert::IsTrue(playerActionController2->isEmpty());
		}
		TEST_METHOD(NotIsEmptyTest)
		{
			playerActionController2->resetPlayerBurger();
			playerActionController2->addIngredient('B');
			playerActionController2->addIngredient('K');
			Assert::IsFalse(playerActionController2->isEmpty());
		}
	};
}