// files is arrays.c
/* The program in this file accepts grades and computes the aveage GPA.
it then removes low grades and computes that average GPA
 
 */

#include "stdio.h"
#include "stdlib.h"
#include "math.h"



/*************************************************************************/

/* DEFINE */
#define ARR_SIZE  20


/**********************************************************************/

/* PROTOTYPES */

int populateArray(int numbers[], int maxArrSize, int* arrSize);
int removeValues(int numbers[], int minValue, int* arrSize);
int isPalindrome(int numbers[], int arrSize);
int printArray(int numbers[], int arrSize);
float computeAvgGPA(int arr[], int arrSize);
int computeStdDev(int arr[], int arrSize, float *stdDev);


/**********************************************************************/




int main(int argc, char* argv[])
{
    
    int gpa[ARR_SIZE];
    int arrSize;
    float avgGpa = 0; 
    float stdDev = 0; 


    // populate the array with numbers
    populateArray(gpa, ARR_SIZE, &arrSize);
    printf("The courses grades are: \n");
    printArray(gpa, arrSize);

    // compute the average gpa
    avgGpa = computeAvgGPA(gpa, arrSize);
    
    // compute the standard deviation
    computeStdDev(gpa, arrSize, &stdDev);
    
    // print the number of courses and the average gpa
    printf("The number of courses = %d average GPA = %5.2f  standard deviation = %5.2f\n", arrSize ,avgGpa, stdDev);


    printf("Removing all gpa elements smaller than 7 \n");
    removeValues(gpa, 7, &arrSize);
    printf("The grades with grades >= 7 are:\n");
    printArray(gpa, arrSize);

    // compute the average gpa
    avgGpa = computeAvgGPA(gpa, arrSize);
    
    stdDev = 0;
    // compute the standard deviation
    computeStdDev(gpa, arrSize, &stdDev);
    
    // print the number of courses and the average gpa
    printf("The number of courses = %d average GPA = %5.2f  standard deviation = %5.2f\n", arrSize ,avgGpa, stdDev);


  
  
}


/************************************************************************/

/* Purpose: compute the average gpa of the array
input
	arr - the array of numbers
	arrSize - the size of arr
output
	avg - the average of the elements of the array
assumptions
	the array has only number based datatypes
	the array is initialized
	the user is friendly
*/

float computeAvgGPA(int arr[], int arrSize)
{
	//initializes average variable
	float avg = 0;
	//adds each element in the array to the average
	for(int i = 0; i < arrSize; i++){
		avg += arr[i];    
	}
	//divides the average variable by the number of elements
	avg = avg/arrSize;
    return(avg);
}




/************************************************************************/
/*
numbers - the array of numbers
maxArrSize - the numbers of elements in the array

output :
    numbers - the modified array
    arrSize - the number of elements in the array after the array was populated

Assumptions:
the user is a friendly user - there is no need to check input or clear the buffer
*/
int populateArray(int *numbers, int maxArrSize, int *arrSize)
{	
	int checker;
	//for until i reaches the max array size
	for(int i = 0; i<maxArrSize; i++){
		//stores the scan to the checker
		scanf("%d", &checker);
		if(checker == -1){
			//if the checker is equal to -1, stop the loop
			break;
		}
		//set an index in numbers to checker
		numbers[i] = checker;
		//add 1 to the size
		*arrSize += 1;
	}
    return(0);
}




/************************************************************************/

/*
Purpose: remove all number that are smaller than the given min value.
For example if minValue is 5 then all number in the array that are smaller than 5 are to be removed.

input:
numbers - the array of numbers
minValue - the value
arrSize - the numbers of elements in the array

output:
numbers - the modified array
arrSize - the number of elements in the array after the values were removed

return
0 

*/


int removeValues(int numbers[], int minValue, int* arrSize)
{
	int invalid=1;
	for(int i = 0; i < *arrSize; i++){
		//preemptively sets a flag
		invalid = 1;
		//if the current element is invalid, trim the array
		if(numbers[i]<minValue){
			while(invalid){
				if(numbers[*arrSize-1]<minValue){
					*arrSize-=1;
				}else{
					invalid = 0;
				}
			}
		//after trimming, set the element to the value of the last, and reduce the size
		numbers[i] = numbers[*arrSize-1];
		*arrSize-=1;
		}
	}
	return(0);
}


/************************************************************************/

/*
Purpose: prints the array


input:
numbers - the array of numbers
arrSize - the numbers of elements in the array


return
0 
*/


int printArray(int numbers[], int arrSize)
{
	//for each element, print it and a whitespace
	for(int i = 0; i < arrSize; i++){
		printf("%d ", numbers[i]);
	}
	//make a new line
	printf("\n");
	return(0);

}



/************************************************************************/

/*
Purpose: computes the standard deviation of the grades


input:
arr - the array of integers
arrSize - the numbers of elements in the array

output:
stdDev - the standard deviation of the grades
return
0 
*/


int computeStdDev(int arr[], int arrSize, float *stdDev)
{	
	//initializes the deviation
	float deviation = 0;
	//for each element, find its deviation from the mean, then add it
	for(int i = 0; i < arrSize; i++){
		deviation += pow(arr[i]-computeAvgGPA(arr, arrSize), 2);
	}
	//find the standard deviation with the average deviation
	*stdDev = sqrt(deviation/arrSize);
	return(0);
}





