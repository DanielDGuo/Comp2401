//includes
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "patient.h"
#include <sys/wait.h>

//prototypes
int morph(char *id, char *priorityLevel, char *medicalProblem);

int main(int argc, char* argv[]){
	int status;
	PatientInfo buffer[10];
	int i = 0;
	pid_t pids[10];

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
		//inserts info to the buffer then closes the file	
		while(!feof(file) && i <10){
			fread(&buffer[i], sizeof(struct patientInfo), 1, file);	
			i++;
		}
		fclose(file);
	}

	for (i=0; i<10; i++) {
		children[i] = fork();
			if (children[i] == 0) {
			
			char idStr[10];
			char priorityLevelStr[10];
	
			sprintf(idStr, "%u", (unsigned int)buffer.id);
			sprintf(priorityLevelStr, "%u", (unsigned int)buffer.priorityLevel);
			
			int mor = morph(idStr, priorityLevelStr, buffer.medicalProblem);
			return mor;			
			
			exit(0);
		}
	}

	for(i = 10; i > 0; i--){
		wait(&status);
		//number of days hospitalized
		int days = WEXITSTATUS(status);
		if(days > 0){
			printf("Patient %s %s id (%d) requires %d hospitalization days.\n"
					, buffer.firstName, buffer.familyName, buffer.id, days);
		}else{
			printf("Patient %s %s id (%d) does not need hospitalization.\n"
					, buffer.firstName, buffer.familyName, buffer.id);
		}
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
