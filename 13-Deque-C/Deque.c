/***************************************************************************
* Program 	:	11Deque.c
* Description :	Program to insert, delete and display using Doubly Ended Queue
* Author		:Mrinal Raj
* Date		:	22th November 2018
* Compiler	: 	gcc version 7.3.0 
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node* lLink;
	struct node* rLink;
};

typedef struct node* NODEPTR;

NODEPTR fnGetNode(void);
NODEPTR fnDeleteFront(NODEPTR);
NODEPTR fnInsertFront(NODEPTR,int);
NODEPTR fnDeleteRear(NODEPTR);
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
	NODEPTR head;
	int iChoice,iItem;
	head=fnGetNode();
	head->info=0;
	head->rLink = head->lLink =head;
	for(;;)
	{
		printf("\n1.Insert Front \n2.Insert Rear");
		printf("\n3.Delete Front");
		printf("\n4.Delete Rear");
		printf("\n5.Display\n6.Exit\n");
		printf("\nEnter your Choice\t:");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1:printf("\nEnter the Item to be inserted at front\n");
					scanf("%d",&iItem);
					head=fnInsertFront(head,iItem);
					break;
			case 2:printf("\nEnter the Item to be inserted at rear\n");
					scanf("%d",&iItem);
					head=fnInsertRear(head,iItem);
					break;
			case 3:head=fnDeleteFront(head);
					break;
			case 4:head=fnDeleteRear(head);
					break;
			case 5:fnDisplay(head);
					break;
			case 6:exit(0);
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
NODEPTR fnGetNode()
{
	NODEPTR newborn;
	newborn=(NODEPTR)malloc(sizeof(struct node));
	if(newborn==NULL)
	{
		printf("\nOut of Memory");
		exit(0);
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
* Function 			:	fnInsertFront
* Description 		:	Function to insert an element to front of the list 
*Input parameters	:	
*	NODEPTR head 	-	node pointing to head node
*	int iItem		- 	value contains element to be inserted
* RETURNS			:	pointer to head node
***************************************************************************/
NODEPTR fnInsertFront(NODEPTR head,int iItem)
{
	NODEPTR temp,first;
	temp=fnGetNode();
	temp->info=iItem;
	
	first =head->rLink;
	head->rLink=temp;
	first->lLink=temp;
	temp->lLink=head;
	temp->rLink=first;
	head->info =head->info+1;
	return head;
}
/***************************************************************************
* Function 			:	fnDeleteFront
* Description 		:	Function to delete an element from front of the list 
*Input parameters	:	
*	NODEPTR head	-	node pointing to head node
* RETURNS			:	pointer to head node
***************************************************************************/
NODEPTR fnDeleteFront(NODEPTR head)
{
	NODEPTR second,first;
	if(head->rLink==head)
	{
		printf("\nList is Empty");
		return head;
	}
	first=head->rLink;
	second=first->rLink;
	head->rLink=second;
	second->lLink=head ;
	
	printf("\nDeleted Element is %d \n",first->info);
	fnFreeNode(first);
	(head->info)--;
	return head;
}
/***************************************************************************
* Function 			:	fnInsertRear
* Description 		:	Function to insert an element to end of the list
*Input parameters	:	
*	NODEPTR head 	-	node pointing to head node
*	int iElem		- 	value contains element to be inserted
* RETURNS			:	pointer to head node
***************************************************************************/
NODEPTR fnInsertRear(NODEPTR head,int iItem)
{
	NODEPTR temp,last;
	temp=fnGetNode();
	temp->info=iItem;
	
	last =head->lLink;
	last->rLink=temp;
	temp->lLink=last;
	temp->rLink=head;
	head->lLink=temp;
	
	head->info =head->info+1;
	return head;
}
/***************************************************************************
* Function 			:	fnDeleteRear
* Description 		:	Function to delete a node from rear of list
*Input parameters	:	
*	NODEPTR head 	-	node pointing to head node
* RETURNS			:	pointer to head node
***************************************************************************/
NODEPTR fnDeleteRear(NODEPTR head)
{
	NODEPTR secondLast,last;
	if(head->rLink==head)
	{
		printf("\nList is Empty");
		return head;
	}
	last =head->lLink;
	secondLast=last->lLink;
	secondLast->rLink=head;
	head->lLink=secondLast;
	
	printf("\nDeleted Element is %d \n",last->info);
	fnFreeNode(last);
	(head->info)--;
	return head;
}
/***************************************************************************
* Function 			:	fnDisplay
* Description 		:	Function to display doubly linked list
*Input parameters	:	
*	NODEPTR head	-	node pointing to head node
* RETURNS			:	no value
***************************************************************************/
void fnDisplay(NODEPTR head)
{
	NODEPTR temp=head->rLink;
	if(head->info ==0 )  //if(head->rLink ==head )
	{
		printf("\nNo contents to be displayed\n");
		return;
	}
	printf("\nContents are:\n");
	while(temp !=head)
	{
		printf("%d\n",temp->info);
		temp=temp->rLink;
	}
	printf("\n");
}
