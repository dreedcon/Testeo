#include "Attributes.h"
#include "Utilities.h"

#include <iostream>
#include <map>
#include <string>

uint done = 0;
uint failed = 0;

#define TEST(msg, test) done++; printf("\t%s\t%s\n", !(##test) ? failed++,"FAIL" : "OK", msg)

int main()
{
	// Atributtes ---------------------

	printf("Testing Atributtes ...\n");
	Attributes atribBarbarian(55, 89, 15, 25, 2, 3, 1, 9);

	atribBarbarian.gainExp(1);
	TEST("test gainExp", atribBarbarian.whatIsyourExp() == 1);


	printf("\nFailures: %d/%d", failed, done);

	getchar();
	return 0;
}