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
NODE insert_front(NODE first,int elem)
{
	NODE temp;
	temp=getnode();
	temp->info=elem;
	temp->link=first;
	return temp;
}
NODE insert_rear(NODE first,int elem)
{
	NODE temp,curr;
	curr=first;
	temp=getnode();
	temp->info=elem;
	temp->link=NULL;
	if(first==NULL)
	return temp;
	while(curr->link!=NULL)
	{
		curr=curr->link;
	}
	curr->link=temp;
	return first;
}
NODE delete_front(NODE first)
{
	NODE next;
	if(first==NULL)
	{
		printf("Deletion not possible\n");
		return NULL;
	}
	if(first->link==NULL)
	{
		printf("The deleted element is %d\n",first->info);
		free(first);
		return NULL;
	}
	next = first->link;
	printf("The deleted element is %d\n",first->info);
	free(first);
	return next;
}
NODE delete_rear(NODE first)
{
	NODE curr,pre;
	if(first==NULL)
	{
		printf("Deletion not possible\n");
		return NULL;
	}
	if(first->link==NULL)
	{
		printf("The deleted element is %d\n",first->info);
		free(first);
		return NULL;
	}
	curr=first;
	while(curr->link!=NULL)
	{
		pre=curr;
		curr=curr->link;
	}
	pre->link=NULL;
	printf("The deleted element is %d\n",curr->info);
	free(curr);
	return first;
}
int count(NODE first)
{
	int i=0;
	while(first!=NULL)
	{
		i++;
		first=first->link;
	}
	return i;
}
NODE delete_specific(NODE first,int pos)
{
	NODE curr,pre,next;
	pre=NULL;
	curr=first;
	if(count(first)>pos)
	{
		for(int i=1; i<=pos; i++)
		{
			pre=curr;
			curr=curr->link;
		}
		if(curr->link!=NULL)
		next=curr->link;
		else
		next=NULL;
		printf("The deleted element is %d\n",curr->info);
		if(pre!=NULL)
		pre->link=next;
		else
		return curr->link;
		return first;
	}
	else
	{
		printf("Deletiom is not possible\n");
	}
}
void display(NODE first)
{
	if(first==NULL)
	{
		printf("No elements to display\n");
	}
	else
	{
		printf("Displayig the elements of SLL:\n");
		while(first!=NULL)
		{
			printf("%d\t",first->info);
			first=first->link;
		}
		printf("\n");
	}
}
int main()
{
	int op,elem,pos;
	NODE first;
	first=NULL;
	while(1)
	{
		printf("Enter an option\n");
		printf("1:insert front\n2:insert rear\n3:delete front\n4:delete rear\n5:display\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			printf("Enter an element to be inserted\n");
			scanf("%d",&elem);
			first= insert_front(first,elem);
			break;
			case 2:
			printf("Enter an element to be inserted\n");
			scanf("%d",&elem);
			first= insert_rear(first,elem);
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
			printf("Enter which position node must be deleted\n");
			scanf("%d",&pos);
			first=delete_specific(first,pos);
			break;
			default :
			printf("invalid option\n");
			return 0;
		}
	}
	return 0;
}