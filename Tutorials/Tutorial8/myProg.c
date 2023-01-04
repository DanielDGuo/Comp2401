#include "stdio.h"
#include "stdlib.h"

int main()

{
	int *p = NULL;
	long *p1 = NULL;

	p = (int *) malloc(sizeof(int) * 3);	// alocated 3 integers
	p1 =  (long *) calloc(sizeof(long), 3);	// allocate 3 long integers

	
	free(p);
	free(p1);
	return(0);
}
