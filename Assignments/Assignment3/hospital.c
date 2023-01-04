#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "string.h"
#include "populateRecords.h"
#include "patient.h"
#include "employee.h"
//prototype Functions for the menu
int menu();


int main(int argc, char *argv[])
{

	struct person *person = NULL;
	int numRecords;         // number of records to be created
	char rc = 0;

	// check the command line parameters for correct number of paramaters
	// if the number is wrong prompt for correct usage and quit
	if(argc != 2){
		printf("Incorrect number of arguments. Expected 2. Recieved %d.\n", argc);
		printf("Arguments should be formatted as \"./hospital n\", where n is the number of records");
		return(1);
	}else{
		numRecords = atoi(argv[1]);
		printf("Creating %d records.\n", numRecords);
	}
	

	// populating the array person with data of patients and employees
	person = malloc(numRecords * sizeof(*person));
	populateRecords(person, numRecords);


	//goto label to loop menu after each option	
	MENU:
	printf("\nPlease select an option\n");
	//sets the option to the users input
	int option = menu();
	if(option < 0 || option > 5){
		printf("Option not Valid. Please select again.\n");
		goto MENU;
	}
	
	//checks the selected option
	switch(option){
		case 0:
			printf("Are you sure you want to quit?(y/n)\n");
			char confirmation[1];
			scanf("%1s", confirmation);
			//checks for correct y/n input
			if(strcmp(confirmation, "y") && strcmp(confirmation, "n")){
				printf("Input is not y/n. Going back to menu.\n");
				goto MENU;
			}
			//checks for n input
			else if(!strcmp(confirmation, "n")){
				printf("Going back to menu\n");
				goto MENU;
			}
			//quits as input must be y
			printf("Quitting...\n");
			return 0;
		break;
		case 1:
			printEmployees(person, numRecords);			
			goto MENU;	
		break;
		case 2:
			printPatients(person, numRecords);
			goto MENU;	
		break;
		case 3:
			printEmployeesSummary(person, numRecords);
			goto MENU;	
		break;
		case 4: 
			printPatientSummary(person, numRecords);
			goto MENU;	
		break;
		case 5:
			//prints the sizes of each structure in bytes
			printf("Size of structures\n");
			printf("Size of PersonRec = %ld\n", sizeof(*person));
			printf("Size of EmployeeRec = %ld\n", sizeof(EmployeeRec));
			printf("Size of PatientRec = %ld\n", sizeof(PatientRec));
			goto MENU;	
		break;
		default:
			printf("Unknown Input. Please try again.");
			goto MENU;	

	}
	//frees the person array
	free(person);
	return 0;
}

int menu(){
	//prints the menu
	printf("1. Print all Employees\n");
	printf("2. Search for all patients by Family Name\n");
	printf("3. Summary of Employee Data\n");
	printf("4. Summary of Patient Data\n");
	printf("5. Size of Structures(PersonRec, PatientRec and EmployeeRec)\n");
	
	printf("0. Quit\n");
	
	//scans for user input
	int option;
	scanf("%d", &option);
	return option;

}

