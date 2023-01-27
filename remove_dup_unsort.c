//Program to implement bubble sort
#include<stdio.h>
int main()
{
	int n,a[10],count=0,pos,temp;
	printf("Enter the number of elements in an array:");
	scanf("%d",&n);
	printf("Enter the elements of the array:");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int i,j;
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=0;j<n;j++)
		{
			if(pos!=j)
			{
				if(a[pos]!=0)
				{
					if(a[pos]==a[j])
					{
						a[j]=0;
						count++;
					}
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(i=0;i<n-count;i++)
		printf("%d\t",a[i]);
	return 0;
}
