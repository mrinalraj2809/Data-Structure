/***************************************************************************
* Program 	:	04EvaluatePrefix.c
* Description :	Program to evaluate prefix expression
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
	char stkArray[STACKSIZE];
	int iTop;
}stack_t;
void fnPush(stack_t *,int);
int fnPop(stack_t *);
/***************************************************************************
*Function			:	main
*Input parameters	:	no parameters
*RETURNS			:	0 on success
***************************************************************************/
int main(void)
{
	stack_t myStack;
	myStack.iTop=-1;
	int i,res,op1,op2;
	char cSymb,exp[50];
	printf("\nEnter a valid prefix expression\t:");
	scanf("%s",exp);
	fnPush(&myStack,'#');
	for(i=strlen(exp)-1;i>=0;i--)
	{
		cSymb=exp[i];
		if(isdigit(cSymb))
			fnPush(&myStack,cSymb-'0');
		else
		{
			op1=fnPop(&myStack);
			op2=fnPop(&myStack);
			switch(cSymb)
			{
				case '+':res=op1+op2;
						break;
				case '*':res=op1*op2;
						break;
				case '/':res=op1/op2;
						break;
				case '-':res=op1-op2;
						break;
				case '%':res=op1%op2;
						break;
				
			}
			fnPush(&myStack,res);
		}
	}
	res=fnPop(&myStack);
	printf("\nFinal Result of expression %s is %d\n\n",exp,res);
	return 0;
}
void fnPush(stack_t *s,int element)
{
	s->iTop=s->iTop+1;
	s->stkArray[s->iTop]=element;
}
int fnPop(stack_t *s)
{
	int element= s->stkArray[s->iTop];
	s->iTop=s->iTop-1;
	return element;
}
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
