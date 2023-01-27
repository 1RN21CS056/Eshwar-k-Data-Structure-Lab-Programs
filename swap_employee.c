//Program to swap employee details

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

void swap(E * e1,E *e2)
{
	E temp;
	temp=*e1;
	*e1=*e2;
	*e2=temp;
}

void display(E * E1,int n)
{
	printf("\n\nDisplaying the details of employee %d:",n);
	printf("\nName:%s",(*E1).Ename);
	printf("\nEmployee ID:%d",(*E1).Eid);
	printf("\nSalary:%f",(*E1).Esal);
}
	
int main()
{
	E E1,E2;
	accept(&E1);
	accept(&E2);
	swap(&E1,&E2);
	display(&E1,1);
	display(&E2,2);
	return 0;
}
