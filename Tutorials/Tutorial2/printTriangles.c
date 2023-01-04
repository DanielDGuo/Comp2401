/* File is printTriangles.c

Purpose: file is for tutorial 2 to explore recursion


Revision:
a. Initial code - Doron Nussbaum 14/9/2020

*/

/************************************************************************/

// INCLUDE FILES

#include "stdio.h"
#include "stdlib.h"


/************************************************************************/
// FUNCTION PROTOTYPES

int printTriangleRecursive(unsigned int numRows);
int printTriangleRecursiveUpsidedown(unsigned int numRows);
int printTriangleRecursiveCountStars(unsigned int numRows, int *numStars);
int print_triangle(unsigned int numRows);

/************************************************************************/


int main()
{

    unsigned int numRows=7;
	int numStars;

	printf("printing a triangle with %d rows \n",numRows);
	printTriangleRecursive(numRows);
 
	printf("\nprinting a triangle upside down with %d rows \n\n",numRows);
	printTriangleRecursiveUpsidedown(numRows);

	printf("\nprinting a triangle with %d rows and counting the number of stars\n\n",numRows);
	printf("the number of printf * should be %d \n", (1+numRows)*numRows/2);
	printTriangleRecursiveCountStars(numRows, &numStars);
	printf("\nthe number of * returned by the function is %d\n\n",numStars);

	return(0);
}


/***********************************************************************************/
/* Purpose: prints a triangle using '*'

input:
numRows - the number of rows that the triangle should have

output:
none

return:
0


*/


int printTriangleRecursive(unsigned int numRows)
{
	if (numRows==1){
		printf("*\n");
		return(0);
	}
	printTriangleRecursive(numRows-1);
	int i=0;
	while(i<numRows){
	printf("*");
	i++;
	}
	printf("\n");
    return(0);
}


/***********************************************************************************/
/* Purpose: prints a triangle using '*' and computes how many '*' were printed

input:
numRows - the number of rows that the triangle should have

output:
numStars - the number of stars that were printed

return:
0
*/


int printTriangleRecursiveCountStars(unsigned int numRows, int *numStars)
{
	int currentStars = 0;
	if (numRows==1){
                printf("*\n");
                return(1);
        }
        currentStars += printTriangleRecursiveCountStars(numRows-1, &*numStars);
	int i=0;
        while(i<numRows){
        	printf("*");
		currentStars++;
        	i++;
        }
        printf("\n");
	*numStars = currentStars;
    return(currentStars);
}




/***********************************************************************************/
/* Purpose: prints a triangle using '*' with the base as the first row

input:
numRows - the number of rows that the triangle should have

output:
none

return:
0
*/


int printTriangleRecursiveUpsidedown(unsigned int numRows)
{
	if (numRows==1){
                printf("*\n");
                return(0);
        }
        int i=0;
        while(i<numRows){
        	printf("*");
        	i++;
        }
        printf("\n");
	printTriangleRecursiveUpsidedown(numRows-1);
	return(0);
}

