/***************************************************************************
* Program 	:	09bQueue.c
* Description :	Program to implement QUEUE using Singly Linked List
* Author		:Mrinal Raj
* Date		:	22th November 2018
* Compiler	: 	gcc version 7.3.0 
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node* link;
};

typedef struct node* NODEPTR;

NODEPTR fnGetNode(void);
NODEPTR fnDeleteFront(NODEPTR);
NODEPTR fnInsertRear(NODEPTR,int);
void fnDisplay(NODEPTR);
void fnFreeNode(NODEPTR);
/***************************************************************************
*Function			:	main
*Input parameters	:	no parameters
*RETURNS			:	0 on success
***************************************************************************/
int main()
{
	NODEPTR first=NULL;
	int iChoice,iElem;
	
	for(;;)
	{
		printf("\n------------------------------------\n|");
		printf("\t1.QInsertRear\t\t\t|\n|\t2.QDeleteFront\t\t\t|\n|\t3.Display\t\t|\n|\t4.Exit\t\t\t|\n");
		printf("------------------------------------\n");
		printf("\nEnter your Choice\t:");
		scanf("%d",&iChoice);
		printf("------------------------------------\n");
		switch(iChoice)
		{
			case 1:printf("\nEnter the element to be inseted:");//here we will not check full becoz link list is dynamic
					scanf("%d",&iElem);
					first = fnInsertRear(first,iElem);
					break;
			case 2:first = fnDeleteFront(first);
					break;
			case 3://here we will not check full becoz link list is dynamic
					fnDisplay(first);
					break;
			case 4:exit(0);
			default :printf("\nInvalid Choice");
			
		}
	}
	return 0;
}
/***************************************************************************
* Function 			:	fnGetNode
* Description 		:	Function to create new node
*Input parameters	:	no parameters
* RETURNS			:	pointer to new node
***************************************************************************/
NODEPTR fnGetNode(void)
{
	NODEPTR newborn =(NODEPTR)malloc(sizeof(struct node));
	if(newborn == NULL)
	{
		printf("\nInsufficiant Heap Memory\n");
		return NULL;
	}
	return newborn;
}
/***************************************************************************
* Function 			:	fnFreeNode
* Description 		:	Function to free node
*Input parameters	:	
	NODEPTR x		- 	value contains pointer to node
* RETURNS			:	no value
***************************************************************************/
void fnFreeNode(NODEPTR x)
{
	free(x);
}
/***************************************************************************
* Function 			:	fnInsertRear
* Description 		:	Function to insert an element to end of the list 
*Input parameters	:	
*	NODEPTR first 	-	node pointing to first node
*	int iElem		- 	value contains element to be inserted
* RETURNS			:	pointer to first node
***************************************************************************/
NODEPTR fnInsertRear(NODEPTR first,int iElem)
{
	NODEPTR temp,prev;
	temp=fnGetNode();
	temp->info = iElem;
	temp->link =NULL;
	prev=first;
	if(first == NULL)
	{
	 	return temp;
	}
	while(prev->link!=NULL)
	{
		prev=prev->link;
	}
	prev->link=temp;
	return ;
}
/***************************************************************************
* Function 			:	fnDeleteFront
* Description 		:	Function to delete a node from front of list
*Input parameters	:	
*	NODEPTR first 	-	node pointing to first node
* RETURNS			:	pointer to first node
***************************************************************************/
NODEPTR fnDeleteFront(NODEPTR first)
{
	NODEPTR temp;
	if(first==NULL)
	{
		printf("\nList is Empty\n");
		return NULL;
	}
	temp=first->link;
	printf("\nElement deleted is %d\n",first->info);
	fnFreeNode(first);
	return temp;
}
/***************************************************************************
* Function 			:	fnDisplay
* Description 		:	Function to display linked list
*Input parameters	:	
*	NODEPTR first 	-	node pointing to first node
* RETURNS			:	no value
***************************************************************************/
void fnDisplay(NODEPTR first)
{
	NODEPTR temp=first;
	if(first == NULL )
	{
		printf("\nNo contents to be displayed\n");
		return;
	}
	printf("\nContents are:\n");
	while(temp !=NULL)
	{
		printf("%d\n",temp->info);
		temp=temp->link;
	}
	printf("\n");
}
