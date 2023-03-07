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

void preorder(NODE root)
{
	if(root==NULL)
	return;
	printf("%d\t",root->info);
	preorder(root->llink);
	preorder(root->rlink);
}

void inorder(NODE root)
{
	if(root==NULL)
	return;
	inorder(root->llink);
	printf("%d\t",root->info);
	inorder(root->rlink);
}

void postorder(NODE root)
{
	if(root==NULL)
	return;
	postorder(root->llink);
	postorder(root->rlink);
	printf("%d\t",root->info);
}

int main()
{
	NODE root;
	root=NULL;
	int choice,info;
	while(1)
	{
		printf("Enter an option\n");
		printf("1: Insert to bst\n2: preorder\n3: inorder\n4: postorder\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter an element\n");
			scanf("%d",&info);
			root=insert_BST(root,info);
			break;
			case 2:
			printf("The BST in preorder traversal\n\n");
			preorder(root);
			break;
			case 3:
			printf("The BST in inorder traversal\n\n");
			inorder(root);
			break;
			case 4:
			printf("The BST in postorder traversal\n\n");
			postorder(root);
			break;
			default:
			printf("Invalid option\n");
			exit(0);
		}
	}
}