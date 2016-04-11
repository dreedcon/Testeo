#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../DynArray2/Project6/DynArray.h"
#include "Assert.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynArray2
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethodReallocate)
		{
			DynArray<int> Array1= 2;
			Array1.Reallocate(Array1.getallocated_memory() +1);

			Assert::IsTrue(Array1.getallocated_memory() == 3);
		}

		TEST_METHOD(TestMethodPush_back)
		{
			DynArray<int> Array1(2);
			Array1.push_back(4);
			Array1.push_back(4);

			Assert::IsTrue(Array1.getallocated_memory() == 2);
		}

		TEST_METHOD(TestMethodPOP)
		{
			DynArray<int> Array1(6);
			Array1.push_back(4);
			Array1.Pop();

			Assert::IsTrue(Array1.getnum_elements() == 0);
		}
	};
}
