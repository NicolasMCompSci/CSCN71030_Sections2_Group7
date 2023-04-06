#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "organize.h"
#include "GenericInput.h"

}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OrganizeUnitTests
{
    TEST_CLASS(OrganizeUnitTests)
    {
    public:
		TEST_METHOD(TestRandomFunctionWithDifferentNum)
		{
			PARTICIPANT participants[5] = { {0, "Tom"}, {0, "Jerry"}, {0, "Mike"}, {0, "Mary"}, {0, "Lucy"} };
			int num1 = 5;
			int num2 = 10;

			random(participants, num1);
			int sum1 = 0;
			for (int i = 0; i < num1; i++) 
			{
				sum1 += participants[i].id;
			}

			random(participants, num2);
			int sum2 = 0;
			for (int i = 0; i < num2; i++) 
			{
				sum2 += participants[i].id;
			}

			Assert::AreNotEqual(sum1, sum2);
		}

		TEST_METHOD(TestRandomFunctionWithSameNum)
		{
			// Arrange
			PARTICIPANT participants[3] = { {0, "Tom"}, {0, "Jerry"}, {0, "Mike"} };
			int num = 3;

			// Act
			random(participants, num);
			int sum1 = 0;
			for (int i = 0; i < num; i++) 
			{
				sum1 += participants[i].id;
			}

			random(participants, num);
			int sum2 = 0;
			for (int i = 0; i < num; i++) 
			{
				sum2 += participants[i].id;
			}

			// Assert
			Assert::AreNotEqual(sum1, sum2);
		}

		TEST_METHOD(TestMannualValidInput)
		{
			PARTICIPANT participants[] = { {1, "Alice", 0}, {2, "Bob", 0}, {3, "Charlie", 0} };
			const int num = 3;

			mannual(participants, num);

			// Assert that each participant has been assigned a valid ID
			for (int i = 0; i < num; i++) 
			{
				Assert::IsTrue(participants[i].id > 0);
			}
		}

		TEST_METHOD(TestMannualInvalidInput)
		{
			PARTICIPANT participants[] = { {1, "Alice", 0}, {2, "Bob", 0}, {3, "Charlie", 0} };
			const int num = 3;

			// Simulate user input of invalid number
			char input[] = "invalid\n";
			int ret = scanf_s(input, "%d", &participants[0].id);
			mannual(participants, num);

			for (int i = 0; i < num; i++) {
				Assert::IsTrue(participants[i].id > 0);
			}
		}
	};

}
