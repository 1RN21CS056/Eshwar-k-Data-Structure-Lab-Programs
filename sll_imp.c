#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node* NODE;
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
NODE insert_f(NODE first,int elem)
{
    NODE temp;
    temp = getnode();
    temp->info=elem;
    temp->link=first;
    return temp;
}
NODE insert_r(NODE first,int elem)
{
    NODE temp,curr,pre;
    curr = first;
    pre = NULL;
    temp = getnode();
    temp->info=elem;
    temp->link=NULL;
    if(first == NULL)
        return temp; 
    else
    {
        while(curr!=NULL)
        {
            pre = curr;
            curr=curr->link;
        }
        pre->link = temp;
        return first;
    }
}
NODE delete_f(NODE first)
{
    NODE next;
    if(first == NULL)
    {
        printf("No elements to delete\n");
        return NULL;
    }
    else
    {
        printf("%d\n is the deleted element\n",first->info);
        next = first->link;
        free(first);
        return next;
    }
}
NODE delete_r(NODE first)
{
    NODE curr,next,pre;
    curr = first;
    pre = NULL;
    if(first == NULL)
    {
        printf("No elements to delete\n");
        return NULL;
    }
    else if(first->link == NULL)
    {
        printf("%d\n is the deleted element\n",first->info);
        free(first);
        return NULL;
    }
    else
    {
        while(curr->link!=NULL)
        {
            pre=curr;
            curr=curr->link;
        }
        printf("%d\n is the deleted element\n",curr->info);
        pre->link=NULL;
        free(curr);
        return first;
    }
}
int count_sll(NODE first)
{
    int count=0;
    while(first!=NULL)
    {
        count++;
        first = first->link;
    }
    return count;
}
void display(NODE first)
{
    if(first == NULL)
    printf("Nothing to display\n");
    else
    {
        for(;first!=NULL;first = first->link)
        printf("%d\t",first->info);
        printf("\n");
    }
}
int main()
{
    int elem,ch;
    NODE first;
    first = NULL;
    while(1)
    {
        ch=0;
        printf("enter an option\n");
        printf("1: insert front\n2: insert rear\n3: delete front\n4: delete rear\n5: display\n6: count number of nodes\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter an element\n");
            scanf("%d",&elem);
            first=insert_f(first,elem);
            break;
            case 2:
            printf("Enter an element\n");
            scanf("%d",&elem);
            first=insert_r(first,elem);
            break;
            case 3:
            first=delete_f(first);
            break;
            case 4:
            first=delete_r(first);
            break;
            case 5: 
            display(first);
            break;
            case 6:
            printf("There are %d number of nodes\n",count_sll(first));
            break;
            default:
            return 0;
        }
    }
    return 0;
}