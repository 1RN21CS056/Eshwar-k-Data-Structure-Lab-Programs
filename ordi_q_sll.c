//Program to implement ordinary queue using SLL

#include<stdio.h>
#include<stdlib.h>

//Declaration of structure
struct node
{
	int info;
	struct node * link;
};

typedef struct node * NODE;

//Function to allocate memory
NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if(temp==NULL)	//Memory not available
	{
		printf("Memory is not available\n");
		exit(0);
	}
	return temp;	//Memory is available
}

//Function to insert the element to the queue
NODE insert(NODE queue,int elem)
{
	NODE temp=getnode();	//Allocating memory
	temp->info=elem;
	temp->link=NULL;
	if(queue==NULL)	//Empty queue
		return temp;
	NODE cur =queue;
	while(cur->link!=NULL)	//To find the last node
		cur=cur->link;
	cur->link=temp;	//Linking new node
	return queue;
}


//Function to delete the element from the Queue
NODE delete(NODE queue)
{
	if(queue==NULL)	//Empty queue
	{
		printf("No elements in queue\n");
		return NULL;
	}
	NODE cur=queue->link;
	printf("The deleted element is %d\n",queue->info);	//Displaying the deleted element
	free(queue);	//Deallocating the node of deleted element
	return cur;
}

//Function to display the elements of the Queue
void display(NODE queue)
{
	if(queue==NULL){	//Empty queue
		printf("No elements in queue\n");
		return;
	}
	printf("Dispalying the elements of Queue\n");	//Elements are present in queue
	NODE cur=queue;
	while(cur!=NULL)	//Displaying the elements
	{
		printf("%d\t",cur->info);
		cur=cur->link;
	}
	printf("\n");
}

int main()
{
	NODE queue = NULL;
	int ch,elem;
	while(1)
	{
		printf("Enter\n1-Insert\n2-Delete\n3-Display\n");	//Accepting the choice
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
					printf("Enter the element to be inserted\n");	//Accepting the element to be inserted
					scanf("%d",&elem);
					queue=insert(queue,elem);
					break;
			case 2 :
					queue=delete(queue);
					break;
			case 3 :
					display(queue);
					break;
			default : 
					printf("Invalid choice\n");
					exit(0);
		}
	}
	return 0;
}