/***************************************************************************
* Program 	:	01Files.c
* Description :	Program using files to search Employee details as per inputted details
* Author		:Rajanish Jha
* Date		:	22th November 2018
* Compiler	: 	gcc version 7.3.0 
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned int uint;
typedef struct 
{
	int e_ID;
	char e_Name[25];
	char e_Dept[25];
	uint e_Sal;
	uint e_Age;
}employee_t;

void fnDislplayAllRecord();
void fnAddRecord(void);
void fnSearchEmpID(int);
void fnSearchEmpSal(int);
void fnSearchEmpDept(char []);
void fnSearchEmpAge(int);
/***************************************************************************
*Function			:	main
*Input parameters	:	no parameters
*RETURNS			:	0 on success
***************************************************************************/
int main(void)
{
	int id,sal,age,iChoice;
	char dept[10];
	FILE *fp;
	fp=fopen("emp.dat","w");
	while(1)
	{
		printf("\n1. Add Record\n2. Search by EmployeeID\n3. Search by Salary\n4. Search by Department\n5.Search by age\n6. Display all Record\n7.Exit\n");
		printf("\nEnter your choice\t:");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1:fnAddRecord();
					break;
			case 2:printf("\nEnter the EmployeeID\t:");
					scanf("%d",&id);getchar();
					fnSearchEmpID(id);
					break;
			case 3:printf("\nEnter the Employee Salary\t:");
					scanf("%d",&sal);
					fnSearchEmpSal(id);
					break;
			case 4:printf("\nEnter the Employee Department\t:");
					scanf("%s",dept);
					fnSearchEmpDept(dept);
					break;
			case 5:printf("\nEnter the Employee Age\t:");
					scanf("%d",&age);
					fnSearchEmpAge(age);
					break;
			case 6:fnDislplayAllRecord();
					break;
			case 7:exit(0);
			default: printf("\nInvalid Choice");
		}
	}
	fclose(fp);
	return 0;
}
/***************************************************************************
* Function 			:	fnAddRecord
* Description 		:	Function to read the Employee Details
*Input parameters	:	no parameters
* RETURNS			:	no value
***************************************************************************/
void fnAddRecord()
{
	FILE *fp;
	employee_t emp;
	printf("\n-----------------Enter Employee Details-----------------\n");
	printf("\tID\t:");
	scanf("%d",&emp.e_ID);
	getchar();
	printf("\tName\t:");
	fgets(emp.e_Name,25,stdin);
	printf("\tDepartment\t:");
	fgets(emp.e_Dept,25,stdin);
	printf("\tSalary\t:");
	scanf("%d",&emp.e_Sal);
	printf("\tAge\t:");
	scanf("%d",&emp.e_Age);
	fp=fopen("emp.dat","a");
	fprintf(fp,"%d\t%s\t%s\t\t%d\t%d\n",emp.e_ID,emp.e_Name,emp.e_Dept,emp.e_Sal,emp.e_Age);
	fclose(fp);
	printf("\n----------------------------------------------------------\n");
}
/***************************************************************************
* Function 			:	fnDislplayAllRecord
* Description 		:	Function to display the Employee Details
*Input parameters	:	no parameters
* RETURNS			:	no value
***************************************************************************/
void fnDislplayAllRecord()
{
	int iCount=0;
	employee_t emp;
	FILE *fp;
	fp=fopen("emp.dat","r");
	if(fp==NULL)
	{
		printf("\nFile does not exist\n");
		return;
	}
	printf("\nID\tNAME\tDEPARTMENT\tSALARY\tAGE\n");
	printf("----------------------------------------------------------\n");
	while(fscanf(fp,"%d%s%s%d%d",&emp.e_ID,emp.e_Name,emp.e_Dept,&emp.e_Sal,&emp.e_Age)!=EOF)
	{
		printf("%d\t%s\t%s\t\t%d\t%d\n",emp.e_ID,emp.e_Name,emp.e_Dept,emp.e_Sal,emp.e_Age);
		iCount++;
	}
	if(iCount==0)
		printf("\nNo Record Found\n");
	fclose(fp);
}
void fnSearchEmpID(int id)
{
	int iCount=0;
	employee_t emp;
	FILE *fp;
	fp=fopen("emp.dat","r");
	if(fp==NULL)
	{
		printf("\nFile does not exist\n");
		return;
	}
	printf("\nID\tNAME\tDEPARTMENT\tSALARY\tAGE\n");
	printf("----------------------------------------------------------\n");
	while(fscanf(fp,"%d%s%s%d%d",&emp.e_ID,emp.e_Name,emp.e_Dept,&emp.e_Sal,&emp.e_Age)!=EOF)
	{
		if(emp.e_ID==id)
		{
			printf("%d\t%s\t%s\t\t%d\t%d\n",emp.e_ID,emp.e_Name,emp.e_Dept,emp.e_Sal,emp.e_Age);
			iCount++;
		}
	}
	if(iCount==0)
		printf("\nNo Record Found\n");
	fclose(fp);
}
/***************************************************************************
* Function 			:	fnSearchEmpDept
* Description 		:	Function to search the Employee Details
*Input parameters	:	
*	char d[25] 		-	contains employee department
* RETURNS			:	no value
***************************************************************************/
void fnSearchEmpDept(char d[25])
{
	int iCount=0;
	employee_t emp;
	FILE *fp;
	fp=fopen("emp.dat","r");
	if(fp==NULL)
	{
		printf("\nFile does not exist\n");
		return;
	}
	printf("\nID\tNAME\tDEPARTMENT\tSALARY\tAGE\n");
	printf("----------------------------------------------------------\n");
	while(fscanf(fp,"%d%s%s%d%d",&emp.e_ID,emp.e_Name,emp.e_Dept,&emp.e_Sal,&emp.e_Age)!=EOF)
	{
		if(strcmp(emp.e_Dept,d)==0)
		{
			printf("%d\t%s\t%s\t\t%d\t%d\n",emp.e_ID,emp.e_Name,emp.e_Dept,emp.e_Sal,emp.e_Age);
			iCount++;
		}
	}
	if(iCount==0)
		printf("\nNo Record Found\n");
	fclose(fp);
}
/***************************************************************************
* Function 			:	fnSearchEmpSal
* Description 		:	Function to search the Employee Details
*Input parameters	:	
*	int sal			-	value containing employee salary
* RETURNS			:	no value
***************************************************************************/
void fnSearchEmpSal(int sal)
{
	int iCount=0;
	employee_t emp;
	FILE *fp;
	fp=fopen("emp.dat","r");
	if(fp==NULL)
	{
		printf("\nFile does not exist\n");
		return;
	}
	printf("\nID\tNAME\tDEPARTMENT\tSALARY\tAGE\n");
	printf("----------------------------------------------------------\n");
	while(fscanf(fp,"%d%s%s%d%d",&emp.e_ID,emp.e_Name,emp.e_Dept,&emp.e_Sal,&emp.e_Age)!=EOF)
	{
		if(emp.e_Sal==sal)
		{
			printf("%d\t%s\t%s\t\t%d\t%d\n",emp.e_ID,emp.e_Name,emp.e_Dept,emp.e_Sal,emp.e_Age);
			iCount++;
		}
	}
	if(iCount==0)
		printf("\nNo Record Found\n");
	fclose(fp);
}
/***************************************************************************
* Function 			:	fnSearchEmpDept
* Description 		:	Function to search the Employee Details
*Input parameters	:	
*	int age 		-	value contains employee age
* RETURNS			:	no value
***************************************************************************/
void fnSearchEmpAge(int age)
{
	int iCount=0;
	employee_t emp;
	FILE *fp;
	fp=fopen("emp.dat","r");
	if(fp==NULL)
	{
		printf("\nFile does not exist\n");
		return;
	}
	printf("\nID\tNAME\tDEPARTMENT\tSALARY\tAGE\n");
	printf("----------------------------------------------------------\n");
	while(fscanf(fp,"%d%s%s%d%d",&emp.e_ID,emp.e_Name,emp.e_Dept,&emp.e_Sal,&emp.e_Age)!=EOF)
	{
		if(emp.e_Age==age)
		{
			printf("%d\t%s\t%s\t\t%d\t%d\n",emp.e_ID,emp.e_Name,emp.e_Dept,emp.e_Sal,emp.e_Age);
			iCount++;
		}
	}
	if(iCount==0)
		printf("\nNo Record Found\n");
	fclose(fp);
}
