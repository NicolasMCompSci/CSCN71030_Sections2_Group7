#include "pch.h"
#include <stdbool.h>
#include "CppUnitTest.h"

extern "C" {
#include "numInput.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SizeSelectorUnitTests
{
	TEST_CLASS(SizeSelectorUnitTests)
	{
	public:
		
		TEST_METHOD(SIZE_TEST_1)
		{
			int size = sizeOfTournament(5, true);
			int expectedSize = 8;
			Assert::AreEqual(size, expectedSize);
		}
		TEST_METHOD(SIZE_TEST_3) 
		{
			int size = sizeOfTournament(68, true);
			int expectedSize = 64;
			Assert::AreEqual(size, expectedSize);
		}
	};
}
