//Program to implement circular linked list 

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node * link;
};

typedef struct node * NODE;

NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory is not available\n");
        exit(0);
    }
    return x;
}

NODE insert_front(NODE last,int elem)
{
    NODE temp;
    temp=getnode();
    temp->info=elem;
    temp->link=NULL;
    if(last==NULL)
    {
        last=temp;
        last->link=temp;
        return last;
    }
    temp->link=last;
    last->link=temp;
    return last;
}

NODE insert_rear(NODE last,int elem)
{
    NODE temp;
    temp=getnode();
    temp->info=elem;
    temp->link=NULL;
    if(last==NULL)
        last=temp;
    else
        temp->link=last->link;
    last->link=temp;
    return temp;
}

NODE delete_front(NODE last)
{
    NODE first;
    if(last==NULL)
    {
        printf("CLL is empty\n");
        return NULL;
    }
    if(last->link==last)
    {
        printf("Deleted element is %d\n",last->info);
        free(last);
        return NULL;
    }
    first=last->link;
    printf("Deleted element is %d\n",first->info);
    last->link=first->link;
    free(first);
    return last;
}

NODE delete_rear(NODE last)
{
    NODE prev=NULL;
    if(last==NULL)
    {
        printf("CLL is empty\n");
        return NULL;
    }
    if(last->link==last)
    {
        printf("Deleted element is %d\n",last->info);
        free(last);
        return NULL;
    }
    prev=last->link;
    while(prev->link!=last)
        prev=prev->link;
    prev->link=last->link;
    printf("Deleted element is %d\n",last->info);
    free(last);
    return prev;
}

void display(NODE last)
{
    if(last==NULL)
    {
        printf("CLL is empty\n");
        return;
    }
    NODE first=last->link;
    printf("Displaying the elements of CLL\n");
    while(first!=last)
    {
        printf("%d\t",first->info);
        first=first->link;
    }
    printf("%d\t",first->info);
    printf("\n");
    return;
}

int main()
{
    NODE last=NULL;
    int ch,elem;
    while(1)
    {
        printf("Enter 1 to insert front\n2-insert rear\n3-delete front\n4-delete rear\n5-display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("Enter the element to be inserted\n");
                    scanf("%d",&elem);
                    last=insert_front(last,elem);
                    break;
            case 2:
                    printf("Enter the element to be inserted\n");
                    scanf("%d",&elem);
                    last=insert_rear(last,elem);
                    break;
            case 3:
                    last=delete_front(last);
                    break;
            case 4:
                    last=delete_rear(last);
                    break;
            case 5:
                    display(last);
                    break;
            default:
                    printf("Invalid choice\n");
                    exit(0);
        }
    }
    return 0;
}