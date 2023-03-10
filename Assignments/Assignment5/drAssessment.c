/* 
   File is drAssessment.c

Purpose:
a program that assess patients medical condistion and
decides if it needs to be hospitalized and if so 
for how many days.
 

input via command line parameters:
id - the patient id
priorityLevel - the priority that was set by the triage nurse.
medicalProblem - the medical 
  
Usage 
programName patientId priority medicalProblem 

example

drAssessment 5637 3 "broken bone"




output:
0 - the patient does not need hospitalization
>0 - the number of hospitalization days
-1 - if the prioity is not in the range of 0-9
-2 - if the command line parameter is not correct 

Assumption:
the program does not check whether all input is correct

Notes:
1. The program must be linked with the file patien.o
2. The program may take time to complete due to simmulation
of medical procedures time
3. to bypass the time that the function takes use 
patientId = 99999999  


Notice:
Code can be used only for the assignment.  Other usages are not allowed

Copyright 2022 Doron Nussbaum


Revisions:
DN November, 2022 file created 

 */ 

/**************************************************************/
// INCLUDE FILES
//
#include "stdio.h"
#include "stdlib.h"
#include "patient.h"




/*************************************************************/
// PROTYPES
//
int isPrime(unsigned long number);


/*************************************************************/


int main(int argc, char *argv[])

{
    int i;

    unsigned int id;
    unsigned char priority;
    char* medicalProblem = NULL;
    int rc;
	printf("here");
    if (argc < 4) return(-2);
    sscanf(argv[1], "%u",&id);	// get the id
    sscanf(argv[2], "%hhu", &priority);  // get the priority
    medicalProblem = argv[3];
    if (priority < 0 || priority > 9) rc = -1;
    else {
        rc = patientAssessment(id, priority, medicalProblem);
    }
    return(rc);
}

