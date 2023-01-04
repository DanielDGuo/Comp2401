// FILE main.c



/* Purpose: Contains the main function of the program

The objective is to use these files to demonstrate usage of the make utility


Revisions:
when    Who                 What
2022,   Doron Nussbaum      Initial version


/******************************************/

// INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"

/********************************************/
// DEFINE
#define NUM_PEOPLE 7

/********************************************/

int main(int argc, char *argv[])
{
  struct person people[NUM_PEOPLE];
  int i;
	float salary = 32000;
  // populate the array
  for (i = 0; i < NUM_PEOPLE; i++) {
    populate(&people[i]);
  }

  // print the array
  for (i = 0; i < NUM_PEOPLE; i++) {
    print(&people[i], 0);
  }
	processArray(people, NUM_PEOPLE, printHighSalary);
  return 0;
}
