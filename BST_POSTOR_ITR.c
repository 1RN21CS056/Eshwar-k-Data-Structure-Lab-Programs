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

void postorder_itr(NODE root)
{
        struct stack
        {
                NODE address;
                int flag;
        };
        NODE cur;
        struct stack s[10];
        int top=-1;
        if(root==NULL)
          return;
        cur=root;
        for(;;)
        {
                while(cur!=NULL)
                {
                        ++top;
                        s[top].address=cur;
                        s[top].flag=1;
                        cur=cur->llink;
                }
                while(s[top].flag<0)
                {
                        cur=s[top].address;
                        top--;
                        printf("%d\n",cur->info);
                        if(top==-1)
                        return;   
                }
                 cur=s[top].address;
                 cur=cur->rlink;
                 s[top].flag=-1;
        }  
}

int main()
{
    NODE root = NULL;
    int choice, info;

    while (1)
    {
        printf("1.Insert\n2.postorder traversal(Iterative)\n3.Exit\n");
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
                printf("postorder Traversal (Iterative):\n");
                postorder_itr(root);
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

