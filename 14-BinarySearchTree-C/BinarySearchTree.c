/***************************************************************************
* Program 	:	12BinarySearchTree.c
* Description :	Program to construct traverse and delete using Binary Search Tree 
* Author		:Mrinal Raj
* Date		:	22th November 2018
* Compiler	: 	gcc version 7.3.0 
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *lbranch;
	struct node *rbranch;
};
typedef struct node* NODEPTR;
NODEPTR fnGetNode(void);
void fnFreeNode(NODEPTR);
NODEPTR fnInsertNode(int ,NODEPTR);
void fnInOrder(NODEPTR);
void fnPreOrder(NODEPTR);
void fnPostOrder(NODEPTR);
NODEPTR fnDeleteNode(NODEPTR,int);
NODEPTR fnMinValueNode(NODEPTR);
/***************************************************************************
*Function			:	main
*Input parameters	:	no parameters
*RETURNS			:	0 on success
***************************************************************************/
int main()
{
	NODEPTR root=NULL;
	int iChoice,iItem;
	for(;;)
	{
		printf("\n1.Insert a node\n2.Inorder traversal\n3.Preorder traversal\n4.Postorder traversal\n");
		printf("5.Delete a node\n6.Exit\n");
		printf("\nEnter your choice\t:");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1:printf("\nEnter the item to be inserted\n");
					scanf("%d",&iItem);
					root=fnInsertNode(iItem,root);
					break;
			case 2:if(root==NULL)
					{
						printf("\nTree is Empty\n");
					}
					else
					{
						printf("\nInorder traversal is :\n");
						fnInOrder(root);
						printf("\n");
					}
					break;
			case 3:if(root==NULL)
					{
						printf("\nTree is Empty\n");
					}
					else
					{
						printf("\nPreorder traversal is :\n");
						fnPreOrder(root);
						printf("\n");
					}
					break;
			case 4:if(root==NULL)
					{
						printf("\nTree is Empty\n");
					}
					else
					{
						printf("\nPostorder traversal is :\n");
						fnPostOrder(root);
						printf("\n");
					}
					break;
			case 5:printf("\nEnter the node to be deleted :");
					scanf("%d",&iItem);
					root=fnDeleteNode(root,iItem);
					break;
			case 6: exit(0);
			default:printf("\nInvalid choice\n");
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
* Function 			:	fnInsertNode
* Description 		:	Function to insert an element to BST
*Input parameters	:	
*	NODEPTR root 	-	node pointing to root node
*	int iItem		- 	value contains element to be inserted
* RETURNS			:	pointer to root node
***************************************************************************/
NODEPTR fnInsertNode(int iItem,NODEPTR root)
{
	NODEPTR temp,cur,prev;
	temp=fnGetNode();
	temp->info=iItem;
	temp->lbranch=temp->rbranch=NULL;
	if(root==NULL )
		return temp;
	prev=NULL;
	cur=root;
	while(cur!=NULL)
	{
		prev=cur;
		if(iItem== cur->info)
		{
			printf("\nDuplicate items not allowed\n");
			fnFreeNode(temp);
			return root;
		}
		cur= (iItem < cur->info)?cur->lbranch:cur->rbranch;
	}
	if(iItem < prev->info)
	{
		prev->lbranch=temp;
	}
	else
		prev->rbranch=temp;
	return root;
}
/***************************************************************************
* Function 			:	fnPreOrder
* Description 		:	Function to perform preorder traversal
*Input parameters	:	
*	NODEPTR root 	-	node pointing to root node
* RETURNS			:	no value
***************************************************************************/
void fnPreOrder(NODEPTR root)
{
	if(root !=NULL)
	{
		printf("%d\t",root->info);
		fnPreOrder(root->lbranch);
		fnPreOrder(root->rbranch);
	}
}
/***************************************************************************
* Function 			:	fnInOrder
* Description 		:	Function to perform inorder traversal
*Input parameters	:	
*	NODEPTR root 	-	node pointing to root node
* RETURNS			:	no value
***************************************************************************/
void fnInOrder(NODEPTR root)
{
	if(root !=NULL)
	{
		fnPreOrder(root->lbranch);
		printf("%d\t",root->info);
		fnPreOrder(root->rbranch);
	}
}
/***************************************************************************
* Function 			:	fnPostOrder
* Description 		:	Function to perform postorder traversal
*Input parameters	:	
*	NODEPTR root 	-	node pointing to root node
* RETURNS			:	no value
***************************************************************************/
void fnPostOrder(NODEPTR root)
{
	if(root !=NULL)
	{
		fnPreOrder(root->lbranch);
		fnPreOrder(root->rbranch);
		printf("%d\t",root->info);
	}
}
/***************************************************************************
* Function 			:	fnDeleteNode
* Description 		:	Function to delete a node from BST
*Input parameters	:	
*	NODEPTR root 	-	node pointing to root node
*	int iItem		- 	value contains element to be deleted
* RETURNS			:	pointer to root node
***************************************************************************/
NODEPTR fnDeleteNode(NODEPTR root,int iItem)
{
	if(root==NULL)
	{
		printf("\nBST is empty,cannot delete");
		return root;
	}
	if(iItem > root->info)
	{
		root->rbranch=fnDeleteNode(root->rbranch,iItem);
	}
	else if(iItem < root->info)
	{
		root->lbranch=fnDeleteNode(root->lbranch,iItem);
	}
	else    // when match is found
	{
		if(root->lbranch ==NULL)
		{
			NODEPTR temp=root->rbranch;
			free(root);
			return temp;
		}
		else if(root->rbranch ==NULL)
		{
			NODEPTR temp=root->lbranch;
			free(root);
			return temp;
		}
		NODEPTR temp=fnMinValueNode(root->rbranch);
		root->info =temp->info;
		root->rbranch = fnDeleteNode(root->rbranch,temp->info);  //to delete the temp node 	
	}
	return root;
}
/***************************************************************************
* Function 			:	fnMinValueNode
* Description 		:	Function to find minimum vslue node BST
*Input parameters	:	
*	NODEPTR node	-	node pointing to right branch node
* RETURNS			:	pointer to node
***************************************************************************/
NODEPTR fnMinValueNode(NODEPTR node)
{
	NODEPTR current =node;
	while(current->lbranch!=NULL)
		current=current->lbranch;
	return current;
}
