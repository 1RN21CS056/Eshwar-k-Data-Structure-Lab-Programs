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

void sort(E emp[10],int n)
{
	int i,j;
	E temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(emp[j].Eid>emp[j+1].Eid)
			{
				temp=emp[j];
				emp[j]=emp[j+1];
				emp[j+1]=temp;
			}
		}
	}
}

void search(E emp[10],int n)
{
	int l,r,mid,key_id;
	l=0;
	r=n-1;
	printf("Enter the id to searched:\n");
	scanf("%d",&key_id);
	while(l<=r)
	{
		mid=(l+r)/2;
		if(emp[mid].Eid==key_id)
		{
			printf("The entered ID id found at position %d\n",mid);
			printf("Employee Id : %d\n",emp[mid].Eid);
			printf("Employee name : %s\n",emp[mid].Ename);
			return;
		}
		else if(emp[mid].Eid>key_id)
			r=mid-1;
		else
			l=mid+1;
	}
	printf("The entered ID is not found\n");
}

int main()
{
	E emp[10];
	int n;
	accept(emp,&n);
	sort(emp,n);
	search(emp,n);
	return 0;
}
	
		
	
