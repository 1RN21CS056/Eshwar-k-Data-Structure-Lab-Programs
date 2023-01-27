#include<stdio.h>
void accept(int a[10][10],int *m,int *n)
{
	printf("Enter the size of the matrix:\n");
	scanf("%d%d",m,n);
	printf("Enter the elements of the matrix:\n");
	for(int i=0;i<*m;i++)
	{
		for(int j=0;j<*n;j++)
			scanf("%d",&a[i][j]);
	}
}

void transpose(int a[10][10],int t[10][10],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			t[j][i]=a[i][j];
	}
}

void display(int t[10][10],int m,int n)
{
	printf("Displaying the transpose:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			printf("%d\t",t[i][j]);
		printf("\n");
	}
}

int main()
{
	int a[10][10],t[10][10],m,n;
	accept(a,&m,&n);
	transpose(a,t,m,n);
	display(t,m,n);
	return 0;
}
	
	
