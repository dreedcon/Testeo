#include <stdlib.h>
#include <assert.h>


#include "DynArray.h"



int main()
{
	DynArray<int> Array1 = 2;
	Array1.Reallocate(Array1.getallocated_memory() + 1);

	bool resultado = (Array1.getallocated_memory() == 3);
	
	
	return 0;
}
	

