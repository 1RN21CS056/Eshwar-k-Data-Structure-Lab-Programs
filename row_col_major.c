//Program to implement row and column major

#include<stdio.h>

//Function to accept the values of the matrix
void display(int a[10][10],int n,int m)
{
	
	int i,j;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}	
}

//Function to display the elements in row major
void row_major(int a[10][10],int n,int m)
{
	int i,j;
	printf("Enter the elements of the matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
}

//Function to display the elements in column major
void col_major(int a[10][10],int n,int m)
{
	int i,j;
	printf("Enter the elements of the matrix\n");
	for(j=0;j<m;j++)
		for(i=0;i<n;i++)
			scanf("%d",&a[i][j]);
	
}

int main()
{
	int a[10][10],b[10][10],n,m;
	printf("Enter the size of the matrix\n");
	scanf("%d%d",&n,&m);
	
	row_major(a,n,m);
	col_major(b,n,m);
	printf("Displaying in row major\n");
	display(a,n,m);
	printf("Displaying in column major\n");
	display(b,n,m);
	return 0;
}

