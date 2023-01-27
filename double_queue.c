//Program to implement double ended queue
#include<stdio.h>
#include<stdlib.h>
#define max_size 20

//Function to insert the element at the rear of double ended queue
void insert_rear_DQ(int DQ[max_size],int *rear,int elem)
{
	if(*rear==max_size-1)
		printf("Insertion at the rear is not possible\n");
	else
	{
		(*rear)++;
		DQ[*rear]=elem;
	}
}

//Function to insert the element at the front of the double ended queue
void insert_front_DQ(int DQ[max_size],int *front,int *rear,int elem)
{
	if(*front==0 && *rear==-1)
	{
		(*rear)++;
		DQ[*rear]=elem;
	}
	else if(*front!=0)
	{
		(*front)--;
		DQ[*front]=elem;
	}
	else
		printf("Insertion at the front is not possible\n");
}

//Function to delete the element at the front of the double ended queue
void delete_front_DQ(int DQ[max_size],int *front,int *rear)
{
	if(*front==0 && *rear==-1)
		printf("Queue is empty,deletion is not possibe\n");
	else
	{
		printf("The deleted element is %d\n",DQ[*front]);
		(*front)++;
		if(*front>*rear)
		{
			*front=0;
			*rear=-1;
		}
	}
}

//Function to delete the element at the rear of double ended queue
void delete_rear_DQ(int DQ[max_size],int *front,int *rear)
{
	if(*front ==0 && *rear ==-1)
		printf("Queue is empty,deletion is not possible\n");
	else
	{
		printf("The deleted element is %d\n",DQ[*rear]);
		(*rear)--;
		if(*front>*rear)
		{
			*front=0;
			*rear=-1;
		}
	}
}

//Function to display the elements of the double ended queue
void display_DQ(int DQ[max_size],int front,int rear)
{
	//No elements in the queue
	if(front==0 && rear==-1)
		printf("There are no elements in the queue\n");
	//There are elements in the queue
	else
	{
		printf("Displaying the elements of the queue\n");
		while(front<=rear)	
		{
			printf("%d\t",DQ[front]);
			front++;
		}
	}
}

int main()
{
	int DQ[max_size],elem,ch,front=0,rear=-1;
	while(1)
	{
		printf("Enter 1-insert rear\n2-insert front\n3-delete front\n4-delete rear\n5-display\n6-exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element to be inserted\n");
				scanf("%d",&elem);
				insert_rear_DQ(DQ,&rear,elem);
				break;
			case 2:
				printf("Enter the element to be inserted\n");
				scanf("%d",&elem);
				insert_front_DQ(DQ,&front,&rear,elem);
				break;
			case 3:
				delete_front_DQ(DQ,&front,&rear);
				break;
			case 4:
				delete_rear_DQ(DQ,&front,&rear);
				break;
			case 5:
				display_DQ(DQ,front,rear);
				break;
			default:
				printf("Program terminated\n");
				exit(0);
		}
	}
	return 0;
}

