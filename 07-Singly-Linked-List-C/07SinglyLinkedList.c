/***************************************************************************
* Program 	:	07SinglyLinkedList.c
* Description :	Program to Singly Linked List to perform insertion, deletion ,display  
* Author		:Mrinal Raj
* Date		:	22th November 2018
* Compiler	: 	gcc version 7.3.0 
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *link;
};
typedef struct node* NODEPTR;
NODEPTR fnGetNode(void);
void fnFreeNode(NODEPTR);
NODEPTR fnInsertRear(NODEPTR,int);
NODEPTR fnDeleteFront(NODEPTR);
NODEPTR fnInsertPosition(NODEPTR,int,int);
NODEPTR fnReverse(NODEPTR);
void fnDisplay(NODEPTR);
/***************************************************************************
*Function			:	main
*Input parameters	:	no parameters
*RETURNS			:	0 on success
***************************************************************************/
int main(void)
{
	NODEPTR first=NULL;
	int iChoice,element,iPos;
	for(;;)
	{
		printf("\n1.Insert Rear\n2.Delete Front\n3.Insert at Position\n4.Reverse\n5.Display\n6.Exit\n");
		printf("Enter your choice\t:");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1:printf("\nEnter the element\t:");
					scanf("%d",&element);
					first=fnInsertRear(first,element);
					break;
			case 2:first=fnDeleteFront(first);
					break;
			case 3:printf("\nEnter the position\t:");
					scanf("%d",&iPos);printf("\nEnter the element\t:");
					scanf("%d",&element);
					first=fnInsertPosition(first,element,iPos);
					break;
			case 4:printf("\nReversed List\t:\n");
					first=fnReverse(first);
					fnDisplay(first);
					break;
			case 5:printf("\nContents of List :\n");
					fnDisplay(first);
					break;
			case 6:exit(0);
			
		}
	}
}
/***************************************************************************
* Function 			:	fnGetNode
* Description 		:	Function to create new node
*Input parameters	:	no parameters
* RETURNS			:	pointer to new node
***************************************************************************/
NODEPTR fnGetNode(void)
{
	NODEPTR newborn=(NODEPTR)malloc(sizeof(struct node));
	if(newborn==NULL)
	{
		printf("\nOut of Heap memory\n");
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
* Description 		:	Function to insert integer to linked list
*Input parameters	:	
*	NODEPTR first 	-	node pointing to first node
*	int element		- 	value contains integer to be inserted at rear
* RETURNS			:	pointer to first node
***************************************************************************/
NODEPTR fnInsertRear(NODEPTR first,int element)
{
	NODEPTR cur,temp;
	temp=fnGetNode();
	temp->info=element;
	temp->link=NULL;
	if(first==NULL)
		return temp;
	for(cur=first;cur->link!=NULL;cur=cur->link);
	cur->link=temp;
	return first;
}
/***************************************************************************
* Function 			:	fnDeleteFront
* Description 		:	Function to delete integer from linked list
*Input parameters	:	
*	NODEPTR first 	-	node pointing to first node
* RETURNS			:	pointer to first node
***************************************************************************/
NODEPTR fnDeleteFront(NODEPTR first)
{
	NODEPTR next;
	if(first==NULL)
	{
		printf("\nCannot delete from an empty list\n");
		return NULL;
	}
	next=first->link;
	printf("\nElement Deleted\t:%d",first->info);
	fnFreeNode(first);
	return next;
}
/***************************************************************************
* Function 			:	fnInsertPosition
* Description 		:	Function to insert node at given position in linked list
*Input parameters	:	
*	NODEPTR first 	-	node pointing to first node
*	int element		- 	value contains integer to be inserted at rear
* RETURNS			:	pointer to first node
***************************************************************************/
NODEPTR fnInsertPosition(NODEPTR first,int element,int iPos)
{
	int iCount=1;
	NODEPTR temp,cur,prev;
	temp=fnGetNode();
	temp->info=element;
	temp->link=NULL;
	if(first==NULL && iPos==1)
		return temp;
	if(first==NULL && iPos!=1)
	{
		printf("\nInvalid Position\n");
		return temp;
	}
	if(iPos==1)   //  there is a node in the list from before 
	{
		temp->link=first;
		return temp;
	}
	for(cur=first;cur!=NULL&&iCount!=iPos;cur=cur->link)
	{
		prev=cur;
		iCount++;
	}
	if(iCount==iPos)   //if it is other than the first node
	{
		prev->link=temp;
		temp->link=cur;
		return first;
	}
	if(cur==NULL)
	{
		printf("\nInvalid Position\n");
		return first;
	}
	return first;
}
/***************************************************************************
* Function 			:	fnReverse
* Description 		:	Function to reverse linked list
*Input parameters	:	
*	NODEPTR first 	-	node pointing to first node
* RETURNS			:	pointer to first node
***************************************************************************/
NODEPTR fnReverse(NODEPTR first)
{
	NODEPTR prev,cur,next;
	if(first==NULL)
	{
		printf("\nList is empty\n");
		return first;
	}
	if(first->link==NULL)
		return first;
	for(prev=first,cur=first->link,next=cur->link,prev->link=NULL;cur->link!=NULL;prev=cur,cur=next,next=next->link)  /*cur is traversed till last node only so that next must not point to invalid position*/
	// define prev's link after initialising cur and next node otherwise the value gets reflected in the first can give unwanted result
	{
		cur->link=prev;
	}
	cur->link=prev;    // so therfore we need to explicitily define cur 
	return cur;
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
	NODEPTR cur;
	if(first==NULL)
	{
		printf("\nList is empty\n");
		return ;
	}
	for(cur=first;cur!=NULL;cur=cur->link)
	{
		printf("%d\t",cur->info);
	}
	printf("\n\n");
}

