//Program to swap two numbers without using temporary variable

#include<stdio.h>

void swap(int *num1,int *num2)
{
	*num1=*num1+*num2;
	*num2=*num1-*num2;
	*num1=*num1-*num2;
}

int main()
{
	int num1,num2;
	printf("Enter two numbers to swap two numbers:\n");
	scanf("%d%d",&num1,&num2);
	printf("The numbers before swapping is \nNum1=%d\tNum2=%d\n",num1,num2);
	swap(&num1,&num2);
	printf("The numbers after swapping is \nNum1=%d\tNum2=%d\n",num1,num2);
	return 0;
}
