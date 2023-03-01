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
NODE concatenate_sll(NODE first,NODE second)
{
	NODE curr,res;
	res=NULL;
	if(first!=NULL)
	{
		curr=first;
		while(curr!=NULL)
		{
			res=insert_rear(res,curr->info);
			curr=curr->link;
		}
	}
	if(second!=NULL)
	{
		curr=second;
		while(curr!=NULL)
		{
			res=insert_rear(res,curr->info);
			curr=curr->link;
		}
	}
	return res;
}
int main()
{
	int op,elem,i,n;
	NODE first,second,temp,res;
	first=NULL;
	second=NULL;
	printf("Enter number of nodes required in first SLL\n");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		printf("Enter an element to be inserted\n");
		scanf("%d",&elem);
		first=insert_rear(first,elem);
	}
	printf("Enter number of nodes required in second SLL\n");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		printf("Enter an element to be inserted\n");
		scanf("%d",&elem);
		second=insert_rear(second,elem);
	}
	res=concatenate_sll(first,second);
	printf("Displaying the concatenated SLL\n");
	display(res);
	
	return 0;
}