#include "pch.h"
#include "CppUnitTest.h"
#include "../KeyBoardBurgers/NewCurrentLevel.h"
#include "../KeyBoardBurgers/NewCurrentLevel.cpp"
//#include "../KeyBoardBurgers/GameController.h"
//#include "../KeyBoardBurgers/GameController.cpp"
#include "../KeyBoardBurgers/Ketchup.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCurrentLevel
{
	TEST_CLASS(TestCurrentLevel)
	{
	public:
		NewCurrentLevel testGame;
		std::vector<Order*> testOrderVector;
		Ingredients* testIngredient = new Ketchup();
		Order* testOrder;
		Order* hasIngredientOrder = new Order();
		Order* testOrderTemp = new Order();
		int level = 7;
		int score = 340;
		int highScore = 570;
		//unable to run these tests since NewCurrentLevel has an attribute of databaseController which references managed classes
		TEST_METHOD(GetandSetLevelNumber)
		{
			testGame.setLevelNumber(level);
			Assert::AreEqual(testGame.getLevelNumber(), level);
		}
		TEST_METHOD(GetandSetScore)
		{
			testGame.setScore(score);
			Assert::AreEqual(testGame.getScore(), score);
		}
		TEST_METHOD(GetandSetHighScore)
		{
			testGame.setHighScore(highScore);
			Assert::AreEqual(testGame.getHighScore(), highScore);
		}
		TEST_METHOD(TestIncrementScore)
		{
			int score = testGame.getScore();
			testGame.incrementScore();
			Assert::AreEqual(testGame.getScore(), score + 1);
		}
		TEST_METHOD(TestDecrementScore)
		{
			int score = testGame.getScore();
			testGame.decrementScore();
			int newScore = testGame.getScore();
			Assert::AreEqual(newScore + 1, score);
		}
		TEST_METHOD(GetAndSetOrderVector)
		{
			testGame.setOrderVector(testOrderVector);
			Assert::IsTrue(testGame.getOrderVector() == testOrderVector);
		}
		TEST_METHOD(TestYesHasNext)
		{
			testOrderVector.push_back(testOrder);
			testGame.setOrderVector(testOrderVector);
			Assert::IsTrue(testGame.hasNext());
		}
		TEST_METHOD(TestNoHasNext)
		{
			testGame.reset();
			Assert::IsFalse(testGame.hasNext());
		}
		TEST_METHOD(TestNext)
		{
			testOrderTemp->addIngredient(testIngredient);
			testOrderVector.clear();
			testGame.reset();
			testOrderVector.push_back(testOrderTemp);
			testGame.setOrderVector(testOrderVector);
			Order temp = *testGame.next();
			while (temp.hasNextIngredient())
			{
				Assert::IsTrue(temp.nextIngredient()->getName() == testOrderTemp->nextIngredient()->getName());
			}
		}
		TEST_METHOD(TestCurrentOrder)
		{
			hasIngredientOrder->addIngredient(testIngredient);
			testOrderVector.push_back(hasIngredientOrder);
			testGame.setOrderVector(testOrderVector);
			Order store = *testGame.next();
			Order temp = *testGame.getCurrentOrder();

			while (temp.hasNextIngredient())
			{
				Assert::IsTrue(store.nextIngredient()->getName() == temp.nextIngredient()->getName());
			}
		}
		TEST_METHOD(TestReset)
		{
			testGame.setScore(10);
			testGame.setHighScore(20);
			testGame.setLevelNumber(3);
			testGame.reset();
			Assert::AreEqual(testGame.getScore(), 0);
			Assert::AreEqual(testGame.getHighScore(), 0);
			Assert::AreEqual(testGame.getLevelNumber(), 0);
		}
	};
}