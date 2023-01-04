#include "employee.h"
#include "stdio.h"
#include "string.h"


//prints the details of a single employee
void printEmployee(PersonRec person)
{
	//stores employee name	
	char employeeName[33] = "";
	strcat(employeeName, person.firstName);
	strcat(employeeName, " ");
       	strcat(employeeName, person.familyName);
	//stores salary to date
	float salaryToDate = person.emp.salary * person.emp.yearsService;
	//prints employee details
	printf("%-33sdept: %d salary:%9.2f position: %d years of service:  %2d salary to-date:%11.2f\n", employeeName, person.emp.department, person.emp.salary, person.emp.position, person.emp.yearsService, salaryToDate);
}

//checks all people in an array and prints only the employeees
void printEmployees(PersonRec *person, int numRecords)
{	
	printf("Hospital Employees\n");	
	//checks all people in given array, and prints employee details if they are an employee
	for(int i = 0; i < numRecords; i++){
		if(person[i].emplyeeOrPatient == 0){
			printEmployee(person[i]);	
		}
	}
}

//prints a summary of employees
void printEmployeesSummary(PersonRec *person, int numRecords)
{
	//stores number of employees per position and total
	unsigned char empNum0 = 0;
	unsigned char empNum1 = 0;
	unsigned char empNum2 = 0;
	unsigned char empNum3 = 0;
	unsigned char empNum = 0;
	
	//stores total employee salary per position and total
	float total0 = 0;
	float total1 = 0;
	float total2 = 0;
	float total3 = 0;
	float total = 0;
	
	//stores average employee salary per position and total
	float avg0 = 0;
	float avg1 = 0;
	float avg2 = 0;
	float avg3 = 0;
	float avg = 0;

	
	//checks if person is an employee
	for(int i = 0; i < numRecords; i++){
		if(person[i].emplyeeOrPatient == 0){
			//adds to total and number of total employees
			empNum++;
			total += person[i].emp.salary;
			//checks the position and adds to that positions total and number of employees
			switch (person[i].emp.position){
				case 0:
					empNum0++;
					total0 += person[i].emp.salary;
				break;
				case 1:
					empNum1++;
					total1 += person[i].emp.salary;
				break;
				case 2:
					empNum2++;
					total2 += person[i].emp.salary;
				break;
				case 3:
					empNum3++;
					total3 += person[i].emp.salary;
				break;
			
			}
		}
	}
	//calculates average
	avg = total/empNum;
	avg0 = total0/empNum0;
	avg1 = total1/empNum1;
	avg2 = total2/empNum2;
	avg3 = total3/empNum3;
	
	//prints summary
	printf("Employee Summary: \n");	
	printf("Total number of Employees: %3d total salary: %10.2f average salary:%8.2f\n", empNum, total, avg);
	
	printf("\nSummary by position\n");
	printf("position[0] - employees: %2d total salary: %9.2f average salary:%8.2f\n", empNum0, total0, avg0);
	printf("position[1] - employees: %2d total salary: %9.2f average salary:%8.2f\n", empNum1, total1, avg1);
	printf("position[2] - employees: %2d total salary: %9.2f average salary:%8.2f\n", empNum2, total2, avg2);
	printf("position[3] - employees: %2d total salary: %9.2f average salary:%8.2f\n", empNum3, total3, avg3);

}
