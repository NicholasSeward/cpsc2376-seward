#include "pch.h"
#include "CppUnitTest.h"
#include "mathyStuff.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace practice03test
{
	TEST_CLASS(practice03test)
	{
	public:
		
		TEST_METHOD(TestAdd1)
		{
			Assert::AreEqual(5, add(2,3));
		}
		TEST_METHOD(TestDouble1)
		{
			Assert::AreEqual(10, doubleValue(5));
		}
		TEST_METHOD(TestFancy1)
		{
			Rectangle r{ 3,4 };
			r.width++;

			Assert::AreEqual(16, r.area());
			Assert::AreEqual(4, r.width);
		}
	};
}
