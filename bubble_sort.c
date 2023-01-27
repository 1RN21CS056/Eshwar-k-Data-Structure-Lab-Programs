//Program to implement bubble sort
#include<stdio.h>

void accept(int * n , int a[10])
{
	printf("Enter the number of elements in an array:");
	scanf("%d",n);
	printf("Enter the elements of the array:");
	for(int i=0;i<*n;i++)
		scanf("%d",&a[i]);
}

void sort(int *n , int a[10])
{
	int i,j;
	for(i=0;i<*n;i++)
	{
		for(j=0;j<*n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp;
				temp = a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void display(int n,int a[10])
{
	int i;
	printf("Displaying the sorted array elements:\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}

int main()
{
	int n,a[10];
	accept(&n,a);
	sort(&n,a);
	display(n,a);
}
