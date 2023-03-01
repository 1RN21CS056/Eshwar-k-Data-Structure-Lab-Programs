//circlular queue using dinamic memory allocation(mallco fun only)
#include<stdio.h>
#include<stdlib.h>
int max=4;
 int * insert_cq(int *q,int *rear,int *front, int * count,int elem)
 {
     if(*count==max)
     {
        max=max*2;
        int *p,i,c=*count,j=0;
        p=(int *)malloc(sizeof(int)*max);
        for(i=*front; c!=0; i=(i+1)%(max/2),c--)
        {
            p[j]=q[i];
            j++;
        }
        (*front)=0;
        (*rear)=max/2-1;
        (*count)++;
        (*rear)=((*rear)+1)%max;
        p[*rear]=elem;
        free(q);
        return p;
     }
        (*rear)=((*rear)+1)%max;
        q[*rear]=elem;
        (*count)++;
        return q;
 }   


  void delete_cq(int*q,int *front,int *count)
  {
  	if(*count==0)
  	{
  		printf("No element in circular queue\n");
  		return;
  	}
  	 printf("The element %d is deleted from queue\n",q[*front]);
     (*front)=((*front)+1)%max;
     (*count)--;
  }
   void display_cq(int *q,int count,int front)
   {
   	
   	if(count==0)
   	{
   		printf("no elements in circular queue\n");
   		return;
   	}
   	printf("Displaying elements in circular queue\n");
   	for( int i=front; count>0; i=(i+1)%max, count--)
   	printf("%d\t",q[i]);
    printf("\n");
   }
    int main()
    {
    		int rear=max-1;
            int *q,count=0,front=0,elem,choice;
            q=(int*)malloc(sizeof(int)*max);
    		while(1)
    		{
    			printf("\nEnter\n 1-insert\n2-delete\n3-display\n 4-exit\n");
    			scanf("%d",&choice);
    			switch(choice)
    			{
    				case 1:
                           printf("Enter element to be inserted\n");
                           scanf("%d",&elem);
 	                       q=insert_cq(q,&rear,&front,&count,elem);
    				break;
    				
    				case 2: delete_cq(q,&front,&count);
    				break;
    				
    				case 3: display_cq(q,count,front);
    				break;
    				
    				case 4: exit(0);
    				default:printf("Invalid option\n");
    			}
    		}
    	     return 0;
    	   }  			
   	
   		
   		
   			 	 		
