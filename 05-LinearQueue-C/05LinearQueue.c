/***************************************************************************
* Program 	:	05LinearQueue.c
* Description :	Implementation of Ordinay QUEUE to perform insertion,deletion and display
* Author		:Mrinal Raj
* Date		:	22th November 2018
* Compiler	: 	gcc version 7.3.0 
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define QUEUE_SIZE 5
typedef struct
{
	int iFront,iRear;
	int Queue[QUEUE_SIZE];
}queue_t;
void fnInsertRear(queue_t*,int);
int fnDeleteFront(queue_t *);
void fnDisplay(queue_t);
bool fnQueueFull(queue_t);
bool fnQueueEmpty(queue_t);
/***************************************************************************
*Function			:	main
*Input parameters	:	no parameters
*RETURNS			:	0 on success
***************************************************************************/
int main(void)
{
	int iChoice,element;
	queue_t myQ;
	myQ.iFront=0;
	myQ.iRear=-1;
	for(;;)
	{
		printf("\n1. Qinsert\n2. Qdelete\n3. Qdisplay\n4. Exit\n");
		printf("\nEnter your choice\t:");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1:if(fnQueueFull(myQ))
					{
						printf("\nQueue is Full\n");
						break;
					}
					printf("\nEnter the element\t:");
					scanf("%d",&element);
					fnInsertRear(&myQ,element);
					break;
			case 2:if(fnQueueEmpty(myQ))
					{
						printf("\nQueue is empty\n");
						break;
					}
					element=fnDeleteFront(&myQ);
					printf("\nDeleted element\t:%d\n",element);
					break;
			case 3:if(fnQueueEmpty(myQ))
					{
						printf("\nQueue is empty\n");
						break;
					}
					printf("\nContents of the list are:\n");
					fnDisplay(myQ);
					break;
			case 4:exit(0);
			default:printf("\nInvalid Choice\n");
		}
	}
	return 0;
}
/***************************************************************************
* Function 			:	fnInsertRear
* Description 		:	Function to insert`integer to queue
*Input parameters	:	
*	queue_t *q 		-	structure representing queue details
*	int element		- 	value contains integer to inserted at end
* RETURNS			:	no value
***************************************************************************/
void fnInsertRear(queue_t *q,int element)
{
	q->iRear=q->iRear+1;
	q->Queue[q->iRear]=element;
}
/***************************************************************************
* Function 			:	fnDeleteFront
* Description 		:	Function to delete`integer from front of queue
*Input parameters	:	
*	queue_t *q 		-	structure representing queue details
* RETURNS			:	integer at front of the queue
***************************************************************************/
int fnDeleteFront(queue_t *q)
{
	int element=q->Queue[q->iFront];
	if(q->iRear==q->iFront)
	{
		q->iFront=0;
		q->iRear=-1;
	}
	else
		q->iFront=q->iFront+1;
	return element;
}
/***************************************************************************
* Function 			:	fnQueueEmpty
* Description 		:	Function to check Queue is empty or not
*Input parameters	:	
*	queue_t q 		-	structure representing queue details
* RETURNS			:	true if empty else false
***************************************************************************/
bool fnQueueEmpty(queue_t q)
{
	return (q.iRear==q.iFront-1);
}
/***************************************************************************
* Function 			:	fnQueueFull
* Description 		:	Function to check Queue is full or not
*Input parameters	:	
*	queue_t q 		-	structure representing queue details
* RETURNS			:	true if full else false
***************************************************************************/
bool fnQueueFull(queue_t q)
{
	return (q.iRear==QUEUE_SIZE-1);
}
/***************************************************************************
* Function 			:	fnDisplay
* Description 		:	Function to display Queue 
*Input parameters	:	
*	queue_t q 		-	structure representing queue details
* RETURNS			:	no value
***************************************************************************/
void fnDisplay(queue_t q)
{
	int i;
	for(i=q.iFront;i<=q.iRear;i++)
		printf("%d\t",q.Queue[i]);
	printf("\nFront is %d and Rear is %d\n",q.iFront,q.iRear);
}
