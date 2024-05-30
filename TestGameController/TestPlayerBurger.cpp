#include "pch.h"
#include "CppUnitTest.h"
#include "../KeyBoardBurgers/PlayerBurger.h"
#include "../KeyBoardBurgers/PlayerBurger.cpp"
#include "../KeyBoardBurgers/Ketchup.h"
#include "../KeyBoardBurgers/Ketchup.cpp"
#include "../KeyBoardBurgers/BottomBun.h"
#include "../KeyBoardBurgers/TopBun.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestPlayerBurger
{
	TEST_CLASS(TestPlayerBurger)
	{
	public:
		Ingredients* newIngredient = new Ketchup();
		Ingredients* bottomBun = new BottomBun();
		Ingredients* topBun = new TopBun();
		//I don't think it's possible to fail this test
		//due to the nature of vectors
		TEST_METHOD(AddIngredient)
		{
			PlayerBurger testBurger;
			Assert::IsTrue(testBurger.addIngredient(newIngredient));
		}
		TEST_METHOD(ClearBurgerTest)
		{
			PlayerBurger testBurger;
			testBurger.addIngredient(newIngredient);
			Assert::IsTrue(testBurger.ClearBurger());
		}
		TEST_METHOD(SizeOfBurgerTest)
		{
			PlayerBurger testBurger;
			testBurger.addIngredient(newIngredient);
			Assert::AreEqual(1, testBurger.sizeOfBurger());
		}
		TEST_METHOD(GetIngredientTest)
		{
			PlayerBurger testBurger;
			testBurger.addIngredient(newIngredient);
			Assert::IsTrue(testBurger.getIngredient(0)->getName() == newIngredient->getName());
		}
		TEST_METHOD(DontGetIngredientTest)
		{
			PlayerBurger testBurger;
			Assert::IsNull(testBurger.getIngredient(0));
		}
		TEST_METHOD(HasBunsTest)
		{
			PlayerBurger testBurger;
			testBurger.addIngredient(bottomBun);
			testBurger.addIngredient(topBun);
			Assert::IsTrue(testBurger.hasBuns());
		}
		TEST_METHOD(OnlyBottomBunHasBunsTest)
		{
			PlayerBurger testBurger;
			testBurger.addIngredient(bottomBun);
			testBurger.addIngredient(newIngredient);
			Assert::IsFalse(testBurger.hasBuns());
		}
		TEST_METHOD(OnlyTopBunHasBunsTest)
		{
			PlayerBurger testBurger;
			testBurger.addIngredient(newIngredient);
			testBurger.addIngredient(topBun);
			Assert::IsFalse(testBurger.hasBuns());
		}
		TEST_METHOD(NumOfIngredientTest)
		{
			PlayerBurger testBurger;
			testBurger.addIngredient(bottomBun);
			testBurger.addIngredient(newIngredient);
			testBurger.addIngredient(newIngredient);
			testBurger.addIngredient(topBun);
			Assert::AreEqual(2, testBurger.numOfIngredient("Ketchup"));
		}
		TEST_METHOD(IsEmptyTest)
		{
			PlayerBurger testBurger;
			Assert::IsTrue(testBurger.isEmpty());
		}
		TEST_METHOD(NotIsEmptyTest)
		{
			PlayerBurger testBurger;
			testBurger.addIngredient(newIngredient);
			Assert::IsFalse(testBurger.isEmpty());
		}
	};
}