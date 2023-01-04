#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "linked_list.h"


/***********************************************************/
/*
Purpose:  adds a record as the first node of the linked list 
input:
head - head of the list
data - a pointer to an Employee record

Output
head - the updated head of the list 

Return
0 - if data was successfully added to the list
1 - if node was not added to the list
*/


int addNode(ListNode **head, Employee *data)
{
	ListNode *p = NULL;

	p = malloc(sizeof(ListNode));
	if(p == NULL){
		return 1;
	}
	// Step 1 alllocate memory for the node and initialize all pointers to NULL
	// if an error then return 1

	p->data = data;
	// Step 2 assign the employee rec to data
	
	p->next = *head;
	// Step 3 update the next field of the new node to point to the first node in the list as a next node
	
	*head = p;
	// Step 4 update the list head to point to the new node.
     return 0;
}
/***********************************************************/
/*
Purpose:  prints the list from the first node to the last node
input:
head - head of the list

Output
None

Return
None
*/


void printList(ListNode *head) 
{
    // while list is not empty 
	while(head != NULL){
		printEmployee(head->data);
		head = head->next;	
	}
    // print the node
        // advance the list

}

/***********************************************************/
/*
Purpose:  prints the list from the first node to the last node usingf recursiion
input:
head - head of the list
emp - a pointer to an Employee record

Output
None

Return
None
*/


void printListRecursive(ListNode *head) 
{
	if(head != NULL){
		printEmployee(head->data);
		printListRecursive(head->next);
	}
	// check bounary conditions

	// do work 

	// condcut recursive call

}




/***********************************************************/
/*
Purpose:  prints the third last record in the list
input:
head - head of the list

Output
None

Return
0 if successful
1 if an error occur (e.g., list does not have three nodes)
*/


int printThirdLast(ListNode *head) 
{	
	if(head == NULL || head->next == NULL || head->next->next == NULL) return 1;
	
	
	if(head->next->next->next == NULL){
		printEmployee (head->data);
		return 0;
	}else{
		printThirdLast(head->next);
	}
	// check bounary conditions - here the recursion stops when the 
    // third last node record is reached.  Note that the list may 
    // not have three nodes

	// if nodes was reached then print the data 
 
	// else condcut recursive call
    // return the result of the recursive call

}

/***********************************************************/
/*
Purpose:  prints the list in reverse from the last node to the first node using recursiion
input:
head - head of the list

Output
None

Return
None
*/


void printListInReverse(ListNode *head) 
{

	// check bounary conditions

	// condcut recursive call

	// do work 

}




/***********************************************************/
/*
Purpose:  delete the first node from the linked list 
input:
head - head of the list

Output
head - the updated head of the list 
data - the data that was stroed in the record 

Return
none 
*/


void deleteNode(ListNode **head, Employee **data)
{

	ListNode *p = NULL;

    *data = (*head)->data;
	// Step 1 
    // if the list is empty then
    //     set data to NULL
    //     return
    // else set p to the point to the first node
	p = *head;
	// Step 2 assign the data in the node to the output data 
	*data = p->data;
	// Step 3 set the to point to the second node 
	*head = p->next;
	// Step 4 free the node pointed to by p
	free(p);
	p = NULL;
}
/***********************************************************/

