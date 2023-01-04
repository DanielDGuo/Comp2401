
/* 
File name is linked_list_hospital.c
 Purpose: file contains functions for manipulating singly linked list
 
 Revisions
 Doron Nussbaum 2022 File created

 
 
 
 
 
 Copyright 2022 Doron Nussbaum
 
 */

/******************************************************************/
// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list_hospital.h"
#include "patient.h"


/************************************************************************/
// Define 



/************************************************************************/

/*
Purpose: insert a new node into the list as the first element
input
patient - the patient record

input/output
head - head of linked list

return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/

ListNode *insertToList(ListNode **head, PatientInfo *patient)

{
	//initiates and allocates node p
	ListNode *p = NULL;	
	p = malloc(sizeof(ListNode));
		if(p==NULL){
			printf("Not enough memory for insertToList().");
			return NULL;
		}
	//set the data in p to the pata given
	p->patient = *patient;
	//sets the next node to the head
	p->next = *head;
	//sets the head to p
	*head = p;
	return p;
}


/************************************************************************/
/*
Purpose: insert a new node into the list after the given node  

Input
input
patient - the patient record


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/


ListNode *insertAfter(ListNode *node, PatientInfo *patient)
{
	 
	//initiates and allocates node p
	ListNode *p = NULL;	
	p = malloc(sizeof(ListNode));
	if(p==NULL){
		printf("Not enough memory for insertAfter().");
		return NULL;
	}
	//set the data in p to the pata given
	p->patient = *patient;
	//sets the next node to the node after the one given
	p->next = node->next;
	//sets the node's next to p
	node->next = p;
	return p;
}




/************************************************************************/
/*
Purpose: search for the first patient with the matching priority
Input
head - the head of the list
priority - first priority of the patient

output
patient - the patient record

return
a pointer to the node that was found.
NULL - if no node was found or list empty

*/


ListNode * searchFirstPatientByPriority(ListNode *head, unsigned char priority, PatientInfo *patient)

{
	ListNode *p = NULL;
	p=head;
	if(p == NULL){
		printf("Error in searchFirstPatientByPriority()");
	}

	//while the current node isn't null, loop
	for(p=head; p != NULL; p=p->next){
		//return if same priority
		if((p->patient).priorityLevel == priority){
			(*patient) = p->patient;
			return p;
		}
	}
	//return NULL as default if no priority matches
	return NULL;

}

/************************************************************************/
/*
Purpose: search for the first patient with the matching criteria.  The criteria is determined
by the comparison function 
Input
head - the head of the list
findPatient -  a function pointer that returns a 0 if the patient's record matches that criteria

output
patient - the patient record

return
a pointer to the node that was found.
NULL - if no node was found or list empty

*/


ListNode * searchNextPatient(ListNode *head, int (*findPatient)(PatientInfo *), PatientInfo *patient)
{
	//initializes and allocs memory for p
	ListNode *p = NULL;
	patient = NULL;
	p = malloc(sizeof(ListNode));
	if(p==NULL){
		printf("not enough memory for searchNextPatient)");
		return NULL;
	}
	//while the current node isn't null, loop
	while(p != NULL){
		//return if matches criteria
		if(findPatient(&(p->patient))==0){
			*patient = p->patient;
			return p;
		}
		//go to next node if not
		p = p->next;
	}
	//return NULL as default if no mmatches
	return NULL;
}

/***************************************************************/

/*
Purpose: delete the first node from the list
Input
head - the head of the list

output
head - the head of the list
patient - the patient record


return

0 if node was deleted
1 if node was not deleted or list is empty

*/


int deleteFromList(ListNode **head, PatientInfo *patient)

{
	//initialize and allocate memory for p
	ListNode *p = NULL;
	p = *head;
	if(p == NULL){
		printf("not enough memory for deleteFromList");
		return 1;
	}
	//copy the data for output
	*patient = p->patient;
	//sets head to the next node and deletes p, the previous head
	*head = p->next;
	free(p);
	p = NULL;
	return 0;
}


/***************************************************************/

