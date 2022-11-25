#include <stdio.h>

#include "demo.h"


int z = 10;

int get_z()
{
	return z;
}

void set_z(int neuerwert)
{
	z = neuerwert;
}

/*static*/ void ausgabe() // static ist das "private" von c
{
	printf("Hallo");
}