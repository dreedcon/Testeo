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

	atribBarbarian.gainExp(50);
	TEST("test gainExp", atribBarbarian.whatIsYourExp() == 50);

	atribBarbarian.update();
	TEST("test update", atribBarbarian.whatIsYourHp() == 57);
	TEST("test update", atribBarbarian.whatIsYourStam() == 92);
	TEST("test update", atribBarbarian.whatIsYourFury() == 16);
	TEST("test update", atribBarbarian.whatIsYourLevel() == 2);

	printf("\nFailures: %d/%d", failed, done);

	getchar();
	return 0;
}