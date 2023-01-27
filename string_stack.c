//Program to implement string stack

#include<stdio.h>
#include<string.h>

void push(char S[20][20],char elem[20],int *top)
{
	
	if((*top)==19)
		printf("The stack is full\n");
	else
	{
		(*top)++;
		strcpy(S[*top],elem);
	}
}

void pop(char S[20][20],int *top)
{
	
	if((*top)==-1)
		printf("The stack is empty\n");
	else
	{
		printf("The popped element is %s\n",S[*top]);
		(*top)--;
	}
}

void display(char S[20][20],int top)
{
	if(top==-1)
		printf("The stack is empty\n");
	else
	{
		printf("Displaying the elements of the stack\n");
		while(top>=0)
		{
			printf("%s\n",S[top]);
			top--;
		}
	}
	printf("\n\n");
}

int main()
{
	char S[20][20],elem[20];
	int top=-1,choice;
	while(1)
	{
		printf("Enter 1-push\n2-pop\n3-display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the string to be pushed\n");
				scanf("%s",elem);
				push(S,elem,&top);
				break;
			case 2:pop(S,&top);
				break;
			case 3: display(S,top);
				 break;
			default: printf("Invalid choice\n");
				  return 0;
		}
	}
	return 0;
}
