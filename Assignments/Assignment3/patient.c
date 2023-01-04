

#include "string.h"
#include "stdio.h"
#include "patient.h"



/********************************************************************/
//prints a single patient
void printPatient(PersonRec person)
{	
	//stores patient name
	char patientName[33] = "";
	strcat(patientName, person.firstName);
	strcat(patientName, " ");
       	strcat(patientName, person.familyName);
	//stores the total cost to date of a patient
	int totalCost = person.patient.numDaysInHospital * person.patient.dailyCost;
	printf("%-33sdept: %d days in hospital:%3d severity: %d daily cost:%3d total cost:%5d\n", patientName, person.patient.department, person.patient.numDaysInHospital, person.patient.severity, person.patient.dailyCost, totalCost);
}

/********************************************************************/
//prints all people who are patients and whos family name is the one given by the input
void printPatients(PersonRec *person, int numRecords)
{
	char searchName[15];
	printf("Enter Patient Family Name: \n");
	scanf("%15s", searchName);

	printf("Patient List\n");	
	for(int i = 0; i < numRecords; i++){
		if(person[i].emplyeeOrPatient == 1 && !strcmp(person[i].familyName, searchName)){
			printPatient(person[i]);	
		}
	}

}


/********************************************************************/
//prints a summary of all patients
void printPatientSummary(PersonRec *person, int numRecords)
{
	//stores the number of patients per department and total
	unsigned char patNum1 = 0;
	unsigned char patNum2 = 0;
	unsigned char patNum3 = 0;
	unsigned char patNum4 = 0;
	unsigned char patNum5 = 0;
	unsigned char patNum6 = 0;
	unsigned char patNum = 0;

	//stores cost to date of patients per dep and total
	float total1 = 0;
	float total2 = 0;
	float total3 = 0;
	float total4 = 0;
	float total5 = 0;
	float total6 = 0;
	float total = 0;

	//stores total daily cost of patients per dep and total
	float daily1 = 0;
	float daily2 = 0;
	float daily3 = 0;
	float daily4 = 0;
	float daily5 = 0;
	float daily6 = 0;
	float daily = 0;

	//stores avg daily cost of patients per dep and total
	float avg1 = 0;
	float avg2 = 0;
	float avg3 = 0;
	float avg4 = 0;
	float avg5 = 0;
	float avg6 = 0;
	float avg = 0;

	//loops through each person and adds information to previous variables
	for(int i = 0; i < numRecords; i++){
		if(person[i].emplyeeOrPatient == 1){
			//add to number of patients, total, and daily 
			patNum++;
			total += person[i].patient.dailyCost * person[i].patient.numDaysInHospital;
			daily += person[i].patient.dailyCost;
			//checks dep number and adds to the corresponding variables
			switch (person[i].patient.department){
				case 1:
					patNum1++;
					total1 += person[i].patient.dailyCost * person[i].patient.numDaysInHospital;
					daily1 += person[i].patient.dailyCost;
				break;
				case 2:
					patNum2++;
					total2 += person[i].patient.dailyCost * person[i].patient.numDaysInHospital;
					daily2 += person[i].patient.dailyCost;
					
				break;
				case 3:					
					patNum3++;
					total3 += person[i].patient.dailyCost * person[i].patient.numDaysInHospital;
					daily3 += person[i].patient.dailyCost;
				break;
				case 4:					
					patNum4++;
					total4 += person[i].patient.dailyCost * person[i].patient.numDaysInHospital;
					daily4 += person[i].patient.dailyCost;
				break;
				case 5:					
					patNum5++;
					total5 += person[i].patient.dailyCost * person[i].patient.numDaysInHospital;
					daily5 += person[i].patient.dailyCost;
				break;
				case 6:					
					patNum6++;
					total6 += person[i].patient.dailyCost * person[i].patient.numDaysInHospital;
					daily6 += person[i].patient.dailyCost;
				break;
			
			}
		}
	}
	//calculates average total cost to date
	avg = total/patNum;
	//calculates avg daily cost
	avg1 = daily1/patNum1;
	avg2 = daily2/patNum2;
	avg3 = daily3/patNum3;
	avg4 = daily4/patNum4;
	avg5 = daily5/patNum5;
	avg6 = daily6/patNum6;

	printf("Patient Summary: \n");	
	printf("Total number of patients: %3d total cost-to-date: %9.2f average cost per patient to-date:%7.2f\n", patNum, total, avg);
	
	printf("\nSummary by Department\n");
	printf("Department[1] - patients:%3d cost-to-date:%7.2f daily cost:%7.2f average daily cost per patient:%7.2f\n", patNum1, total1, daily1, avg1);
	printf("Department[2] - patients:%3d cost-to-date:%7.2f daily cost:%7.2f average daily cost per patient:%7.2f\n", patNum2, total2, daily2, avg2);
	printf("Department[3] - patients:%3d cost-to-date:%7.2f daily cost:%7.2f average daily cost per patient:%7.2f\n", patNum3, total3, daily3, avg3);
	printf("Department[4] - patients:%3d cost-to-date:%7.2f daily cost:%7.2f average daily cost per patient:%7.2f\n", patNum4, total4, daily4, avg4);
	printf("Department[5] - patients:%3d cost-to-date:%7.2f daily cost:%7.2f average daily cost per patient:%7.2f\n", patNum5, total5, daily5, avg5);
	printf("Department[6] - patients:%3d cost-to-date:%7.2f daily cost:%7.2f average daily cost per patient:%7.2f\n", patNum6, total6, daily6, avg6);
}
