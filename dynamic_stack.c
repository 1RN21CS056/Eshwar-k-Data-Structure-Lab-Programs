//Program to implement stack using dnamic memory allocation

#include<stdio.h>
#include<stdlib.h>

int * push(int *S , int * top,int elem)
{
	if((*top)==-1)
	{
		(*top)++;
		S[*top]=elem;
	}
	else
	{
		(*top)++;
		S=(int*) realloc(S,sizeof(int)*((*top)+1));
		S[*top]=elem;
	}
	return S;
}

int * pop(int *S,int *top)
{
	if((*top)==0)
	{
		printf("The popped element is %d\n",S[*top]);
		(*top)--;
	}
	else
	{
		printf("The popped element is %d\n",S[*top]);
		(*top)--;
		S=(int *)realloc(S,sizeof(int)*((*top)+1));
	}
	return S;
}

void display(int *S,int top)
{
	if(top==-1)
		printf("The stack is empty\n");
	else
	{
		printf("Displaying the elements of the stack\n");
		while(top>=0)
		{
			printf("%d\n",S[top]);
			top--;
		}
	}
}

int main()
{
	int *S;
	int top=-1,elem,choice;
	S=(int*)malloc(sizeof(int));
	while(1)
	{
		printf("Enter 1 - Push\n2 - Pop\n3 - Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : printf("Enter the element to be pushed\n");
				  scanf("%d",&elem);
				  S=push(S,&top,elem);
				  break;
			case 2 : S=pop(S,&top);
				  break;
			case 3 : display(S,top);
				  break;
			default : printf("Invalid choice\n");
				   return 0;
		}
	}
	return 0;
}
