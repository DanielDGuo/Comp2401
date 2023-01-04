

#include "stdio.h"
#include "sum.h"

/* computes the sum of values of all consectutive integers between two numbers
 * 
 *
 * input:
 * firstNum - the first number 
 * lastNum - the last number  
 *
 * output:
 * none
 *
 * return:
 * the sum of the all the numbers
 *
 *
 * assumptions:
 * 1. firstNum <= lastNum
 * 2. the value of lastNum <= 20 

 */

int sum(int firstNum, int lastNum) {

  int sum = 0;
  int i;
  
  for (i = firstNum; i <= lastNum; i++) {
	  sum += i;
  }
  return (sum);
}
