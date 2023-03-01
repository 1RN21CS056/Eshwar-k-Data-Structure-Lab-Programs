//circular Q dinamic(realloc only)
#include<stdio.h>
#include<stdlib.h>
int max=3;
int *insert(int *q,int *rear,int *front,int *count,int elem)
{
    if(*count == max)
    {
        int i,j;
        max = max*2;
        q=(int *)realloc(q,sizeof(int)*max);
        if(*front != 0)
        {
            for(i=(max/2)-1,j=max-1; i>=(*front); i--,j--)
            q[j]=q[i];
            (*front)=j+1;
        }
        (*rear)=((*rear)+1)%max;
        q[*rear]=elem;
        (*count)++;
        return q;
    }
    (*rear)=((*rear)+1)%max;
    q[*rear]=elem;
    (*count)++;
    return q;
}
void delete(int *q,int *front,int *count)
{
    if(*count == 0)
    {
        printf("nothing to return \n");
        return;
    }
    printf("the deleted element is %d\n",q[*front]);
    (*front)=((*front)+1)%max;
    (*count)--;
}
void display(int *q,int front,int count)
{
    if(count == 0)
    {
        printf("nothing to display\n");
        return;
    }
    printf("displaying elements in queue\n");
    for( ;count>0;front=(front+1)%max,count--)
    printf("%d\t",q[front]);
    printf("\n");
}
int main()
{
    int *q,rear=-1,front=0,count=0,elem,op;
    q=(int*)malloc(sizeof(int)*max);
    while(1)
    {
        op=0;
        printf("enter an option\n");
        printf("1:insert\n2:delete\n3:display\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            printf("enter an element to be inserted\n");
            scanf("%d",&elem);
            q=insert(q,&rear,&front,&count,elem);
            break;
            case 2:
            delete(q,&front,&count);
            break;
            case 3:
            display(q,front,count);
            break;
            default :
            return 0;
        }
    }
    return 0;
}