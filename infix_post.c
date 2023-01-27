//Program to convert oinfix expression to postfix expression

#include<stdio.h>

void push(char S[20],int * top,char elem)
{
	if(*top==19)
		printf("Element cannot be inserted\n");
	else
	{
		(*top)++;
		S[*top]=elem;
	}
}

char pop(char S[20],int *top)
{
	char elem;
	elem=S[*top];
	(*top)--;
	return elem;
}

int F(char symbol)
{
	switch(symbol)
	{	
		case '+':
		case '-': return 2;
		case '*':
		case '/':return 4;
		case '$':
		case '^': return 5;
		case '#':return -1;
		case '(': return 0;
		default : return 8;
	}
}

int G(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 3;
		case '$':
		case '^': return 6;
		case ')':return 0;
		case '(': return 9;
		default : return 7;
	}
}

void conv_postfix(char infix[20],int *top,char S[20])
{
	int i=0,j=0;
	char postfix[20];
	while(infix[i]!='\0')
	{
		while(F(S[*top])>G(infix[i]))
			postfix[j++]=pop(S,top);
		if(F(S[*top])!=G(infix[i]))
			push(S,top,infix[i]);
		else
			(*top)--;
		i++;
	}
	while(S[*top]!='#')
		postfix[j++]=pop(S,top);
	postfix[j]='\0';
	printf("The postfix expression is %s\n",postfix);
	
}

int main()
{
	char infix[20],S[20];
	int top=-1;
	push(S,&top,'#');
	printf("Enter the infix expression\n");
	scanf("%s",infix);
	conv_postfix(infix,&top,S);
	return 0;
}

