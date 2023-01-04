
/*************************************************************/

// INCLUDES 
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"

/*************************************************************/

// prototypes 

int fexists(char *fileName);
void readFile(FILE *fid);

/*************************************************************/

 
int main(int argc, char *argv[]) {

  FILE *fid;
  int rc=0;

  // check the number of command line parmeters 
  // if incorrect number print message and exits
  if (argc < 2) {
      printf("usage %s filename \n",argv[0]);
      return(1);
  }

  // check if file exists
  rc = fexists(argv[1]);

  // print message depending whether the file exists
  if(rc){
  	printf("file %s exists\n", argv[1]);
	fid = fopen(argv[1], "r");
	readFile(fid);	
  }else{
  	printf("file %s does not exist\n", argv[1]);
  }

  return 0;
}


/*********************************************************************/
// Return whether the given file exists in the current directory.
// 
// Input:
// fileName - name of fle
//
// Output:
// None
//
// Return:
// 0 if the file does not exist
// 1 if the file exists
//
int fexists(char *fileName)
{
    // add code

    FILE *fp = NULL;
    int rc = 0;

	fp = fopen(fileName, "r");
	if(fp == NULL){
		return 0;
	}
	fclose(fp);
	return 1;

 	// determine the recturn code
 

  // if applicable then close the file

    return(rc);
}




/*********************************************************************/
// Read the content of the file 
// 
// Input:
// fid - file handle 
//
// Output:
// None
//
// Return:
// 0 if the file does not exist
// 1 if the file exists
//
void readFile(FILE *fid)
{
	// while not end of file
	while(!feof(fid)){
		char firstName[30];
		char lastName[30];
		int age;
		fscanf(fid, "%30s %30s %d", firstName, lastName, &age);
		// read a values in a line
		// print the values to the screen 
		printf("%s %s %d\n", firstName, lastName, age);
	}
}
