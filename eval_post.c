//Program to valuate postfix expression

#include<stdio.h>
#include<ctype.h>
#include<math.h>

void push(int S[20],int *top,int elem)
{
	(*top)++;
	S[*top]=elem;
}

int pop(int S[20],int *top)
{
	int elem=S[*top];
	(*top)--;
	return elem;
}

int evaluate(int op1,char op,int op2)
{
	switch(op)
	{
		case '+' : return op1+op2;
		case '-' : return op1-op2;
		case '*' : return op1*op2;
		case '/' : return op1/op2;
		case '%' : return op1%op2;
		case '^' :
		case '$' : return pow(op1,op2);
		default : break;
	}
}

void display(int S[20],int top)
{
	printf("The result after evaluation of postfix expression is %d\n",S[top]);
}

void eval_post(char postfix[30])
{
	int S[20],top=-1,op1,op2;
	int i=0;
	while(postfix[i]!='\0')
	{
	
		if(isdigit(postfix[i]))
			push(S,&top,postfix[i]-'0');
		else
		{
			op2=pop(S,&top);
			op1=pop(S,&top);
			int res=evaluate(op1,postfix[i],op2);
			push(S,&top,res);
		}
		i++;
	}
	display(S,top);
}
			
int main()
{
	char postfix[30];
	printf("Enter the postfix expression for evaluation\n");
	scanf("%s",postfix);
	eval_post(postfix);
	return 0;
}


