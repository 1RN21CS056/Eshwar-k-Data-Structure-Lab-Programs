//Program to implement bubble sort
#include<stdio.h>
int main()
{
	int n,a[10],count=0;
	printf("Enter the number of elements in an array:");
	scanf("%d",&n);
	printf("Enter the elements of the array:");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
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
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]==a[j+1])
			{
				for(i=1;i<n-1;i++)
				{
					a[j+i]=a[j+i+1];
					count++;
				}
			}
		}
	}
	for(i=0;i<=count;i++)
		printf("%d\t",a[i]);
	return 0;
}
