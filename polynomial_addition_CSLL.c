#include<stdio.h>
#include<stdlib.h>
struct node
{
	int cf,px,py,pz;
	struct node* link;
};
typedef struct node* NODE;
NODE getnode()
{
	NODE x;
	x= (NODE)malloc(sizeof(struct node));
	if(x== NULL)
	{
		printf("Memory not available\n");
		exit(0);
	}
	return x;
}
void insert_front(NODE head,int cf,int px,int py,int pz)
{
	NODE temp;
	temp=getnode();
	temp->cf=cf;
	temp->px=px;
	temp->py=py;
	temp->pz=pz;
	temp->link=head->link;
	head->link=temp;
}
void accept(NODE head)
{
	int cf,px,py,pz;
	printf("Enter the term to be inserted in polynomial\n");
	printf("It's co-efficient\n");
	scanf("%d",&cf);
	printf("It's power to x,y,z\n");
	scanf("%d%d%d",&px,&py,&pz);
	insert_front(head,cf,px,py,pz);
}
void display(NODE head)
{
	NODE curr=head->link;
	if(curr==head)
	{
		printf("empty polynomial \n");
		return;
	}
	printf("The polynomial is:\n");
	while(curr!=head)
	{
		if(curr->cf>=0)
		printf("+%d x^%dy^%dz^%d\t",curr->cf,curr->px,curr->py,curr->pz);
		else
		printf("%d x^%dy^%dz^%d\t",curr->cf,curr->px,curr->py,curr->pz);
		curr=curr->link;
	}
	printf("\n");
}
NODE compare(NODE term,NODE p2)
{
	NODE curr=p2->link;
	while(curr!=p2)
	{
		if(curr->px == term->px && curr->py == term->py && curr->pz == term->pz)
		return curr;
		curr=curr->link;
	}
	return NULL;
}
void polynomial_add(NODE p1,NODE p2,NODE p3)
{
	NODE term=p1->link,curr;
	while(term!=p1)
	{
		curr=compare(term,p2);
		if(curr!=NULL)
		insert_front(p3,term->cf+curr->cf,term->px,term->py,term->pz);
		else
		insert_front(p3,term->cf,term->px,term->py,term->pz);
		term=term->link;
	}
	term=p2->link;
	while(term!=p2)
	{
		curr=compare(term,p1);
		if(curr==NULL)
		insert_front(p3,term->cf,term->px,term->py,term->pz);
		term=term->link;
	}
}
int main()
{
	NODE p1,p2,p3;
	p1=getnode();
	p1->link=p1;
	p2=getnode();
	p2->link=p2;
	p3=getnode();
	p3->link=p3;
	int terms;
	printf("Enter the number of terms in first polynomial\n");
	scanf("%d",&terms);
	for(int i=0; i<terms; i++)
	accept(p1);
	printf("Enter the number of terms in second polynomial\n");
	scanf("%d",&terms);
	for(int i=0; i<terms; i++)
	accept(p2);
	display(p1);
	display(p2);
	polynomial_add(p1,p2,p3);
	printf("The ressultant after adding two polynomials\n");
	display(p3);
	return 0;
}