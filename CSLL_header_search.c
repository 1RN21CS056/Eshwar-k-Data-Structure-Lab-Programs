#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int info;
	struct node* link;
};
typedef struct node* NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("MEMORY NOT AVAILABLE\n");
		exit(0);
	}
	return x;
}
void insert_front(NODE head,int elem)
{
	NODE temp;
	temp=getnode();
	temp->info=elem;
	temp->link=head->link;
	head->link=temp;
}
void insert_rear(NODE head,int elem)
{
	NODE temp,curr;
	curr=head;
	temp=getnode();
	temp->info=elem;
	temp->link=head;
	while(curr->link!=head)
	{
		curr=curr->link;
	}
	curr->link=temp;
}

void delete_front(NODE head)
{
	NODE curr;
	curr=head->link;
	if(curr==head)
	{
		printf("Deletion not possible\n");
		return;
	}
	printf("The deleted element is %d\n",curr->info);
	head->link=curr->link;
	free(curr);
}
void delete_rear(NODE head)
{
	NODE curr,pre;
	pre=head;
	curr=head->link;
	if(curr==head)
	{
		printf("Deletion not possible\n");
		return;
	}
	while(curr->link!=head)
	{
		pre=curr;
		curr=curr->link;
	}
	printf("The deleted element is %d\n",curr->info);
	pre->link=head;
	free(curr);
}
void display(NODE head)
{
	NODE curr=head->link;
	if(curr==head)
	{
		printf("No elements to display\n");
	}
	else
	{
		printf("Displayig the elements of CSLL:\n");
		while(curr!=head)
		{
			printf("%d\t",curr->info);
			curr=curr->link;
		}
		printf("\n");
	}
}
void search(NODE head,int key)
{
	int i=0;
	NODE curr=head->link;
	while(curr!=head)
	{
		if(curr->info == key)
		{
			printf("The element is found in node %d\n",i);
			return;
		}
		i++;
		curr=curr->link;
	}
	printf("The element is not found\n");
}
int main()
{
	int op,elem,n,key;
	NODE head;
	head=getnode();
	head->link=head;
	while(1)
	{
		printf("Enter an option\n");
		printf("1:insert front\n2:insert rear\n3:delete front\n4:delete rear\n5:display\n6: count number of nodes\n7: insert at a specific position\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			printf("Enter an element to be inserted\n");
			scanf("%d",&elem);
			insert_front(head,elem);
			break;
			case 2:
			printf("Enter an element to be inserted\n");
			scanf("%d",&elem);
			insert_rear(head,elem);
			break;
			case 3:
			delete_front(head);
			break;
			case 4:
			delete_rear(head);
			break;
			case 5:
			display(head);
			break;
			case 6:
			printf("Enter an element to be searched\n");
			scanf("%d",&key);
			search(head,key);
			break;
			default :
			printf("invalid option\n");
			return 0;
		}
	}
	return 0;
}
