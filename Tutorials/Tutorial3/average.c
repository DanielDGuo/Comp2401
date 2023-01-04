

#include "stdio.h"
#include "average.h"

/* computes the average of two numbers
 *  
 * 
 *
 * input:
 * x - the first number 
 * y - the last number  
 *
 * output:
 * average - the average of the two numbers
 *
 * return:
 * none 
 *
 *
 *  

 */

int average(int x, int y, float *average) {

    float sum;
    int i;

    sum = 0; 
  
    // compute the sum
    sum = x;
    for (i = 0; i < y; i++) {
        sum += 1;
    }

    // compute the average
    *average = sum /2;
    
    return (0);
}
