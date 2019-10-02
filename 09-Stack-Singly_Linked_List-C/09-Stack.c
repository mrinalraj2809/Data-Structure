/***************************************************************************
* Program 	:	09aStack.c
* Description :	Program to implement STACK using Singly Linked List
* Author		:Mrinal Raj
* Date		:	22th November 2018
* Compiler	: 	gcc version 7.3.0 
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node{
	int info;
	struct node *link;
};

typedef struct node *NODEPTR;

NODEPTR fnGetNode(void);
void fnFreeNode(NODEPTR);
NODEPTR fnPush(NODEPTR,int);
NODEPTR fnPop(NODEPTR);
void fnDisplay(NODEPTR);
/***************************************************************************
*Function			:	main
*Input parameters	:	no parameters
*RETURNS			:	0 on success
***************************************************************************/
int main()
{
	NODEPTR first=NULL;
	int iElem,iChoice;
	for(;;)
	{
		printf("\n1. Push\n2. Pop\n3. Display\n4.Exit\n");
		printf("\nEnter the Choice\n");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1: printf("\nEnter an element\n");
					scanf("%d",&iElem);
					first=fnPush(first,iElem);
					break;
			case 2: first=fnPop(first);
					break;
			case 3: fnDisplay(first);
					break;
			case 4: exit(0);
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
	NODEPTR newNode;
	newNode=(NODEPTR)malloc(sizeof(struct node));
	if(newNode==NULL)
	{
		printf("\nFailed to allocate heap memory\n");
		return NULL;
	}
	return newNode;
}
/***************************************************************************
* Function 			:	fnFreeNode
* Description 		:	Function to free node
*Input parameters	:	
	NODEPTR x		- 	value contains pointer to node
* RETURNS			:	no value
***************************************************************************/
void fnFreeNode(NODEPTR ptr)
{
	free(ptr);
}
/***************************************************************************
* Function 			:	fnPush
* Description 		:	Function to push an element to top of stack 
*Input parameters	:	
*	NODEPTR first 	-	node pointing to first node
*	int iElem		- 	value contains element to be inserted
* RETURNS			:	pointer to first node
***************************************************************************/
NODEPTR fnPush(NODEPTR first, int iElem)
{
	NODEPTR temp;
	temp=fnGetNode();
	temp->info=iElem;
	temp->link=first;
	return temp;
}
/***************************************************************************
* Function 			:	fnPop
* Description 		:	Function to pop an element from top of stack
*Input parameters	:	
*	NODEPTR first 	-	node pointing to first node
* RETURNS			:	pointer to first node
***************************************************************************/
NODEPTR fnPop(NODEPTR first)
{
	NODEPTR temp;
	if(first==NULL)
	{
		printf("\nCannot delete from an empty stack\n");
		return first;
	}
	temp=first;
	first=first->link;
	printf("\nElement deleted is %d\n",temp->info);
	fnFreeNode(temp);
	return first;
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
	NODEPTR curr;
	if(first==NULL)
	{
		printf("\nStack is empty\n");
		return;
	}
	printf("The contents of stack are:\n");
	curr=first;
	while(curr!=NULL)
	{
		printf("%d\t",curr->info);
		curr=curr->link;
	}
	printf("\n");
}

