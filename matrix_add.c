#include<stdio.h>
#include<stdlib.h>

void accept(int a[10][10],int b[10][10],int *m,int *n,int *p,int *q)
{
	int i,j;
	printf("Enter the size of first matrix:\n");
	scanf("%d%d",m,n);
	printf("Enter the size of second matrix:\n");
	scanf("%d%d",p,q);
	if((*m)!=(*p) || (*n)!=(*q))
	{
		printf("Matrix addition is not possible\n");
		exit(0);
	}
	else
	{
		printf("Enter the elements of first matrix:\n");
		for(i=0;i<*m;i++)
		{
			for(j=0;j<*n;j++)
				scanf("%d",&a[i][j]);
		}
		printf("Enter the elements of second matrix:\n");
		for(i=0;i<*m;i++)
		{
			for(j=0;j<*n;j++)
				scanf("%d",&b[i][j]);
		}
	}
}

void add(int a[10][10],int b[10][10],int r[10][10],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			r[i][j]= (a[i][j]+b[i][j]);
	}
}
	

void display(int r[10][10],int m,int n)
{
	printf("Displaying the rsultant matrix:\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d\t",r[i][j]);
		printf("\n");
	}
}

int main()
{
	int a[10][10],b[10][10],r[10][10],m,n,p,q;
	accept(a,b,&m,&n,&p,&q);
	add(a,b,r,m,n);
	display(r,m,n);
	return 0;
}
	
