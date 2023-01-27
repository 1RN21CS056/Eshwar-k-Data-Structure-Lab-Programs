//Program to find the string length without using built in function

#include<stdio.h>

//Function to find the length of the string
void str_len(char str[20],int *len) 
{
	int i;
	for(i=0;str[i]!='\0';i++)
		(*len)++; //finding the length
}

int main()
{
	char str[20];
	int len=0;
	printf("Enter the string to find its length:\n"); //Accepting the string
	scanf("%[^\n]",str);
	str_len(str,&len); //passing the string and address of len to the function
	printf("The length of the string is %d\n",len); //Printing the result
	return 0;
}
	

