#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *llink,*rlink;
};
typedef struct node *NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x== NULL)
	{
		printf("Memory not available\n");
		exit(0);
	}
	return x;
}
NODE insert_front(NODE first,int elem)
{
	NODE temp;
	temp=getnode();
	temp->info=elem;
	temp->llink=temp->rlink=NULL;
	if(first==NULL)
	return temp;
	temp->rlink=first;
	first->llink=temp;
	return temp;
}
NODE insert_rear(NODE first,int elem)
{
	NODE temp,curr=first,pre=NULL;
	temp=getnode();
	temp->info=elem;
	temp->rlink=temp->llink=NULL;
	if(first==NULL)
	return temp;
	while(curr->rlink!=NULL)
	{
		curr=curr->rlink;
	}
	temp->llink=curr;
	curr->rlink=temp;
	return first;
}
NODE delete_front(NODE first)
{
	if(first==NULL)
	{
		printf("Deletion is not possible\n");
		return NULL;
	}
	NODE next=first->rlink;
	printf("The deleted element is %d\n",first->info);
	free(first);
	if(next!=NULL)
	next->llink=NULL;
	return next;
}
NODE delete_rear(NODE first)
{
	if(first==NULL)
	{
		printf("Deletion is not possible\n");
		return NULL;
	}
	NODE pre=NULL,curr=first;
	while(curr->rlink!=NULL)
	{
		pre=curr;
		curr=curr->rlink;
	}
	printf("The deleted element is %d\n",curr->info);
	if(pre==NULL)
	return NULL;
	pre->rlink=NULL;
	free(curr);
	return first;
}
void display(NODE first)
{
	if(first==NULL)
	{
		printf("No elements to display\n");
		return;
	}
	printf("Displaying elements of DLL:\n");
	while(first!=NULL)
	{
		printf("%d\t",first->info);
		first=first->rlink;
	}
	printf("\n");
}
int count(NODE first)
{
	int c=0;
	while(first!=NULL)
	{
		c++;
		first=first->rlink;
	}
	return c;
}
int main()
{
	NODE first=NULL;
	int elem,op;
	while(1)
	{
		printf("Enter an option\n");
		printf("1: insert at front\n2: insert at rear\n3: delete front\n4: delete rear\n5: display\n6: count number of nodes\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			printf("Enter the element to be inserted\n");
			scanf("%d",&elem);
			first=insert_front(first,elem);
			break;
			case 2:
			printf("Enter the element to be inserted\n");
			scanf("%d",&elem);
			first=insert_rear(first,elem);
			break;
			case 3:
			first=delete_front(first);
			break;
			case 4:
			first=delete_rear(first);
			break;
			case 5:
			display(first);
			break;
			case 6:
			printf("There are %d nodes in dll\n",count(first));
			break;
			default:
			printf("Invalid option\n");
			exit(0);
		}
	}
	return 0;
}