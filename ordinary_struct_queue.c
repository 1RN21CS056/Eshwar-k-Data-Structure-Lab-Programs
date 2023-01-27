//Program to implement ordinary queue for structur employee
#include<stdio.h>
#include<stdlib.h>
#define max_size 20

typedef 
struct emp
{
	int eid;
	char ename[20];
} E;

//Function to insert the structure to the queue
void insert(E Q[max_size],int *rear,E elem)
{
	if(*rear == max_size-1)
		printf("Queue is full,insertion is not possible\n");
	else
	{
		(*rear)++;
		Q[*rear]=elem;
	}
}

//Function to delete the structure from the queue
void delete(E Q[max_size],int *front,int rear)
{
	if(*front>rear)
		printf("No elememts in the queue,deletion is not possible\n");
	else
	{
		printf("The deleted structure is\nName: %s\nID: %d\n",Q[*front].ename,Q[*front].eid);
		(*front)++;
	}
}

//Function to display the elements of the queue
void display(E Q[max_size],int front,int rear)
{
	if(front>rear)
		printf("No elements in the queue\n");
	else
	{
		printf("Displaying the elements of the queue\n");
		while(front<=rear)
		{
			printf("Name: %s\nId: %d\n",Q[front].ename,Q[front].eid);
			printf("\n\n");
			front++;
		}
	}
}

int main()
{
	int front=0,rear=-1,ch;
	E Q[max_size],elem;
	while(1)
	{
		printf("Enter 1-insert\n2-delete\n3-display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the name and id to be inserted\n");
				scanf("%s%d",elem.ename,&(elem.eid));
				insert(Q,&rear,elem);
				break;
			case 2:
				delete(Q,&front,rear);
				break;
			case 3:
				display(Q,front,rear);
				break;
			default:
				printf("Invalid choice\n");
				exit(0);
		}
	}
	return 0;
}