/*
Purpose: Retrieve the first node that matches the priority.  When found the node is deleted and the patient
information is provided. 

Input
head - the head of the list

output
head - the head of the list
patient - the patient record


return

0 if node was deleted  
1 if node was not found or list is empty 

*/


int retrieveNextPatientByPriority(ListNode **head, unsigned char priority, PatientInfo *patient)

{
	//initialize and allocate memory for p
	ListNode *p = NULL;
	ListNode *q = NULL;
	p = *head;
	q = p;
	if(p == NULL || q == NULL){
		printf("not enough memory for deleteFromList\n");
		return 1;
	}
	//traverse the list
	while(p->next != NULL){
		//if priority is equal, delete the node
		if((p->next->patient).priorityLevel == priority){
			//copy the data for output
			*patient = p->next->patient;
			//keep a handle on the element to be deleted
			q = p->next;
			//sets the next to the next next element, then deletes q
			p->next = p->next->next;
			free(q);
			q = NULL;
			return 0;
		}
		p = p->next;
	}
	return 1;
}

/***************************************************************/

/*
Purpose: Retrieve the patient with the highest criteria to be treated.  The maximum criteria is determined by 
a comparePatients function.  Once the patient is found it is deleted from the list and its information is 
returned. 

Input
head - the head of the list
comparePatients - this function takes two paitent records and compares them.  
				It returns, -1, 0 or 1 if p1 < p2, p1 == p2, or p1 > p2, respectively. 

output
head - the head of the list
patient - the patient record


return
0 if  patient was found and the node was deleted  
1 if no paitent was found or the list is empty 


Algorithm:
The function first finds the patient with the hights criteria by comparing all the patients records and 
finding the first patient with the maximum criteria to be treated.  It then deletes the patient and returns
its information. 
*/


int retrieveNextPatientByCriteria(ListNode **head, int (*comparePatients)(PatientInfo *p1, PatientInfo *p2, int currentTime), int currentTime, PatientInfo *patient)

{
        // check if list is empty
 	if(*head == NULL){
		return 1;
	}
	
	ListNode *highest = NULL;
 	ListNode *highestPrevious = NULL;
	ListNode *current = NULL;
	ListNode *currentPrevious = NULL;

	highest = *head;
	highestPrevious = highest;
	current = *head;
	currentPrevious = current;
	if(highest == NULL || highestPrevious == NULL || current == NULL || currentPrevious == NULL){
		printf("not enough memory for retriveNextPatientByCriteria");
		return 1;
	}
	//checks if the list is a single item
	if(current->next == NULL){
		*patient = current->patient;
		*head = NULL;
		return 0;
	}

	while(current != NULL){
		//if the current is higher, set the highest and highestPrevious to tthe current
		if(comparePatients(&(current->patient), &(highest->patient), currentTime) == 1){
			highest = current;
			highestPrevious = currentPrevious;
		}
		//traverse the list
		currentPrevious = current;
		current = current->next;
	}
	//skips the highest node and deletes it
	*patient = highest->patient;
	highestPrevious->next = highest->next;
	free(highest);
	highest = NULL;
	return 0;
}



/************************************************************************/
/*
Purpose: deletes all nodes from the list
input/output
head - the head of the list


*/


void deleteList(ListNode **head)
{
	ListNode *p = NULL;
	ListNode *pPrev = NULL;
	p = *head;
	pPrev = p;
	if(p == NULL || pPrev == NULL){
		printf("list empty or not enough space in deleteList()");
	}
	while(p != NULL){
		pPrev = p;
		p = p->next;
		free(pPrev);
		pPrev = NULL;
	}
	//free(p);
	//free(pPrev);
	//free(head);
}



/************************************************************************/
/*
Purpose: prints all the records in the list

input
head - the head of the list
myPrint - a function pointer for print the patient information. 
*/


void printList(ListNode *head, void (*myPrint)(PatientInfo *patient))
{
	ListNode *p=NULL;
	p = head;
	if(p == NULL){
		printf("list empty or not enough space in printList()");
	}
	while(p != NULL){
		myPrint(&(p->patient));
		p = p->next;
	}
}



