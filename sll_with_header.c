//Program to implement SLL with header

#include<stdio.h>
#include<stdlib.h>

//Declaration of structure
struct node
{
    int info;
    struct node * link;
};

typedef struct node * NODE;

//Function to allocate memory
NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    if(temp==NULL)  //Memory not available
    {
        printf("Memory is not available\n");
        exit(0);
    }
    return temp;    //Memory is available
}

//Function to insert the element at the front of SLL with header
void insert_front(NODE head,int elem)
{
    NODE temp=getnode(); //Allocating the memory
    temp->info=elem;    //Inserting the element
    temp->link=NULL;
    if(head->link==NULL)//Sll with header is empty
    {
        head->link=temp;
        return;
    }
    temp->link=head->link; //Elemnets are present
    head->link=temp;
}

//Function to insert the elements at the rear of SLL with header
void insert_rear(NODE head,int elem)
{
    NODE temp=getnode();    //Allocating the memory
    temp->info=elem;    //Inserting the element
    temp->link=NULL;
    NODE cur=head->link;
    if(head->link==NULL)    //SLL with header is empty
    {
        head->link=temp;
        return;
    }
    while(cur->link!=NULL)  //Getting the last node
        cur=cur->link;
    cur->link=temp; //Linking the new node to the last node
    return;
}

void delete_front(NODE head)
{
    NODE first,sec;
    //check empty
    if(head->link==NULL)
    {
        printf("Empty\n");
        return;
    }
    first=head->link;
    sec=first->link;
    head->link=sec;
    printf("Deleted element is %d\n",first->info);
    free(first);
}

void delete_rear(NODE head)
{
    NODE cur,prev;
    //check empty
    if(head->link==NULL)
    {
        printf("Empty\n");
        return;
    }
    cur=head->link;
    prev=head;
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    printf("Deleted element is %d\n", cur->info);
    prev->link=NULL;
    free(cur);
}
//Function to display the elements of SLL with header
void display(NODE head)
{

    if(head->link==NULL)
    {
        printf("SLL with header is empty\n");
        return;
    }
    printf("Displaying the elements of SLL with header\n");
    NODE cur=head->link;
    while(cur!=NULL)
    {
        printf("%d\t",cur->info);
        cur=cur->link;
    }
    printf("\n");
    return;
}
int main()
{
    NODE head;
    int choice,elem;
    head=getnode(); //Allocating the memory for header node
    head->link=NULL; //Initializing the link field to NULL
    while(1)
    {
        printf("Enter your choice\n1.Insert at front\n2.Insert at rear\n3.Delete from front\n4.Delete from rear\n5.Display\n6.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element to be inserted\n");
                    scanf("%d",&elem);
                    insert_front(head,elem); //Calling insert_front function
                    break;
            case 2: printf("Enter the element to be inserted\n");
                    scanf("%d",&elem);
                    insert_rear(head,elem); //Calling insert_rear function
                    break;
            case 3: delete_front(head); //Calling delete_front function
                    break;
            case 4: delete_rear(head); //Calling delete_rear function
                    break;
            case 5: display(head); //Calling display function
                    break;
            case 6: exit(0); //Exiting the program
            default: printf("Invalid choice\n"); //For invalid choices
        }
    }
    return 0;
}
