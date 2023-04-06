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
			const int NUM_PARTICIPANTS = 10;

			PARTICIPANT participants[NUM_PARTICIPANTS];
			random(participants, NUM_PARTICIPANTS);

			// Check that each participant has a unique id
			for (int i = 0; i < NUM_PARTICIPANTS; i++) {
				for (int j = i + 1; j < NUM_PARTICIPANTS; j++) {
					Assert::AreNotEqual(participants[i].id, participants[j].id);
				}
			}

			// Check that each id is within the range of 1 to 10 times the number of participants
			for (int i = 0; i < NUM_PARTICIPANTS; i++) {
				Assert::IsTrue(participants[i].id >= 1 && participants[i].id <= NUM_PARTICIPANTS * 10);
			}
		}

		TEST_METHOD(TestManualFunction_SingleParticipant)
		{
			PARTICIPANT participants[1];
			int num = 1;

			// Act
			mannual(participants, num);

			// Assert
			Assert::AreNotEqual(participants[0].id, 0);
		}

		TEST_METHOD(TestManualFunction_MultipleParticipants)
		{
			// Arrange
			PARTICIPANT participants[3];
			int num = 3;

			// Act
			mannual(participants, num);

			// Assert
			Assert::AreNotEqual(participants[0].id, 0);
			Assert::AreNotEqual(participants[1].id, 0);
			Assert::AreNotEqual(participants[2].id, 0);
			Assert::AreNotEqual(participants[0].id, participants[1].id);
			Assert::AreNotEqual(participants[0].id, participants[2].id);
			Assert::AreNotEqual(participants[1].id, participants[2].id);
		}

    };
}