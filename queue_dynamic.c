//Program to implement ordinary queue using dynamic memeory allocation

#include<stdio.h>
#include<stdlib.h>
#define max_size 3

int * insert(int *Q,int *rear,int *front,int elem)
{
	printf("%d\n",*rear);
	if((*rear)==max_size-1)
	{
		Q=(int *)realloc(Q,sizeof(int)*((*rear)+2));
		(*rear)++;
		Q[*rear]=elem;
		return Q;
	}
	else
	{
		(*rear)++;
		Q[*rear]=elem;
		return Q;
	}
}

int * delete(int *Q,int *front,int *rear)
{
	int i,j;
	if(*front>*rear)
		printf("No elements in the queue\n");
	else
	{
		printf("The deleted element is %d\n",Q[*front]);
		for(i=0;i<*rear;i++)
			Q[i]=Q[i+1];
		Q=(int *)realloc(Q,sizeof(int)*((*rear)));
		(*rear)--;
		
	}
	return Q;
}

void display(int *Q,int front,int rear)
{
	if(front>rear)
		printf("Queue is empty\n");
	else
	{
		printf("Displaying the elements of the queue\n");
		for(int i=front;i<=rear;i++)
			printf("%d\t",Q[i]);
		printf("\n");
	}
}

int main()
{
	int *Q,rear=-1,front=0,elem,choice;
	Q=(int *)malloc(sizeof(int)*max_size);
	while(1)
	{
		printf("Enter\n1-Insert\n2-Delete\n3-Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the element to be inserted\n");
				 scanf("%d",&elem);
				 Q=insert(Q,&rear,&front,elem);
				 break;
			case 2: Q=delete(Q,&front,&rear);
				 break;
			case 3: display(Q,front,rear);
				 break;
			default: printf("Invalid choice\n");
				  return 0;
		}
	}
	return 0;
}
			
