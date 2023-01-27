//Program to simulate simple calculator using nested if statements

#include<stdio.h>

void calci(int op,int num1,int num2)
{
	int res;
	if(op==1)
		res= num1+num2;
	else if(op==2)
		res=num1-num2;
	else if(op==3)
		res=num1*num2;
	else if(op==4)
	{
		if(num2!=0)
			res=num1/num2;
		else{
			printf("Divide by 0 error\n");
			return;
		}
	}
	else if(op==5)
		res=num1%num2;
	else{
		printf("Invalid input\n");
		return;
	}
	printf("The result is %d\n",res);
}

int main()
{
	int op,num1,num2;
	printf("1-Add\t2-Sub\t3-Mult\t4-Div\t5-Mod\nEnter your choice\n");
	scanf("%d",&op);
	printf("Enter two numbers to perform the operation\n");
	scanf("%d%d",&num1,&num2);
	calci(op,num1,num2);
	return 0;
}
