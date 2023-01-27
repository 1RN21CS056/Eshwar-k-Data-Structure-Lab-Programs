#include<stdio.h>
#include<stdlib.h>

void accept(int a[10][10],int b[10][10],int *m,int *n,int *p,int *q)
{
	int i,j;
	printf("Enter the size of first matrix:\n");
	scanf("%d%d",m,n);
	printf("Enter the size of second matrix:\n");
	scanf("%d%d",p,q);
	if((*n)!=(*p))
	{
		printf("Matrix multiplication is not possible\n");
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

void multiply(int a[10][10],int b[10][10],int r[10][10],int m,int q,int n)
{
	int i,j,k;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			r[i][j]=0;
			for(k=0;k<q;k++)
				r[i][j] = r[i][j]+a[i][k]*b[k][j];
		}
	}
}
	

void display(int r[10][10],int m,int q)
{
	printf("Displaying the rsultant matrix:\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<q;j++)
			printf("%d\t",r[i][j]);
		printf("\n");
	}
}

int main()
{
	int a[10][10],b[10][10],r[10][10],m,n,p,q;
	accept(a,b,&m,&n,&p,&q);
	multiply(a,b,r,m,q,n);
	display(r,m,q);
	return 0;
}
	
