/***************************************************************************
* Program 	:	09cAddPolynimial.c
* Description :	Program to add two polynomial using Singly linked list
* Author		:Mrinal Raj
* Date		:	22th November 2018
* Compiler	: 	gcc version 7.3.0 
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct polynomial
{
	int coeff;
	int exponent;
	struct polynomial *link;
};
typedef struct polynomial *NODEPTR;
NODEPTR fnGetNode(void);
NODEPTR fnInsertRear(int,int,NODEPTR);
void fnDisplay(NODEPTR);
NODEPTR fnAddPoly(NODEPTR,NODEPTR);
int evalPoly(NODEPTR,int);
/***************************************************************************
*Function			:	main
*Input parameters	:	no parameters
*RETURNS			:	0 on success
***************************************************************************/
int main()
{
	NODEPTR poly1,poly2,poly3;
	int i,iX,iRes,iDegree,iaCoeff[10];
	poly1=poly2=poly3=NULL;
	printf("\nEnter the degree of polynomial1\n");
	scanf("%d",&iDegree);
	printf("\nEnter the Coefficients\n");
	for(i=iDegree;i>=0;i--)
	{
		scanf("%d",&iaCoeff[i]);
		poly1=fnInsertRear(iaCoeff[i],i,poly1);
	}
	printf("\nEnter the degree of polynomial 2\n");
	scanf("%d",&iDegree);
	printf("\nEnter the Coefficients\n");
	for(i=iDegree;i>=0;i--)
	{
		scanf("%d",&iaCoeff[i]);
		poly2=fnInsertRear(iaCoeff[i],i,poly2);
	}
	poly3=fnAddPoly(poly1,poly2);
	printf("Polynomial 1:\t");
	fnDisplay(poly1);
	printf("Polynomial 2:\t");
	fnDisplay(poly2);
	printf("Polynomial Sum:\t");
	fnDisplay(poly3);
	printf("\nEnter the value of x \n");
	scanf("%d",&iX);
	iRes=evalPoly(poly3,iX);
	printf("\nValue of the polynomial sum for x=%d is %d\n",iX,iRes);
	return 0;
}
/***************************************************************************
* Function 			:	fnInsertRear
* Description 		:	Function to insert an element to end of the list 
*Input parameters	:	
*	NODEPTR first 	-	node pointing to first node
*	int iElem		- 	value contains element to be inserted
* RETURNS			:	pointer to first node
***************************************************************************/
NODEPTR fnInsertRear(int iCoeff,int iExp,NODEPTR first)
{
	NODEPTR temp,cur;
	temp=fnGetNode();
	temp->coeff=iCoeff;
	temp->exponent=iExp;
	temp->link=NULL;
	if(first==NULL)
	{
		return temp;
	}
	cur=first;
	while(cur->link!=NULL)
	{
		cur=cur->link;
	}
	cur->link=temp;
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
	NODEPTR cur;
	for(cur=first;cur->link!=NULL;cur=cur->link)   // leaving last node as the power will be 0 so to not display x^0 we will leave last node 
	{
		printf("(%d)x^%d+",cur->coeff,cur->exponent);
	}
	printf("%d\n",cur->coeff);  //and then print it specifically at last
}
/***************************************************************************
* Function 			:	fnAddPoly
* Description 		:	Function to add two polynomials
*Input parameters	:	
*	NODEPTR list1 	-	node pointing to polynomial 1 node
*	NODEPTR list2 	-	node pointing to polynomial 2 node
* RETURNS			:	pointer to new added list node
***************************************************************************/
NODEPTR fnAddPoly(NODEPTR poly1,NODEPTR poly2)
{
	NODEPTR tracker1,tracker2,poly3=NULL;
	tracker1=poly1;
	tracker2=poly2;
	while(tracker1 !=NULL &&tracker2!=NULL)
	{
		if(tracker1->exponent >tracker2->exponent)
		{
			poly3=fnInsertRear(tracker1->coeff,tracker1->exponent,poly3);
			tracker1=tracker1->link;
		}
		else if(tracker1->exponent ==tracker2->exponent)
		{
			poly3=fnInsertRear(tracker1->coeff + tracker2->coeff,tracker1->exponent,poly3);
			tracker1=tracker1->link;
			tracker2=tracker2->link;
		}
		else   // if bx^2+cx =d       and    ax^3+bx^2+cx =d
		{
			poly3=fnInsertRear(tracker2->coeff,tracker2->exponent,poly3);
			tracker2=tracker2->link;
		}
	}
	return poly3;
}
/***************************************************************************
* Function 			:	evalPoly
* Description 		:	Function to evaluate polynomial
*Input parameters	:	
*	NODEPTR list 	-	node pointing to list node
*	int x			-	contains the value of x
* RETURNS			:	evalated polynomial result
***************************************************************************/
int evalPoly(NODEPTR list,int x)
{
	int iSum=0;
	NODEPTR cur=list;
	
	while(cur!=NULL)
	{
		iSum+=(cur->coeff * /*MUL*/ (int)pow(x,cur->exponent));
		cur=cur->link;
	}
	return iSum;
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
	newborn=(NODEPTR)malloc(sizeof(struct polynomial));
	if(newborn==NULL)
	{
		printf("\nOut of Memory");
		exit(0);
	}
	return newborn;
}

