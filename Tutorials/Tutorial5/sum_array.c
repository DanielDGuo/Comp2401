
#include "stdio.h"
#include "stdlib.h"

int computeD1Sum(int sizeD2, float arr[][sizeD2], int D1Index);

int main(int argc, char* argv[])
{
	int i, j, k;
	int count = 0;

	float arr2D[3][6];
	float arr3D[4][5][6];



	// populate the array arr2D
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 6; j++) {
    			arr2D[i][j] = count;
			//added in
			printf("array[%d][%d] is %f \n", i, j, arr2D[i][j]);
			//end of additions
			count++;
		}
	}

	// populate the array arr3D

    count = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 5; j++) {
			for (k = 0; k < 6; k++) {
				arr3D[i][j][k] = count;
				 //added in
                	        printf("array[%d][%d][%d] is %f \n", i, j, k, arr3D[i][j][k]);
          	              //end of additions
				count++;
			}
		}
	}


    // call the function to compute the sum arr2D[2]
    printf("%d", computeD1Sum(6, arr2D, 2));


    // print the sum of arr3D[2]

    
    return 0;
}
//sizeD2 is the number of elements in the 2nd dimention.
//d1Index is the index at which the sum of the elements are to be computed
int computeD1Sum(int sizeD2, float arr[][sizeD2], int d1Index){
	int sum = 0;

	for(int i = 0; i < sizeD2; i++){
		printf("arr[%d][%d] is %f \n",d1Index, i, arr[d1Index][i]);
		sum += arr[d1Index][i];
	}
	return(sum);
}

int computeD2Sum(float arr[][][], int d2Index){
	int sum = 0;
	for(int i = 0; i < ){
		sum += computeD2Sum(5, arr[2])
	}
}
