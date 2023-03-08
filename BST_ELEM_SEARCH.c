#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *llink;
    int info;
    struct node *rlink;
};
typedef struct node* NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory not Allocated\n");
        exit(0);
    }
    return x;
}
NODE insert_BST(NODE root,int info)
{
        NODE temp,prev,cur;
        temp=getnode();
        temp->llink=temp->rlink=NULL;
        temp->info=info;
        if(root==NULL)
        {
                return temp;
        }
        cur=root;
        while(cur!=NULL)
        {
                prev=cur;
                if(cur->info>info)
                  cur=cur->llink;
                else 
                   cur=cur->rlink;
        }          
                if(prev->info>info)
                    prev->llink=temp;
                 else  
                    prev->rlink=temp;
                 return root;           

}
void search(NODE root,int elem)
{
    NODE curr;
    curr=root;
    if(curr==NULL)
    {
        printf("Empty tree\n");
        return;
    }
    while(curr!=NULL)
    {
        if(curr->info==elem)
        {
            printf("Element found\n");
            return;
        }
        if(elem>curr->info)
        {
            curr=curr->rlink;
        }
        else
        {
            curr=curr->llink;
        }
    }
    printf("Element not found\n");
}
int main()
{
    NODE root=NULL;
    int choice,elem, info;

    while(1)
    {
        printf("\n1.Insert\n2.Search\n3.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted:");
                scanf("%d",&info);
                root=insert_BST(root,info);
                break;
            case 2:
                printf("Enter the element to be searched:");
                scanf("%d",&elem);
                search(root,elem);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
