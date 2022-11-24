#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
void printlist(struct Node *n)
{
	while(n!= NULL)
	{
		printf("%d \n",n->data);
		n=n->next;
	}
}
int main()
{
	struct Node* head;
	struct Node* one=NULL;
	struct Node* two=NULL;
	head=(struct Node*)malloc(sizeof(struct Node));
	one=(struct Node*)malloc(sizeof(struct Node));
	two=(struct Node*)malloc(sizeof(struct Node));
	one->data=6;
	one->next=third;
	two->data=7;
	two->next=NULL;
	head=one;
	printlist(head);
}
