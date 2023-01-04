/* File is main.c
 *
 * Purpose: 
 * test the function average()
 *
 */

#include "stdio.h"
#include "average.h"


int main(int argc, char **argv)

{
    int x;
    int y;
    float result;

    printf("Testing the average function \n");

    // test 1 
	x = 5;
	y = 7;
	printf("test 1: testing average(%d, %d) answer should be 6\n",x,y);
    average(x,y, &result);
 	printf("average(%d, %d)=%f\n \n",x, y, result);

    // test 2 
	x = 5;
	y = 4;
	printf("test 2: testing average(%d, %d) answer should be 4.5\n",x,y);
    average(x,y, &result);
 	printf("average(%d, %d)=%f\n \n",x, y, result);

	return(0);
}


