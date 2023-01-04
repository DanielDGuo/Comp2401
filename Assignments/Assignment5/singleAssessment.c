//includes
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "patient.h"

//prototypes
int morph(char *id, char *priorityLevel, char *medicalProblem);

int main(int argc, char* argv[]){
	
	if(argc != 2){//incorrect number of arguments
		printf("Unexpected input. To use this program, provide binary file name.");
		return -2;
	}else{		
		FILE *file = NULL;

		file = fopen(argv[1], "rb");

		if(file == NULL){//file does not exist
			printf("File %s does not exist.", argv[1]);
			return -3;
		}

		PatientInfo buffer;
		//inserts info to the buffer then closes the file	
		fread(&buffer, sizeof(struct patientInfo), 1, file);	
		fclose(file);
		
		char idStr[10];
		char priorityLevelStr[10];

		sprintf(idStr, "%u", (unsigned int)buffer.id);
		sprintf(priorityLevelStr, "%u", (unsigned int)buffer.priorityLevel);
		

		int status = morph(idStr, priorityLevelStr, buffer.medicalProblem);
		return status;
	}
}

//input: id, priorityLevel, medicalProblem
//return: -1 if failed.
int morph(char *id, char *priorityLevel, char *medicalProblem){
	//args
	char *args[] = {"./drAssessment", id, priorityLevel, medicalProblem, NULL};
	
	int status = execvp("./drAssessment", args);
	
	if(status == -1){
		printf("execvp failed/n");
		return -1;
	}

	return 0;

}
