// FILE is classroom.h
//
// Purpose:
// contains declartion and function prototypes for manipulatging the Classroom
//
// Revisions:
// 2017 - Doron Nussbaum, file created

#ifndef CLASSROOM_HEADER  
#define CLASSROOM_HEADER  1



/**************************************************************/
// structure of a classrooom 
typedef struct classroom {
	int numSeats;		// number of seats
	int numProjectors;	// number of projectors in the classroom
	int numBlackboards;	// nummber of blackborads in the classroom
	int	accessibility;	// a flag detremines whehter the class is accessible
                        // if flag is 0 then no accessibility
						// if flag is 1 then class is accessbile 
} Classroom;


/**************************************************************/
// prototype

int initClassroom(Classroom *p, int numSeats, int numProjectors, int numBlackboards, int accessibility);
int printClassroom(Classroom p);
int copyAccessibleClasses(Classroom *in, Classroom *out, int size);
#endif


