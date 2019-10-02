/***************************************************************************
* Program 	:	02Stack.c
* Description :	Implementation of Stack to perform push,pop and display operstion.
* Author		:Mrinal Raj
* Date		:	22th November 2018
* Compiler	: 	gcc version 7.3.0 
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STACKSIZE 10
typedef struct
{
	int iaStack[STACKSIZE];
	int iTop;
}stack_t;

void fnPush(stack_t *,int );
int fnPop(stack_t *);
int fnPeek(stack_t);
void fnDisplay(stack_t);
bool fnCheckEmpty(stack_t);
bool fnCheckFull(stack_t);
/***************************************************************************
*Function			:	main
*Input parameters	:	no parameters
*RETURNS			:	0 on success
***************************************************************************/
int main(void)
{
	stack_t s;
	int iChoice,iElem;
	s.iTop=-1;
	while(1)
	{
		printf("\n1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT\n");
		printf("\nEnter your choice\t:");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1:if(fnCheckFull(s))
					{
						printf("\nStack Overflow\n");
						break;
					}
					printf("\nEnter value to be pushed\t:");
					scanf("%d",&iElem);
					fnPush(&s,iElem);
					break;
			case 2:if(fnCheckEmpty(s))
					{
						printf("\nStack Underflow\n");
						break;
					}
					printf("\nDeleted Element\t:");
					iElem=fnPop(&s);
					printf("%d\n",iElem);
					break;
			case 3:if(fnCheckEmpty(s))
					{
						printf("\nNo elements in the Stack\n");
						break;
					}
					printf("\nElement at the peek\t:");
					iElem=fnPeek(s);
					printf("%d\n",iElem);
					break;
			case 4:if(fnCheckEmpty(s))
					{
						printf("\nNo element to be displayed, EMPTY Stack\n");
						break;
					}
					printf("\nContents of the stack are:\n");
					printf("------------------------------------------------\n");
					fnDisplay(s);
					break;
			case 5:return 0;
			default:printf("\nInvalid Choice\n");			
		}
	}
}
/***************************************************************************
* Function 			:	fnPush
* Description 		:	Function to push an element to top of stack
*Input parameters	:	
*	stack_t *s 		-	structure representing stack details
*	int iElem		- 	value contains element to be inserted
* RETURNS			:	no value
***************************************************************************/
void fnPush(stack_t *s,int iElem)
{
	s->iTop=s->iTop+1;
	s->iaStack[s->iTop]=iElem;
}
/***************************************************************************
* Function 			:	fnPop
* Description 		:	Function to pop an element from top of stack
*Input parameters	:	
*	stack_t *s 		-	structure representing stack details
* RETURNS			:	deleted element
***************************************************************************/
int fnPop(stack_t *s)
{
	int iElem=s->iaStack[s->iTop];
	s->iTop=s->iTop-1;
	return iElem;
}
/***************************************************************************
* Function 			:	fnPush
* Description 		:	Function to push an element to top of stack
*Input parameters	:	
*	stack_t s 		-	structure representing stack details
* RETURNS			:	value at the top of the STACK
***************************************************************************/
int fnPeek(stack_t s)
{
	return s.iaStack[s.iTop];
}
/***************************************************************************
* Function 			:	fnDisplay
* Description 		:	Function to display contents of stack
*Input parameters	:	
*	stack_t s 		-	structure representing stack details
* RETURNS			:	no value
***************************************************************************/
void fnDisplay(stack_t s)
{
	int i;
	for(i=s.iTop;i>-1;i--)
	{
		printf("-\t\t\t%d\t\t\t\b-\n",s.iaStack[i]);
	}
	printf("------------------------------------------------\n");
}
/***************************************************************************
* Function 			:	fnCheckEmpty
* Description 		:	Function to check stack is empty or not
*Input parameters	:	
*	stack_t s 		-	structure representing stack details
* RETURNS			:	true if empty else false
***************************************************************************/
bool fnCheckEmpty(stack_t s)
{
	return s.iTop==-1;
}
/***************************************************************************
* Function 			:	fnCheckFull
* Description 		:	Function to check stack is full or not
*Input parameters	:	
*	stack_t s 		-	structure representing stack details
* RETURNS			:	true if full else false
***************************************************************************/
bool fnCheckFull(stack_t s)
{
	return s.iTop==STACKSIZE;
}
