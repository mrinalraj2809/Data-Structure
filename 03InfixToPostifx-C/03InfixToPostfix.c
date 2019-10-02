/***************************************************************************
* Program 	:	03InfixToPostfix.c
* Description :	Program to convert given infix to postfix expression
* Author		:Mrinal Raj
* Date		:	22th November 2018
* Compiler	: 	gcc version 7.3.0 
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define STACKSIZE 10
typedef struct
{
	char opStkArray[STACKSIZE];
	int iTop;
}stack_t;
void fnPush(stack_t *,char);
char fnPop(stack_t *);
int fnPrecd(char);
/***************************************************************************
*Function			:	main
*Input parameters	:	no parameters
*RETURNS			:	0 on success
***************************************************************************/
int main(void)
{
	stack_t myStack;
	myStack.iTop=-1;
	int i,j=0;
	char cSymb;
	char acInfix[50],acPostfix[50];
	printf("\nEnter a valid Infix expression\t:");
	scanf("%s",acInfix);
	fnPush(&myStack,'#');
	for(i=0;i<strlen(acInfix);i++)
	{
		cSymb=acInfix[i];
		if(isalnum(cSymb))
			acPostfix[j++]=cSymb;
		else if(cSymb=='(')
		{
			fnPush(&myStack,cSymb);
		}
		else if(cSymb==')')
		{
			while(myStack.opStkArray[myStack.iTop]!='(')
			{
				acPostfix[j++]=fnPop(&myStack);
			}
			fnPop(&myStack);
		}
		else
		{
			while(fnPrecd(myStack.opStkArray[myStack.iTop]) >= fnPrecd(cSymb))
			{
				acPostfix[j++]=fnPop(&myStack);
			}
			fnPush(&myStack,cSymb);
		}
	}
	while(myStack.opStkArray[myStack.iTop] != '#')
	{
		acPostfix[j++]=fnPop(&myStack);
	}
	acPostfix[j]='\0';
	printf("\nInputted Infix Expression\t:%s",acInfix);
	printf("\nEquivalent Postfix expression\t:%s\n\n",acPostfix);
	return 0;
}
/***************************************************************************
* Function 			:	fnPush
* Description 		:	Function to push`character to stack
*Input parameters	:	
*	stack_t *s 		-	structure representing stack details
*	char ch			- 	value contains character to pushed
* RETURNS			:	no value
***************************************************************************/
void fnPush(stack_t *s,char ch)
{
	s->iTop=s->iTop+1;
	s->opStkArray[s->iTop]=ch;
}
/***************************************************************************
* Function 			:	fnPop
* Description 		:	Function to pop character from stack
*Input parameters	:	
*	stack_t *s 		-	structure representing stack details
* RETURNS			:	character at top of stack
***************************************************************************/
char fnPop(stack_t *s)
{
	char ch= s->opStkArray[s->iTop];
	s->iTop=s->iTop-1;
	return ch;
}
/***************************************************************************
* Function 			:	fnPrecd
* Description 		:	Function to find precedence of operator
*Input parameters	:	
*	char ch 		-	value contains character to be compared
* RETURNS			:	integer precedence
***************************************************************************/
int fnPrecd(char ch)
{
	switch(ch)
	{
		case '#':return -1;
		case '(':return 0;
		case '+':
		case '-':return 1;		
		case '*':
		case '/':
		case '%':return 2;
		case '$':return 3;
		default :return -2;
	}
}
