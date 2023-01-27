//Program to evaluate the polynomial

#include<stdio.h>
#include<math.h>

typedef struct Polynomial
{
	int cx,px;
} P;

void accept(P a[10], int terms)
{
	int i;
	printf("Enter the coefficients and power of the terms\n");
	for(i=0;i<terms;i++)
		scanf("%d%d",&a[i].cx,&a[i].px);
	printf("The entered polynomial is\n");
	for(i=0;i<terms;i++)
	{
		if(a[i].cx>0)
			printf("+ %dX^%d  ",a[i].cx,a[i].px);
		else
			printf("%dX^%d  ",a[i].cx,a[i].px);
	}
}

void evaluate_poly(P a[10],int terms)
{
	int x,sum=0,i;
	printf("\nEnter the value of x\n");
	scanf("%d",&x);
	for(i=0;i<terms;i++)
		sum = sum + (a[i].cx*pow(x,a[i].px));
	printf("The value of the polynomial is %d\n",sum);
}

int main()
{
	int terms;
	P a[10];
	printf("Enter the number of terms in the polynomial\n");
	scanf("%d",&terms);
	accept(a,terms);
	evaluate_poly(a,terms);
	return 0;
}
