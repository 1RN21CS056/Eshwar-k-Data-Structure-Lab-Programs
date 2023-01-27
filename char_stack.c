//Program to implement character stack

#include<stdio.h>

void push(char S[20],char elem,int *top)
{
	
	if((*top)==19)
		printf("The stack is full\n");
	else
	{
		(*top)++;
		S[*top]=elem;
	}
}

char pop(char S[20],int *top)
{
	char elem=S[*top];
	(*top)--;
	return elem;
}

void display(char S[20],int top)
{
	if(top==-1)
		printf("The stack is empty\n");
	else
	{
		printf("Displaying the elements of the stack\n");
		while(top>=0)
		{
			printf("%c\n",S[top]);
			top--;
		}
	}
	printf("\n\n");
}

int main()
{
	char S[20],elem;
	int top=-1,choice;
	while(1)
	{
		printf("Enter 1-push\n2-pop\n3-display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the character to be pushed\n");
				scanf("%c%c",&elem,&elem);
				push(S,elem,&top);
				break;
			case 2: if(top==-1)
					printf("Stack is empty\n");
				else
					printf("Popped element is %c\n",pop(S,&top));
				break;
			case 3: display(S,top);
				 break;
			default: printf("Invalid choice\n");
				  return 0;
		}
	}
	return 0;
}
