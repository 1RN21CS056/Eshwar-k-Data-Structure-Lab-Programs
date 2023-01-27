//Program to add two polynomials

#include<stdio.h>

struct polynomial
{
	int cx,px;
};
typedef struct polynomial P;

void accept(P p[10],int n)
{
	int i,j;
	for(i=0;i<n;i++)
		scanf("%d%d",&p[i].cx,&p[i].px);
	printf("The entered polynomial is :\n");
	for(i=0;i<n;i++)
	{
		if(p[i].cx>0)
			printf("+ %dX^%d  ",p[i].cx,p[i].px);
		else
			printf("%dX^%d  ",p[i].cx,p[i].px);
	}
}

int add_poly(P p1[10],P p2[10],P res[20],int n1,int n2)
{
	int i,j,k=0;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(p1[i].px == p2[j].px)
			{
				res[k].cx=p1[i].cx+p2[j].cx;
				res[k].px=p1[i].px;
				p2[j].cx=-999;
				k++;
				break;
			}
		}
		if(j==n2)
		{
			res[k].cx=p1[i].cx;
			res[k].px=p1[i].px;
			k++;
		}
	}
	for(j=0;j<n2;j++)
	{
		if(p2[j].cx!=-999)
		{
			res[k].cx=p2[j].cx;
			res[k].px=p2[j].px;
			k++;
		}
	}
	return k;
}

void display_sum(P res[20],int n)
{
	int i;
	printf("\n\nThe sum of two polynomials is;\n");
	for(i=0;i<n;i++)
	{
		if(res[i].cx>0)
			printf("+%dX^%d  ",res[i].cx,res[i].px);
		else
			printf("%dX^%d  ",res[i].cx,res[i].px);
	}
}
				
int main()
{
	int n1,n2;
	printf("Enter the number of terms in first polynomial\n");
	scanf("%d",&n1);
	printf("Enter the number of terms in second polynomial\n");
	scanf("%d",&n2);
	P p1[10],p2[10],res[20];
	printf("Enter the coefficient and power of the terms of first polynomial one by one\nFormat :\ncx(term1) ex(term1)\ncx(term2) ex(term2)\n");
	accept(p1,n1);
	printf("\n\nEnter the coefficient and power of the terms of second polynomial one by one\nFormat :\ncx(term1) ex(term1)\ncx(term2) ex(term2)\n");
	accept(p2,n2);
	int n=add_poly(p1,p2,res,n1,n2);
	display_sum(res,n);
	return 0;
}
	
