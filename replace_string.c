//Program to search and replace substring in main string

#include<stdio.h>
#include<string.h>

int pattern_match(char ps[30],char ms[30],int startpos)
{
	int i,n;
	n=strlen(ps);
	for(i=0;i<n;i++)
	{
		if(ps[i]!=ms[startpos])
			break;
		startpos++;
	}
	if(i==n)
		return 0;
	else
		return 1;
}

int out_string(char ostring[30],char rs[30],int opos)
{
	int i;
	for(i=0;rs[i]!='\0';i++)
	{
		ostring[opos]=rs[i];
		opos++;
	}
	return opos;
}

int main()
{
	char ms[30],rs[30],ps[30],ostring[30];
	int i,opos=0;
	
	printf("Enter the main string\n");
	scanf("%s",ms);
	printf("Enter the pattern string\n");
	scanf("%s",ps);
	printf("Enter the replace string\n");
	scanf("%s",rs);
	for(i=0;ms[i]!='\0';)
	{
		if((pattern_match(ps,ms,i))==0)
		{
			opos=out_string(ostring,rs,opos);	
			i=i+strlen(ps);
		}
		else
		{
			ostring[opos]=ms[i];
			opos++;
			i++;
		}
	}
	ostring[opos]='\0';
	printf("The final string is %s\n",ostring);
	return 0;
}


