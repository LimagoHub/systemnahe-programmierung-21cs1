#include <stdio.h>
#include <malloc.h>
#include <string.h>


int main()
{
	

	
	// Deklaration
	double feld[] = { 3.14, 1.41, -9.0 };

	double* feldptr;
	
	feldptr = feld;
	
	printf("%f\n", feld[0]);
	printf("%f\n", *feld);
	printf("%f\n", feldptr[0]);
	printf("%f\n\n", *feldptr);

	printf("%f\n", feld[1]); // feld(4000) + sizeof(double) * Wert in der Klammer
	printf("%f\n", *(feld+1));
	printf("%f\n", feldptr[1]);
	printf("%f\n", *(feldptr+1));

}
