#include "pch.h"
#include "CppUnitTest.h"
#include "../KeyBoardBurgers/Order.h"
#include "../KeyBoardBurgers/Order.cpp"
#include "../KeyBoardBurgers/Ketchup.h"
#include "../KeyBoardBurgers/BottomBun.h"
#include "../KeyBoardBurgers/TopBun.h"
#include <vector>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestOrder
{
	TEST_CLASS(TestOrder)
	{
	public:
		Ingredients* testIngredient = new Ketchup();
		Ingredients* bottomBun = new BottomBun();
		Ingredients* topBun = new TopBun();
		// can't fail since just pushing an ingredient onto a vector
		TEST_METHOD(AddIngredientTest)
		{
			Order testOrder;
			Assert::IsTrue(testOrder.addIngredient(testIngredient));
		}
		TEST_METHOD(HasNextIngredientTest)
		{
			Order testOrder;
			testOrder.addIngredient(testIngredient);

			Assert::IsTrue(testOrder.hasNextIngredient());
		}
		TEST_METHOD(FailedHasNextIngredientTest)
		{
			Order testOrder;
			Assert::IsFalse(testOrder.hasNextIngredient());
		}
		TEST_METHOD(NextIngredientTest)
		{
			Order testOrder;
			testOrder.addIngredient(testIngredient);
			Ingredients* temp = testOrder.nextIngredient();
			bool tempBool = (testIngredient->getName() == temp->getName());
			Assert::IsTrue(tempBool);
		}
		TEST_METHOD(NumOfIngredientTest)
		{
			Order testOrder;
			testOrder.addIngredient(bottomBun);
			testOrder.addIngredient(testIngredient);
			testOrder.addIngredient(topBun);
			Assert::AreEqual(1, testOrder.numOfIngredient("Ketchup"));
		}
		TEST_METHOD(GetAndSetHasDrinkTest)
		{
			Order testOrder;
			testOrder.setHasDrink(true);
			Assert::IsTrue(testOrder.getHasDrink());
		}
		TEST_METHOD(GetAndSetHasFriesTest)
		{
			Order testOrder;
			testOrder.setHasFries(true);
			Assert::IsTrue(testOrder.getHasFries());
		}
	};
}
