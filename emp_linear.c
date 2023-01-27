#include<stdio.h>
#include<string.h>

struct EMP
{
	int Eid;
	char Ename[20];
};

typedef struct EMP E;

void accept(E emp[10],int *n)
{
	printf("Enter the total number of employees:\n");
	scanf("%d",n);
	for(int i=0;i<*n;i++)
	{
		printf("Enter the name of the employee:\n");
		scanf("%s",emp[i].Ename);
		printf("Enter the employee id:\n");
		scanf("%d",&(emp[i].Eid));
	}
}

void search(E emp[10],int n)
{
	int ch,key_id,i;
	char key_name[20];
	printf("On what basis you want to search:\n");
	printf("1-Employee ID\t2-Employee name\nEnter your choice:\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 : printf("Enter the id to be searched:\n");
			  scanf("%d",&key_id);
			  for(i=0;i<n;i++)
			  {
			  	if(emp[i].Eid==key_id)
			  	{
			  		printf("It is found at %d position\n",i);
			  		printf("Employee ID : %d\n",emp[i].Eid);
			  		printf("Employee Name : %s\n",emp[i].Ename);
			  		return;
			  	}
			  }
			  printf("The enetered id is not found\n");
			  break;
		case 2 : printf("Enter the name to be searched:\n");
			  scanf("%s",key_name);
			  for(i=0;i<n;i++)
			  {
			  	if(strcmp(key_name,emp[i].Ename)==0)
			  	{
			  		printf("The enetered name is found at %d position\n",i);
			  		printf("Employee ID : %d\n",emp[i].Eid);
			  		printf("Employee Name : %s\n",emp[i].Ename);
			  		return;
			  	}
			  }
			  printf("The enetered name is not found\n");
			  break;
		default : printf("Invalid choice\n");
			   break;
	}
}

int main()
{
	E emp[10];
	int n;
	accept(emp,&n);
	search(emp,n);
	return 0;
}
			
		
	
