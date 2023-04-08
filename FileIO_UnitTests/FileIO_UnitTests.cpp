#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>

extern "C" {
#include "FileIO.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace FileIOUnitTests
{
	TEST_CLASS(FileIOUnitTests)
	{
	public:
		
		// Exception test to see if invalid file names are blocked
		TEST_METHOD(FIO_TEST_1)
		{
			// Initialize testing variables
			PARTICIPANT testTournament[2];
			testTournament[0].id = 1;
			strcpy_s(testTournament[0].name, "You");
			testTournament[1].id = 2;
			strcpy_s(testTournament[1].name, "Me");
			// invalid file name that should be rejected
			char invalidNameInput[4] = { 'd', '@', 't', 'a' };
			bool result = Save(testTournament, 2, invalidNameInput);
			Assert::AreEqual(false, result);
		}

		// Functional test checks whether tournament of size 2 can be
		// saved successfully
		TEST_METHOD(FIO_TEST_2)
		{
			// Initialize testing variables
			PARTICIPANT testTournament[2];
			testTournament[0].id = 1;
			strcpy_s(testTournament[0].name, "You");
			testTournament[1].id = 2;
			strcpy_s(testTournament[1].name, "Me");
			// create valid file name that will be accepted by the function
			char validNameInput[4] = { 'd', 'a', 't', 'a' };
			bool result = Save(testTournament, 2, validNameInput);
			Assert::AreEqual(true, result);
		}

		// Functional test checks whether tournament of size 4 can be
		// saved successfully
		TEST_METHOD(FIO_TEST_3)
		{
			// Initialize testing variables
			PARTICIPANT testTournament[4];
			testTournament[0].id = 1;
			strcpy_s(testTournament[0].name, "You");
			testTournament[1].id = 2;
			strcpy_s(testTournament[1].name, "Me");
			testTournament[2].id = 3;
			strcpy_s(testTournament[2].name, "They");
			testTournament[3].id = 4;
			strcpy_s(testTournament[3].name, "He");
			// create valid file name that will be accepted by the function
			char validNameInput[4] = { 'd', 'a', 't', 'a' };
			bool result = Save(testTournament, 4, validNameInput);
			Assert::AreEqual(true, result);
		}
	};
}