/************************************************************************/
/*
Purpose: counts the number of patients that are waiting to be treted
input
head - the head of the list

return 
the number of registered patients

*/


int numPatientsInEmergency(ListNode *head)
{
	int counter = 0;	 
	ListNode *p=NULL;
	p = head;
	if(p == NULL){
		return 0;
	}
	//iterate over list
	while(p != NULL){
		counter++;
		p = p->next;
	}
	return counter;
}

/************************************************************************/
/*
Purpose: counts the number of patients with a matching priority
input
head - the head of the list


return 
the number of patients with a matching priority


*/


int countPatients(ListNode *head, unsigned char priority)
{
	int counter = 0;	 
	ListNode *p = NULL;
	p = head;
	if(p == NULL){
		return 0;
	}
	//iterate over list
	while(p != NULL){
		//checks priority
		if((p->patient).priorityLevel == priority){
			counter++;
		}
		p = p->next;
	}
	return counter;  
}



/************************************************************************/
/*

Purpose: store all the patients records in the file by printing out the information i.e., in ASCII readable format. 


input
filename - the name of the file to be used for storing the data
head - the head of the  list

Algorithm:
use the '$' character as a delimeter between the fields
For example:
Miya                 $Bronson                 $ 9700    $ 20  $ 2 $ Broken Bone 
*/

// Backup Functions
int createAsciiBackup(char *fileName, ListNode *head)

{
	// add code 

	// open the file

	// store each patient records in the file

	// close the file

    return(0);
}

/************************************************************************/
/*

Purpose: store all the patients records in the file in their binary format. 


input
filename - the name of the file to be used for storing the data
head - the head of the  list



*/

int createBinaryBackup(char *fileName, ListNode *head)
{
	// add code 

	// open the file

	// store each patient records in the file

	// close the file

    return(0);
}

////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

// BONUS SECTION



/************************************************************************/
/*

Purpose: removes all Patients with priority less than or equal to the given priority 
(remove all patients with priorityLevel <= priority).   


input
head - the head of the  list

Ouput
head - the head of the list where all patients with priorityLevel < priority are removed 

*/

int releasePatients(ListNode **head, unsigned char priority)

//same as retrieveNextPatient; uses <= instead of == and interates until the end.
{
	//initialize and allocate memory for p
	ListNode *p = NULL;
	ListNode *q = NULL;
	p = *head;
	q = malloc(sizeof(ListNode));
	if(p == NULL || q == NULL){
		printf("not enough memory for deleteFromList\n");
		return 1;
	}
	//traverse the list
	while(p->next != NULL){
		//if priority is equal, delete the node
		if((p->next->patient).priorityLevel <= priority){
			//keep a handle on the element to be deleted
			q = p->next;
			//sets the next to the next next element, then deletes q
			p->next = p->next->next;
			free(q);
			q = NULL;
		}
		return(0);
	}
}
/************************************************************************/
/*
Purpose: prints all the patients' records in the list in reverse order using recursion

input
head - the head of the list
*/


void printListReverse(ListNode *head, void (*myPrint)(PatientInfo *patient))
{
	//check if the firest element or if the next element is null
	if(head != NULL && head->next != NULL){
		//go to the next node
		printListReverse(head->next, myPrint);
	} 
 	
	if(head != NULL){
		myPrint(&(head->patient));
	}
    
 
}





/*****************************************************************************/

/************************************************************************/
/*
Purpose: Reverse the list such that the last node in the list becomes the first node and the first node in the list becomes the last node.  

Restrictions:
1.	This operation must be achieved using recursive calls
2.	No memory is to be allocated or released at any time during the execution of the function



input
head - the head of the list


Returns:
the head of the new list
*/

ListNode *reverse(ListNode *head)
{
	//checks if the first element is NULL and if the next element is NULL
	if(head == NULL || head->next != NULL){
		return head;
	}
	
	ListNode *p = NULL;
	p=reverse(head->next);
	if(p==NULL){
		printf("error in reverse()");
	}
	//sets the next node's next to the current node
	head->next->next = head;
	//removes the current link
	head->next = NULL;
	
	
	return p;
}




