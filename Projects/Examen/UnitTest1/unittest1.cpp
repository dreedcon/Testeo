#include "stdafx.h"
#include "CppUnitTest.h"
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <iostream>

#include "../Examen/Point2D.h"
#include "../Examen/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(MethodCo)
		{

			String a("hello");
			String b("hello");

			Assert::IsTrue(a == b);
		}

		TEST_METHOD(MethodDi)
		{

			String a("hello");
			String b("hi");

			Assert::IsTrue(a != b);
		}

		TEST_METHOD(MethodDCo1)
		{

			String a("hello");
			char*  b("hello");

			Assert::IsTrue(a == b);
		}

		TEST_METHOD(MethodDi2)
		{

			String a("hello");
			char*  b("hi");

			Assert::IsTrue(a != b);
		}

		TEST_METHOD(MethodEq)
		{

			String a("hello");
			String b("helo");
			a = b;

			Assert::IsTrue(a == b);
		}

		TEST_METHOD(MethodEq1)
		{

			String a("hello");
			char* b("helo");
			a = b;

			Assert::IsTrue(a == b);
		}

		TEST_METHOD(MethodIn)
		{

			String a("hello");
			String b("hi");

			a += b;

			Assert::IsTrue(a == "hellohi");
		}

		TEST_METHOD(MethodIn1)
		{

			String a("hello");
			char* b("helo");

			a += b;

			Assert::IsTrue(a == "hellohelo");
		}

		TEST_METHOD(MethodLen)
		{
			String a("hello");
			Assert::IsTrue(strlen(a.string));
		}

		TEST_METHOD(Methodlen)
		{
			String a("hello");

			Assert::IsTrue(strlen(a.string));
		}

		TEST_METHOD(MethodCa)
		{
			String a("hello");
			Assert::IsTrue(strlen(a.string) - 1);
		}

		TEST_METHOD(MethodCl)
		{
			String a("hello");

			a.clear();

			Assert::IsTrue(a == "");
		}

		//-------------POINT2D---------------------

		TEST_METHOD(MethodSum)
		{
			Point2D <int>a(3, 2);
			Point2D <int>b(4, 2);
			Point2D <int>c;
			c = a + b;
			Assert::IsTrue((c.x == a.x + b.x) && (c.y == a.y + b.y));
		}

		TEST_METHOD(MethodSub)
		{
			Point2D <int>a(6, 3);
			Point2D <int>b(5, 8);
			Point2D <int>c;
			c = a - b;
			Assert::IsTrue((c.x == a.x - b.x) && (c.y == a.y - b.y));
		}

		TEST_METHOD(MethodIn0)
		{
			Point2D <int>a(1, 3);
			Point2D <int>b(5, 3);
			Point2D <int>c(1, 3);
			a += b;
			Assert::IsTrue((a.x == c.x + b.x) && (a.y == c.y + b.y));
		}

		TEST_METHOD(MethodDe)
		{
			Point2D <int>a(2, 5);
			Point2D <int>b(4, 8);
			Point2D <int>c(2, 5);
			a -= b;
			Assert::IsTrue((a.x == c.x - b.x) && (a.y == c.y - b.y));
		}

		TEST_METHOD(MethodEq2)
		{
			Point2D <int>a(2, 5);
			Point2D <int>b(3, 2);
			a = b;
			Assert::IsTrue((a.x == b.x) && (a.y == b.y));
		}

		TEST_METHOD(MethodCo3)
		{
			Point2D <int>a(4, 6);
			Point2D <int>b(2, 3);
			Assert::IsFalse((a.x == b.x) && (a.y == b.y));
		}
		TEST_METHOD(MethodDi1)
		{
			Point2D <int>a(9, 7);
			Point2D <int>b(9, 2);
			Assert::IsTrue((a.x != b.x) || (a.y != b.y));
		}


		TEST_METHOD(Method0)
		{
			Point2D <int>a(3, 0);
			Point2D <int>b(0, 2);
			Assert::IsFalse(((a.x == 0) && (b.x == 0)) && ((a.y == 0) && (b.y == 0)));
		}

		TEST_METHOD(Method00)
		{
			Point2D <int>a(0, 0);
			Point2D <int>b(0, 0);
			Assert::IsTrue(((a.x == 0) && (b.x == 0)) && ((a.y == 0) && (b.y == 0)));
		}
	

       };
	}