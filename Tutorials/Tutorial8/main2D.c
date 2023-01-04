/*
FILE IS main2D.c

Purpose:
a. Practice memory allocation of a 2D array and populating it.

Description:
See tutorial notes

History:
20/1/2018 Doron Nussbaum modified the file

2018 copyright Doron Nussbaum

*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


#define DIM_1   10 
#define DIM_2    5 



int main(int argc, char **argv)

{

    int i,j;
    int count = 0;
    int rc = 0; 
    int **arr = NULL;

    
    // allocate memory for the arrray of pointers to int array
    // the array has to have DIM_1 elements where each element is an int *
    arr = (int **) malloc(sizeof(int *) * DIM_1);
	if(arr == NULL){
		printf("array not intialized properly");
		return(1);
	}

    // initialize the pointers to NULL
    for (i = 0; i < DIM_1; i++) arr[i] = NULL;
        
    
    // allocate memory for each element in the array arr
    // each element should contains the address of a 1D array of DIM_2 elements each of type int 
    for (i = 0; i < DIM_1; i++) {
        arr[i]= (int *) malloc(sizeof(int) * DIM_2);
	if(arr[i] == NULL){
		printf("2D array not initialized properly");
		return 1;
	}
    }

    
    // populate the array (using 2 for loops) 
    count = 1;
	for(i = 0; i < DIM_1; i++){
		for(j = 0; j < DIM_2; j++){
			arr[i][j] = count;
			count++;
		
		}
	}
    for(i = 0; i < DIM_1; i++){
		for(j = 0; j < DIM_2; j++){
			printf("%d\n",arr[i][j]);
		}
	}
	
   for(i = 0; i < DIM_1; i++){
   	free(arr[i]);
   } 
   free(arr);
    return(0);
}


