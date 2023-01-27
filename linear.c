//Program to implement linear search

#include<stdio.h>

void accept(int arr[10],int * n)
{
	printf("Enter the number of elements in an array\n");
	scanf("%d",n);
	printf("Enter the elements of the array\n");
	for(int i=0;i<*n;i++)
		scanf("%d",&arr[i]);
}

void search(int arr[10],int * key,int n)
{
	printf("Enter the key element to be searched\n");
	scanf("%d",key);
	for(int i=0;i<n;i++)
	{
		if(arr[i]==*key)
		{
			printf("The element is found at %d\n",i);
			return;
		}
	}
	printf("The element is not found\n");
}

int main()
{
	int arr[10],n,key;
	accept(arr,&n);
	search(arr,&key,n);
	return 0;
}
