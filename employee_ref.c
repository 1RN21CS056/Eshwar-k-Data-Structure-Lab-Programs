//Program to accept and display employee details using structure by call by reference

#include<stdio.h>
struct Employee
{
	int Eid;
	char Ename[20];
	float Esal;
};
typedef struct Employee E;

void accept(E * E1)
{
	printf("Enter the employee id:");
	scanf("%d",&(*E1).Eid);
	printf("Enter the employee name:");
	scanf("%s",(*E1).Ename);
	printf("Enter the employee salary:");
	scanf("%f",&(*E1).Esal);
}

void display(E * E1)
{
	printf("\nDisplaying the employee details:");
	printf("\n\nName:%s",(*E1).Ename);
	printf("\nEmployee ID:%d",(*E1).Eid);
	printf("\nSalary:%f",(*E1).Esal);
}
	
int main()
{
	E E1;
	accept(&E1);
	display(&E1);
	return 0;
}
