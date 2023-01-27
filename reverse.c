//Prgram to reverse a number

#include<stdio.h>

void reverse_num(int *num,int *rev)
{
	int rem;
	while(*num!=0)
	{
		rem=(*num)%10;
		*rev=((*rev)*10)+rem;
		*num=(*num)/10;
	}
}

int main()
{
	int num,rev=0;
	printf("Enter a number to reverse it\n");
	scanf("%d",&num);
	reverse_num(&num,&rev);
	printf("The number after reversing is %d\n",rev);
	return 0;
}
