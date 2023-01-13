#include<stdio.h>
void tower_of_hanoi(int n,char s,char t,char d)
{
   if(n==0)
   {
     return;
   }
     tower_of_hanoi(n-1,s,d,t);
     printf("Move disc %d from %c to %c\n",n,s,d);
     tower_of_hanoi(n-1,t,s,d);
  
}
int main()
{
  int n;
  //char s,t,d;
  printf("Enter the number of disc\n");
  scanf("%d",&n);
 printf("Assumption:\n");
 printf("sorce rod:'A'\n temporary rod:'B'\n destination rod:'c'\n");
 tower_of_hanoi(n,'A','B','C');
 return 0;
}