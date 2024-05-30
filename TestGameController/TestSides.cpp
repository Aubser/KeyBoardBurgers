#include "pch.h"
#include "CppUnitTest.h"
#include "../KeyBoardBurgers/Sides.h"
#include "../KeyBoardBurgers/Sides.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSides
{
	TEST_CLASS(TestSides)
	{
	public:
		TEST_METHOD(GetAndSetAddedDrinkTest)
		{
			Sides testSides;
			testSides.setAddedDrink(true);
			Assert::IsTrue(testSides.getAddedDrink());
		}
		TEST_METHOD(GetAndSetAddedFriesTest)
		{
			Sides testSides;
			testSides.setAddedFries(true);
			Assert::IsTrue(testSides.getAddedFries());
		}
		TEST_METHOD(PassResetTest)
		{
			Sides testSides;
			testSides.setAddedDrink(true);
			testSides.setAddedFries(true);
			Assert::IsTrue(testSides.reset());
		}
	};
}