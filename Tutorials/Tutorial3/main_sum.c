/* File is main.c
 *
 * Purpose: 
 * test the function sum()
 *
 */

#include "stdio.h"
#include "sum.h"


int main(int argc, char **argv)

{
    int firstNum;
    int lastNum;

    printf("Testing the sum function \n");

    // test 1 
	firstNum = 5;
	lastNum = 8;
	printf("test 1: testing sum(%d, %d) answer should be 26\n",firstNum,lastNum);
 	printf("sum(%d, %d)=%d\n \n",firstNum,lastNum,sum(firstNum,lastNum));

    // test 2 
	firstNum = 5;
	lastNum = 14;
	printf("test 2: testing sum(%d, %d) answer should be 95\n",firstNum,lastNum);
 	printf("sum(%d, %d)=%d\n \n",firstNum,lastNum,sum(firstNum,lastNum));

    // test 3 
	firstNum = 11;
	lastNum = 20;
	printf("tst 3 :testing sum(%d, %d) answer should be 155\n",firstNum,lastNum);
 	printf("sum(%d, %d)=%d\n \n",firstNum,lastNum,sum(firstNum,lastNum));

  
	return(0);
}


