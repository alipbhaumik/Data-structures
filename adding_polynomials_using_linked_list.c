
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int coeff;
	int e;
	struct node *next;
}*header,*poly1,*poly2,*poly;
int lenpoly1,lenpoly2;
void createList(int n);
//void addpolynomial();
int main()
{
	int n;
	printf("\nEnter no of nodes\n");
	scanf("%d",&n);
	lenpoly1=n;
	createList(n);
	poly1=header;
	display(poly1);
	printf("\nEnter no of nodes\n");
	scanf("%d",&n);
	lenpoly2=n;
	createList(n);
	poly2=header;
	display(poly2);
	
	return 0;
}
//creating the linked list
void createList(int n)
{
	struct node *newNode,*temp;
	int coeff,e,i;
	newNode=(struct node*)malloc(sizeof(struct node));
	if(newNode==NULL)
	{
		printf("\nUnable to allocate memory\n");
	}
	else
	{
		printf("\nEnter coefficient and exponent for Node 1:\n");
		scanf("%d %d",&coeff,&e);
		newNode->coeff=coeff;
		newNode->e=e;
		newNode->next=NULL;
		header=newNode;
		temp=newNode;
		for(i=2;i<=n;i++)
		{
			newNode=(struct node*)malloc(sizeof(struct node));
			if(newNode==NULL)
			{
				printf("Unable to allocate memory");
				break;
			}
			else
			{
			printf("\nEnter coefficient and exponent for Node %d:\n",i);
			scanf("%d %d",&coeff,&e);
			newNode->coeff=coeff;
			newNode->e=e;
			newNode->next=NULL;
			temp->next=newNode;
			temp=temp->next;
			}
		}
	}
	if(newNode==NULL)
	printf("Coudnt Create Linked List");
	else
	printf("\nPolynomial successfully created\n");
	return header;
}
//Display the polynomial
void display(struct node *poly)
{
 struct node *temp;
 int i=1;
 temp=poly;
 while(temp!=NULL)
 {
 	if(i==1)
 	{
 	printf("%dx^%d",temp->coeff,temp->e);
 	temp=temp->next;
 	i++;
 	}
 	else
 	{
 	printf("+%dx^%d",temp->coeff,temp->e);
 	temp=temp->next;
 	}
 }
 }
 void addpolynomial()
 {
 struct node *poly,temp*;
 int i;
 if(lenpoly1<lenpoly2)
 {
 for(i=1;i<=lenpoly1;i++)
 {
 	struct node *newNode=(struct node*)malloc(sizeof(struct node));
 	if(poly1->e>poly2->e)//exponent of poly 1 is greater than poly 2
 	{
 		newNode->coeff=poly1->coeff;
 		newNode->e=poly1->e;
 		newNode->next=NULL;
 		if(i==1)//first iteration
 		{
 		poly=newNode//setting the header
 		temp=poly;
 		}
 		temp->next=newNode;
 		temp=newNode;
 	}
 	else if(poly1->e<poly2->e)//exponent of poly 2 is greater than poly 1
 	{
		newNode->coeff=poly2->coeff;
 		newNode->e=poly2->e;
 		newNode->next=NULL;
 		if(i==1)//first iteration
 		{
 		poly=newNode//setting the header
 		temp=poly;
 		}
 		temp->next=newNode;
 		temp=newNode;
 	
 	}
 	else if(poly1->e==poly2->e)//both exponents are equal
 
