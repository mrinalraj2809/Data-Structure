/***************************************************************************
* Program 	:	10SwapDoublyLinkedList.c
* Description :	Program to insert, display, delete and swap using Headed DoublylinkedList 
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

NODEPTR fnSwapNodes(NODEPTR head,int m,int n);
void fnDisplay(NODEPTR head);
NODEPTR fnDelElemPos(NODEPTR head,int iPos);
NODEPTR fnInsertNext(NODEPTR head,int iItem);
NODEPTR fnDeleteFirst(NODEPTR last);
NODEPTR fnInsertFront(NODEPTR last,int iItem);
void fnFreeNode(NODEPTR x);
NODEPTR fnGetNode();
/***************************************************************************
*Function			:	main
*Input parameters	:	no parameters
*RETURNS			:	0 on success
***************************************************************************/
int main()
{
	NODEPTR head,last;
	int iChoice,iItem,iKey,iPos,iM,iN;
	head=fnGetNode();
	head->info=0;
	head->rLink = head->lLink =head;
	for(;;)
	{
		printf("\n1.Insert Front \n2.Insert to the next of a given Node");
		printf("\n3.Delete First Node");
		printf("\n4.Delete a Node whose position is specified");
		printf("\n5.Display\n6.Swap Nodes\n7.Exit\n");
		printf("\nEnter your Choice\t:");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1:printf("\nEnter the Item to be inserted\n");
					scanf("%d",&iItem);
					head=fnInsertFront(head,iItem);
					break;
			case 2:printf("\nEnter the key value of the node\n");
					scanf("%d",&iKey);
					head=fnInsertNext(head,iKey);
					break;
			case 3:last =head->lLink;
					head=fnDeleteFirst(last);
					break;
			case 4:printf("\nEnter the position of the element to be deleted\n");
					scanf("%d",&iPos);
					head=fnDelElemPos(head,iPos);
					break;
			case 5:fnDisplay(head);
					break;
			case 6:printf("\nEnter the position m and n of the nodes to be swapped such that m<n\n");
					scanf("%d%d",&iM,&iN);
					if(iM>iN)
						printf("\nInvalid input\n");
					else
						head=fnSwapNodes(head ,iM,iN);
					break;
			case 7: exit(0);
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
* Function 			:	fnDeleteFirst
* Description 		:	Function to delete an element from front of the list 
*Input parameters	:	
*	NODEPTR last 	-	node pointing to last node
* RETURNS			:	pointer to last node
***************************************************************************/
NODEPTR fnDeleteFirst(NODEPTR last)
{
	NODEPTR second,first,head;
	if(last->rLink==last)
	{
		printf("\nList is Empty");
		return last;
	}
	head =last->rLink;
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
* Function 			:	fnInsertNext
* Description 		:	Function to insert an element to next of the list 
*Input parameters	:	
*	NODEPTR head 	-	node pointing to head node
*	int iItem		- 	value contains element to be inserted
* RETURNS			:	pointer to head node
***************************************************************************/
NODEPTR fnInsertNext(NODEPTR head,int iItem)
{
	NODEPTR temp,cur,next;
	if(head->rLink == head)
	{
		printf("\nList is Empty\n\n");
		return head;
	}
	cur=head->rLink;
	while(cur!=head && iItem!=cur->info)
	{
		cur=cur->rLink;
	}
	if(cur==head)
	{
		printf("\nSpecified Node not found\n");
		return head;
	}
	next=cur->rLink;
	printf("\nEnter the element to inserted to the next of %d\t:",iItem);
	temp=fnGetNode();
	scanf("%d",&temp->info);
	
	cur->rLink=temp;
	next->lLink=temp;
	temp->lLink=cur;
	temp->rLink=next;
	(head->info)++;
	return head;
}
/***************************************************************************
* Function 			:	fnDelElemPos
* Description 		:	Function to delete element at given position 
*Input parameters	:	
*	NODEPTR head 	-	node pointing to head node
*	int iPos		- 	value contains position of node to be deleted
* RETURNS			:	pointer to head node
***************************************************************************/
NODEPTR fnDelElemPos(NODEPTR head,int iPos)
{
	NODEPTR prev,cur,next;
	int count=1;
	if(head->rLink==head)
	{
		printf("\nList is Empty\n");
		return head;
	}
	cur=head->rLink;
	while(cur!=head && iPos!=count)
	{
		count++;
		cur=cur->rLink;
	}
	if(count==iPos)
	{
		prev=cur->lLink;
		next=cur->rLink;
		prev->rLink=next;
		next->lLink=prev;
		
		printf("\nElement Deleted is %d\n",cur->info);
		fnFreeNode(cur);
	}
	if(cur==head)
	{
		printf("\nIvalid position\n");
		return head;
	}
	return head;
}
/***************************************************************************
* Function 			:	fnSwapNodes
* Description 		:	Function to swap nodes at given positions
*Input parameters	:	
*	NODEPTR head 	-	node pointing to head node
*	int m			- 	value contains position of node to be deleted
*	int n			- 	value contains position of node to be deleted
* RETURNS			:	pointer to head node
***************************************************************************/
NODEPTR fnSwapNodes(NODEPTR head,int m,int n)
{
	int temp,count=1;
	NODEPTR cur,mPos,nPos;
	cur=head->rLink;
	while(cur!=head &&count!=m)
	{
		cur=cur->rLink;
		count++;
	}
	if(cur!=head)  //if(count==m)
	{
		mPos =cur;
	}
	else
	{
		printf("\nNode %d does not exist \n",m);
		return head;
	}
	while(cur!=head && count!=n)
	{
		cur=cur->rLink;
		count++;
	}
	if(cur!=head)
	{
		nPos=cur;
	}
	else 
	{
		printf("\nNode %d does not exist\n",n);
		return head;
	}
	temp=mPos->info;   //here temp is integer variable
	mPos->info=nPos->info;
	nPos->info=temp;
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
