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


		TEST_METHOD(TestMannualTest_AllParticipantsGetUniqueNumbers)
		{
			PARTICIPANT participants[] = {
				{"Alice", 0},
				{"Bob", 0},
				{"Charlie", 0},
				{"Dave", 0},
				{"Eve", 0},
			};
			int num_participants = sizeof(participants) / sizeof(PARTICIPANT);

			// Create an array of unique numbers for testing
			int numbers[] = { 1, 2, 3, 4, 5 };

			// Call the mannualTest function
			mannualTest(participants, num_participants, numbers);

			// Check that all participants have unique numbers
			for (int i = 0; i < num_participants; i++) {
				for (int j = 0; j < num_participants; j++) {
					if (i != j) {
						Assert::AreNotEqual(participants[i].id, participants[j].id);
					}
				}
			}
		}
    };
}