//Program to implement stack

#include<stdio.h>

#define max_size 5

void push(int S[max_size],int *top,int elem)
{
	if((*top)==max_size-1)
		printf("Overflow condition\n");
	else
	{
		(*top)++;
		S[(*top)]=elem;
	}
}

void pop(int S[max_size] ,int *top)
{
	if((*top)==-1)
		printf("Underflow condition\n");
	else
	{
		printf("The deleted element is %d\n",S[(*top)]);
		(*top)--;
	}
}

void display(int S[max_size],int top)
{
	for(int i=0;i<=top;i++)
		printf("%d\n",S[i]);
}

int main()
{
	int S[max_size],top=-1,elem,choice;
	while(1)
	{
		printf("Enter	your choice\n1-push\n2-pop\n3-display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : printf("Enter the element to be pushed\n");
				 scanf("%d",&elem);
				 push(S,&top,elem);
				 break;
			case 2: pop(S,&top);
				break;
			case 3: display(S,top);
				break;
			default : return 0;
		}
	}
}
