#include<stdio.h>
#include<stdlib.h>

struct node
{
        struct node* llink;
        int info;
        struct node* rlink;
};
typedef struct node* NODE;

NODE getnode()
{
        NODE temp;
        temp=(NODE)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Memory is not available\n");
                exit(0);
        }
        return temp;
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

void preorder_itr(NODE root)
{
        NODE s[10],cur;
        int top=-1;
        if(root==NULL)
        return;
        cur=root;
      for(;;)
      {
            while(cur!=NULL)
            {
                    printf("%d\t",cur->info);
                    s[++top]=cur;
                    cur=cur->llink;
            }
            if(top!=-1)
            {
                    cur=s[top--];
                    cur=cur->rlink;
            }
            else
            return;
      }
}      

int main()
{
    NODE root = NULL;
    int choice, info;

    while (1)
    {
        printf("1.Insert\n2.Preorder traversal(Iterative)\n3.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element to be inserted:");
                scanf("%d", &info);
                root = insert_BST(root, info);
                break;
            case 2:
                printf("Preorder Traversal (Iterative):\n");
                preorder_itr(root);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
