//Program to accept and display sparse matrix

#include<stdio.h>
typedef struct Sparse
{
	int row, col,value;
} S;

void accept(S a[10])
{
	int m,n,i,j,elem,k=1;
	printf("Enter the size of the sparse matrix:\n");
	scanf("%d%d",&m,&n);
	printf("Enter the elements of the sparse matrix\n");
	for(i=0;i<m;i++)
	{	
		for(j=0;j<n;j++)
		{
			scanf("%d",&elem);
			if(elem!=0)
			{
				a[k].row=i;
				a[k].col=j;
				a[k].value=elem;
				k++;//changes to be made
			}
		}
	}
	a[0].row=m;
	a[0].col=n;
	a[0].value=k-1;
}

void display(S a[10])
{
	int i,j,k=1;
	printf("Displaying the sparse matrix\n");
	for(i=0;i<a[0].row;i++)
	{
		for(j=0;j<a[0].col;j++)
		{
			if(i==a[k].row && j==a[k].col)
			{
				printf("%d\t",a[k].value);
				k++;
			}
			else
				printf("0\t");
		}
		printf("\n");
	}
}

int main()
{
	S a[10];
	accept(a);
	display(a);
	return 0;
}
	
