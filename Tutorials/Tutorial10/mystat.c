// FILE is mystat.c

// FILE is person.c

/* Purpose: computes basic stats related to person records 


Revisions:
when    Who                 What
2022,   Doron Nussbaum      Initial version


/********************************************/
// INCLUDE
#include <stdio.h>
#include <stdlib.h>

#include "mystat.h"

/********************************************/

/* purpose: compute the avarge value of of an array of floats.
 
 input
 arr - the array
 size - the number of records in the array
 
 */

void average(float *arr, int size, float *average)
{
  int i;
  *average = 0;

  for (i = 0; i < size; i++, arr++) {
    *average += *arr;
  }
  *average /= size;
}
