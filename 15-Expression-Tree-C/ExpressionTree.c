/***************************************************************************
* Program 	:	13ExpressionTree.c
* Description :	Program to construct an expression tree with given postfix expression
* Author		:Mrinal Raj
* Date		:	22th November 2018
* Compiler	: 	gcc version 7.3.0 
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
struct ExpTree
{
	char value;
	struct ExpTree *lbranch,*rbranch;
};
typedef struct ExpTree* NODEPTR;

bool isOperator(char c);
void inOrder(NODEPTR);
NODEPTR newNode(int v);
NODEPTR constructTree(char postfix[]);
void push(NODEPTR[],NODEPTR ,int *);
NODEPTR pop(NODEPTR[],int *);
float evalPost(NODEPTR);
/***************************************************************************
*Function			:	main
*Input parameters	:	no parameters
*RETURNS			:	0 on success
***************************************************************************/
int main()
{
	char postfix[30];
	float fResult;
	printf("\nEnter a postfix expression\n");
	scanf("%s",postfix);
	NODEPTR et =constructTree(postfix);
	printf("Infix Expression is \n");
	inOrder(et);
	printf("\n");
	fResult= evalPost(et);
	printf("\nValue of Postfix Expression is: %g\n\n",fResult);
	return 0;
}
float evalPost(NODEPTR root)
{
	float fNum;
	switch(root->value)
	{
		case '+':return (evalPost(root->lbranch) + evalPost(root->rbranch));
		case '-':return (evalPost(root->lbranch) - evalPost(root->rbranch));
		case '*':return (evalPost(root->lbranch) * evalPost(root->rbranch));
		case '/':return (evalPost(root->lbranch) / evalPost(root->rbranch));
		case '^':return (pow(evalPost(root->lbranch) , evalPost(root->rbranch)));
		default:if(isalpha(root->value))
				{
					printf("\n%c = ",root->value);
					scanf("%f",&fNum);
					return(fNum);
				}
				else
					return(root->value-'0');
	}
}
/***************************************************************************
* Function 			:	fnInOrder
* Description 		:	Function to perform inorder traversal
*Input parameters	:	
*	NODEPTR t 	-	node pointing to node
* RETURNS			:	no value
***************************************************************************/
void inOrder(NODEPTR t)
{
	if(t)   // executes inner block when not NULL
	{
		inOrder(t->lbranch);
		printf("%c",t->value);
		inOrder(t->rbranch);
	}
}
/***************************************************************************
* Function 			:	constructTree
* Description 		:	Function to construct tree using given postfix string
*Input parameters	:	
*	char postfix[] 	-	string containing postfix string
* RETURNS			:	pointer to the root
***************************************************************************/
NODEPTR constructTree(char postfix[])
{
	NODEPTR stack[100];
	int i,top=-1;
	NODEPTR t,t1,t2;
	for(i=0;i<strlen(postfix);i++)
	{
		if(!isOperator(postfix[i]))
		{
			t=newNode(postfix[i]);
			push(stack,t,&top);
		}
		else  // operator
		{
			t=newNode(postfix[i]);
			t1 =pop(stack,&top);
			t2 =pop(stack,&top);
			t->rbranch=t1;               //we are just converting it to infix by makig it a child
			t->lbranch=t2;
			//Now we are going to push it on to stack
			push(stack,t,&top);
		}
	}
	t=pop(stack,&top);
	return t;
}
/***************************************************************************
* Function 			:	isOperator
* Description 		:	Function to check character is operator or not
*Input parameters	:	
*	char c	 		-	value contains character
* RETURNS			:	true if it is operator else false
***************************************************************************/
bool isOperator(char c)
{
	if(c == '+'||c == '-'||c == '*'||c == '/'||c == '^')
		return true;
	return false;
}
/***************************************************************************
* Function 			:	fnGetNode
* Description 		:	Function to create new node
*Input parameters	:	no parameters
* RETURNS			:	pointer to new node
***************************************************************************/
NODEPTR newNode(int v)
{
	NODEPTR temp=(NODEPTR) malloc(sizeof(struct ExpTree));
	temp->lbranch=temp->rbranch=NULL;
	temp->value=v;
	return temp;
}
/***************************************************************************
* Function 			:	push
* Description 		:	Function to push a node to top of stack 
*Input parameters	:	
*	NODEPTR st[] 	-	node pointing to stack of node
*	NODEPTR p	 	-	pointer to node which is to be pushed
*	int *t			- 	value contains top of stack using pass by reference
* RETURNS			:	no value
***************************************************************************/
void push(NODEPTR st[],NODEPTR p,int *t)
{
	*t=*t+1;
	st[*t]=p;   //stack of nodes
}
/***************************************************************************
* Function 			:	pop
* Description 		:	Function to pop a node from top of stack 
*Input parameters	:	
*	NODEPTR st[] 	-	node pointing to stack of node
*	int *t			- 	value contains top of stack using pass by reference
* RETURNS			:	pointer to node
***************************************************************************/
NODEPTR pop(NODEPTR st[],int *t)
{
	NODEPTR temp;
	temp = st[*t];
	*t = *t-1;
	return temp;
}
