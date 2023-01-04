
#include <stdio.h>
#include <stdlib.h>

#include "classroom.h"

#define ARRAY_SIZE 20

int getClassFieldsToPopulate(int *numSeats, int *numProjectors, int *numBlackboards, int *accessible);
int get_random(int min, int max);


/***************************************************************************/


int main(int argc, char *argv[])
{
    int i;
	Classroom arr[ARRAY_SIZE];
	Classroom accessArray[ARRAY_SIZE];
	int accessArraySize = 0;
	int numSeats;
	int numBlackboards;
	int numProjectors;
	int accessibility;
    Classroom *p = NULL;


    // Populate the array.
    for (i = 0; i < ARRAY_SIZE; i++) {
		// get the fields to populate a class structure
		getClassFieldsToPopulate(&numSeats, &numProjectors, &numBlackboards, &accessibility);

		// initialize the fields of the current structure element in the array
		initClassroom(&arr[i], numSeats, numProjectors, numBlackboards, accessibility);
    }

    for (i = 0; i < ARRAY_SIZE; i++) {
		printClassroom(arr[i]);
    }

	printf("\n\n");

	int accessSize = copyAccessibleClasses(arr, accessArray, ARRAY_SIZE);
	for(int i = 0; i < accessSize; i++){
		printClassroom(accessArray[i]);
	}

  return 0;
}       
/********************************************************************/
// generates random numbers in the required ranges for the class fields
// output
// numSeats - number of seats
// numProjectors - number of projectors
// numBlacboards - number fo blackboards
// accessibile - determeins whether the class is accessible
//
int getClassFieldsToPopulate(int *numSeats, int *numProjectors, int *numBlackboards, int *accessible)
{
	*numSeats = get_random(10, 250);
	*numProjectors = get_random(0, 7);
	*numBlackboards = get_random(0, 3);
	*accessible = get_random(0, 2) != 0 ? 1 :0 ;


}

/********************************************************************/
//  generates a random number in a given range
//
//  input
//  min - minimum of range (positive value)
//  max - maximum of range (positive value)
//
//  return
//  a numbr in between min and max
int get_random(int min, int max)
{
	return (rand() % (max - min)) + min;
}
