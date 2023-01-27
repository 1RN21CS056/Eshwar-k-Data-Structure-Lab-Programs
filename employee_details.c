//Program to accept and display members pf the structure

#include<stdio.h>
struct Employee
{
	int Eid;
	char Ename[20];
	float Esal;
};
typedef struct Employee E;

int main()
{
	E E1;
	printf("Enter the employee id:");
	scanf("%d",&E1.Eid);
	printf("Enter the employee name:");
	scanf("%s",E1.Ename);
	printf("Enter the employee salary:");
	scanf("%f",&E1.Esal);
	printf("Displaying the employee details:");
	printf("\n\nName:%s",E1.Ename);
	printf("\nEmployee ID:%d",E1.Eid);
	printf("\nSalary:%f",E1.Esal);
	return 0;
}
