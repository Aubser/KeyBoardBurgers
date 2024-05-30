#include "pch.h"
#include "CppUnitTest.h"
#include "../KeyBoardBurgers/Command.h"
#include "../KeyBoardBurgers/AddIngredientCommand.h"
#include "../KeyBoardBurgers/AddIngredientCommand.cpp"
#include "../KeyBoardBurgers/Invoker.h"
#include "../KeyBoardBurgers/Invoker.cpp"
#include <iostream>



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCommandPattern
{
	TEST_CLASS(TestCommandPattern)
	{
	public:
		Invoker invoker;
		PlayerActionController* playerActionControler = new PlayerActionController();
		Ingredients* testIngredient = new Ketchup();
		AddIngredientCommand* addIngredient = new AddIngredientCommand(playerActionControler, testIngredient);
		TEST_METHOD(TestIsEmpty)
		{
			Assert::IsTrue(invoker.isDoneEmpty());
		}
		TEST_METHOD(TestDoCommand)
		{
			invoker.doCommand(addIngredient);
			bool tempTest = invoker.isDoneEmpty();
			cout << tempTest;
			Assert::IsFalse(tempTest);
		}
		TEST_METHOD(TestUndo)
		{
			invoker.doCommand(addIngredient);
			invoker.undo();
			Assert::IsFalse(invoker.isUndoneEmpty());
		}
		TEST_METHOD(TestRedo)
		{
			invoker.doCommand(addIngredient);
			invoker.undo();
			invoker.redo();
			Assert::IsFalse(invoker.isDoneEmpty());
		}
	};
}