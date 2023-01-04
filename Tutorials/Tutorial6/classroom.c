#include <stdio.h>
#include <stdlib.h>

#include "classroom.h"


/*******************************************************/


// populate the classroom with fields

int initClassroom(Classroom *p, int numSeats, int numProjectors, int numBlackboards, int accessible)
{
	(*p).numSeats = numSeats;
	(*p).numProjectors = numProjectors;
	(*p).numBlackboards = numBlackboards;
	(*p).accessibility = accessible;

    return(0);

}

int printClassroom(Classroom p){
	printf("# Seats = %d, # projectors = %d, # blackboards = %d, classroom ", p.numSeats, p.numProjectors, p.numBlackboards);
	if(p.accessibility){
		printf("is accessible\n");
	}else{
		printf("not accessible\n");
	}


}

int copyAccessibleClasses(Classroom *inArray, Classroom *outArray, int size){
	int j = 0;
	for(int i = 0; i < size; i++){
		if((inArray[i]).accessibility && (inArray[i]).numProjectors){
			outArray[j] = inArray[i];
			j++;
		}
	}
	return j;
}


