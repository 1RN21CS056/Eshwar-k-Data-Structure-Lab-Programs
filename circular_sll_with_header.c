#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
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

void insert_front(NODE head,int elem)
{
    NODE temp;
    temp=getnode();
    temp->info=elem;
    temp->link=head->link;
    head->link=temp;
}

void display(NODE head)
{
    if(head->link==head)
    {
        printf("No elements in CLL with header\n");
        return;
    }
    printf("Displaying the elements of CLL with header\n");
    NODE cur=head->link;
    while (cur!=head)
    {
        printf("%d\t",cur->info);
        cur=cur->link;
    }
    printf("\n");
}

int main()
{
    int elem,ch;
    NODE head =getnode();
    head->link=head;
    while(1)
    {
        printf("Enter 1 to insert front\n2-Display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
                    printf("Enter the element to be inserted\n");
                    scanf("%d",&elem);
                    insert_front(head,elem);
                    break;
            case 2 :
                    display(head);
                    break;
            default :
                    printf("Invalid choice\n");
                    exit(0);
        }
    }
    return 0;
}