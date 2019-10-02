/***************************************************************************
* Program 	:	08IntersectionUnion.c
* Description :	Program to perform union and intersection using Singly linked list
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
NODEPTR fnInsertOrder(NODEPTR,int);
NODEPTR fnInsertRear(NODEPTR,int);
NODEPTR fnUnion(NODEPTR,NODEPTR);
NODEPTR fnIntersection(NODEPTR,NODEPTR);
void fnDisplay(NODEPTR);
/***************************************************************************
*Function			:	main
*Input parameters	:	no parameters
*RETURNS			:	0 on success
***************************************************************************/
int main(void)
{
	NODEPTR list1,list2,list3;
	list1=list2=list3=NULL;
	int iChoice,element;
	for(;;)
	{
		printf("\n1.Insert List1\n2.Insert List2\n3.Union\n4.Intersection\n5.Display\n6.Exit\n");
		printf("Enter your choice\t:");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1:printf("\nEnter the element\t:");
					scanf("%d",&element);
					list1=fnInsertOrder(list1,element);
					break;
			case 2:printf("\nEnter the element\t:");
					scanf("%d",&element);
					list2=fnInsertOrder(list2,element);
					break;
			case 3:printf("\nUNION\t:\n");
					list3=fnUnion(list1,list2);
					printf("\nContents of List1 :\n");
					fnDisplay(list1);
					printf("\nContents of List2 :\n");
					fnDisplay(list2);
					printf("\nContents of List3 :\n");
					fnDisplay(list3);
					break;
			case 4:printf("\nIntersection\t:\n");
					list3=fnIntersection(list1,list2);
					printf("\nContents of List1 :\n");
					fnDisplay(list1);
					printf("\nContents of List2 :\n");
					fnDisplay(list2);
					printf("\nContents of List3 :\n");
					fnDisplay(list3);
					break;
			case 5:printf("\nContents of List1 :\n");
					fnDisplay(list1);
					printf("\nContents of List2 :\n");
					fnDisplay(list2);
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
* Function 			:	fnInsertOrder
* Description 		:	Function to insert in linked list in ascending order
*Input parameters	:	
*	NODEPTR first 	-	node pointing to first node
*	int element		- 	value contains integer to be inserted
* RETURNS			:	pointer to first node
***************************************************************************/
NODEPTR fnInsertOrder(NODEPTR first,int element)
{
	NODEPTR cur,temp,prev;
	temp=fnGetNode();
	temp->info=element;
	temp->link=NULL;
	if(first==NULL)
		return temp;
	if(element <=first->info)  
	{
		temp->link=first;
		return temp;
	}
	prev=NULL;
	for(cur=first;cur!=NULL && element > cur->info;prev=cur,cur=cur->link);
	prev->link=temp;
	temp->link=cur;
	return first;
}
/***************************************************************************
* Function 			:	fnUnion
* Description 		:	Function to perform union of two list
*Input parameters	:	
*	NODEPTR list1 	-	node pointing to list1 node
*	NODEPTR list2 	-	node pointing to list2 node
* RETURNS			:	pointer to new list node
***************************************************************************/
NODEPTR fnUnion(NODEPTR list1,NODEPTR list2)
{
	NODEPTR list3=NULL;
	NODEPTR t1,t2;
	t1=list1,t2=list2;
	while(t1!=NULL&&t2!=NULL)
	{
		if(t1->info < t2->info)
		{
			list3=fnInsertRear(list3,t1->info);
			t1=t1->link;
		}
		else if(t1->info > t2->info)
		{
			list3=fnInsertRear(list3,t2->info);
			t2=t2->link;
		}
		else             //if elements are same
		{
			t2=t2->link;     
		}
	}
	for(;t1!=NULL;t1=t1->link)
	{
		list3=fnInsertRear(list3,t1->info);
	}
	for(;t2!=NULL;t2=t2->link)
	{
		list3=fnInsertRear(list3,t2->info);
	}
	return list3;
}
/***************************************************************************
* Function 			:	fnIntersection
* Description 		:	Function to perform intersection of two list
*Input parameters	:	
*	NODEPTR list1 	-	node pointing to list1 node
*	NODEPTR list2 	-	node pointing to list2 node
* RETURNS			:	pointer to new list node
***************************************************************************/
NODEPTR fnIntersection(NODEPTR list1,NODEPTR list2)
{
	NODEPTR t1,t2,t3=NULL;
	for(t1=list1;t1!=NULL;t1=t1->link)
	{
		for(t2=list2;t2!=NULL;t2=t2->link)
		{
			if(t1->info == t2->info)
				t3=fnInsertRear(t3,t1->info);
		}
	}
	return t3;
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

