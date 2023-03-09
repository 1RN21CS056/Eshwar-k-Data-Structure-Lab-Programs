#include<stdio.h>
#include<stdlib.h>
struct poly 
{
    int px,py,pz,cf;
    struct poly *link;
};
typedef struct poly *P;
P getnode()
{
    P temp;
    temp=(P)malloc(sizeof(struct poly));
    if(temp==NULL)
    {
        printf("Memory not available\n");
        exit(0);
    }
    return temp;
}
void insert(P p,int cf,int px, int py,int pz)
{
    P temp;
    temp=getnode();
    temp->cf=cf;
    temp->px=px;
    temp->py=py;
    temp->pz=pz;
    temp->link=p->link;
    p->link=temp;
}
void display(P p)
{
    if(p==p->link)
    printf("No terms in polynomial\n");
    else
    {
        P curr;
        curr=p->link;
        printf("The polynomial is :\n");
        while(curr!=p)
        {
            if(curr->cf >= 0)
            printf("+%d x^%d y^%d z^%d ",curr->cf,curr->px,curr->py,curr->pz);
            else
            printf("%d x^%d y^%d z^%d ",curr->cf,curr->px,curr->py,curr->pz);
            curr=curr->link;
        }
        printf("\n");
    }
}
void accept(P p)
{
    int px,py,pz,cf,terms;
    printf("Enter number of terms should be there in this polynomial\n");
    scanf("%d",&terms);
    while(terms--)
    {
        printf("Enter co-efficient of the term\n");
        scanf("%d",&cf);
        printf("Enter exponent of x,y,z respectively\n");
        scanf("%d%d%d",&px,&py,&pz);
        insert(p,cf,px,py,pz);
    }
}
void poly_add(P p1, P p2, P p3)
{
    int flag;
    P curr1,curr2;
    curr1=p1->link;
    while(curr1 != p1)
    {
        curr2=p2->link;
        flag=0;
        while(curr2 != p2)
        {
            if(curr1->px==curr2->px && curr1->py==curr2->py && curr1->pz==curr2->pz)
            {
                insert(p3,curr1->cf+curr2->cf,curr1->px,curr1->py,curr1->pz);
                curr2->cf=-999;
                flag=1;
                break;
            }
            curr2=curr2->link;
        }
        if(flag==0)
            insert(p3,curr1->cf,curr1->px,curr1->py,curr1->pz);
        curr1=curr1->link;
    }
    curr2=p2->link;
    while(curr2!=p2)
    {
        if(curr2->cf!=-999)
            insert(p3,curr2->cf,curr2->px,curr2->py,curr2->pz);
        curr2=curr2->link;
    }
}
int main()
{
    P p1,p2,p3;
    p1=getnode();
    p1->link=p1;
    p2=getnode();
    p2->link=p2;
    p3=getnode();
    p3->link=p3;
    accept(p1);
    accept(p2);
    display(p1);
    display(p2);
    poly_add(p1,p2,p3);
    printf("The addition of two polynomial is :\n");
    display(p3);
    return 0;
}