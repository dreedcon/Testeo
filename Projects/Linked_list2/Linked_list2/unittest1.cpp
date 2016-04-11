#include "stdafx.h"
#include "CppUnitTest.h"
#include <Assert.h>
#include "../../Linked_List_enlazado/Linked_List_enlazado/Class_linked_list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Linked_list2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethodAdd)
		{
			
			List<int> List1;
			List1.Add(3);
			List1.Add(4);
			List1.Add(2);
			List1.Add(100);
		    
			Assert::IsTrue(List1.getlast()->value == 100);
		}

		TEST_METHOD(TestMethodDel)
		{

			List<int> List1;
			List1.Add(2);
			List1.Add(3);
			List1.Del(List1.getfirst());
		    
			Assert::IsTrue(List1.getfirst()->value == 3);
		
		}
	    
		TEST_METHOD(TestMethodClear)
		{
            List<int> List1;
			List1.Add(1); 
			List1.Add(2); 
			List1.Add(4);
			List1.Clear();
		
			Assert::IsTrue((List1.start == NULL) && (List1.finish == NULL));
		}
	  
	
	};
}