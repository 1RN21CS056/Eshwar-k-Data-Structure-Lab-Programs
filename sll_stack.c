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

NODE delete_front(NODE first)
{
    NODE next;
    if(first == NULL)
    {
        printf("No elements to delete\n");
        return NULL;
    }
    else
    {
        printf("%d\n is the deleted element\n",first->info);
        next = first->link;
        free(first);
        return next;
    }
}

void display(NODE first)
{
    if(first == NULL)
    printf("Nothing to display\n");
    else
    {
        for(;first!=NULL;first = first->link)
        printf("%d\t",first->info);
        printf("\n");
    }
}
int main()
{
	int op,elem;
	NODE first;
	first=NULL;
	while(1)
	{
		printf("Enter an option\n");
		printf("1:push\n2:pop\n3:display\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			printf("Enter an element to be inserted\n");
			scanf("%d",&elem);
			first= insert_front(first,elem);
			break;
			case 2:
			first=delete_front(first);
			break;
			case 3:
			display(first);
			break;
			default :
			printf("invalid option\n");
			return 0;
		}
	}
	return 0;
}
