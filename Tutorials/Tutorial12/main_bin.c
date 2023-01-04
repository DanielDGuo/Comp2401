#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"

int fexists(char *fileName);

int main(int argc, char *argv[]) {

  struct personInfo person;
  FILE *fid;
  int i;
  int rc;


  // check if file exists
  rc = fexists("emp.bin");

  // print message depending whether the file exists
  if(rc){
	fid = fopen("emp.bin", "rb+");
	if(fread(&person, sizeof(struct personInfo), 1, fid)){
		person.salary[0] = 47500;
		person.salary[1] = 40000;
		person.salary[2] = 23000;
		person.salary[3] = 51000;
		person.salary[4] = 37000;
				
		printPerson(&person);
	}
	fseek(fid, 2* sizeof(struct personInfo), SEEK_CUR);		
	fwrite(&person, sizeof(struct personInfo), 1, fid);
	int currentPosition = ftell(fid);
	int recordNumber = currentPosition / sizeof(struct personInfo);
	printf("%d", recordNumber);
	fseek(fid, -sizeof(struct personInfo), SEEK_CUR);
		
	fread(&person, sizeof(struct personInfo), 1, fid);
	printPerson(&person);

	fclose(fid);
  }else{
  	printf("emp.bin not found\n");
  }

  return 0;
}

/************************************************************************/
// Return whether the given file exists in the current directory.
int fexists(char *fileName){

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

