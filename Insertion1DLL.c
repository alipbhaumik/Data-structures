//insertion at any point in double linked list
#include <stdio.h>
#include <stdlib.h>
struct node {  /* Basic structure of Node */
int data;
struct node * prev;
struct node * next;
}*head,*last;
int lastnode;
void createList(int n);
void insert_position(int data, int position);
void displayList();
int main()
{
    int n, data;
    head = NULL;
    last = NULL;
    printf("Enter the total number of nodes in list: ");
    scanf("%d", &n);
    createList(n);  // function to create double linked list
    displayList(); // function to display the list
    lastnode=n;
    printf("Enter the position and data to insert new node: ");
    scanf("%d %d", &n, &data);                
    insert_position(data, n);// function to insert node at any position
    displayList();
    return 0;
}
void createList(int n)
{
    int i, data;
    struct node *newNode;
    if(n >= 1){             /* Creates and links the head node */    
        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of 1 node: ");
        scanf("%d", &data);
        head->data = data;
        head->prev = NULL;
        head->next = NULL;
        last = head;
        for(i=2; i<=n; i++){    /* Creates and links rest of the n-1 nodes */
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data of %d node: ", i);
            scanf("%d", &data);
            newNode->data = data;
            newNode->prev = last; //Links new node with the previous node
            newNode->next = NULL;
            last->next = newNode; //Links previous node with the new node
            last = newNode; //Makes new node as last/previous node
        }
        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
void insert_position(int data, int position)
{
    struct node * newNode, *temp;
    if(head == NULL)
    {
       printf("Error, List is empty!\n");
    }
    else{
        int i;
        temp = head;
        if(position>1 && position<lastnode)
        {
            for(i=2;i<=position-1;i++)
            {
                temp=temp->next;//if i=2 temp will point to head->next which is the 2nd node
                //if i=3 it will point to the 3rd node
                //temp will still represent the 2nd node
            }
                newNode = (struct node *)malloc(sizeof(struct node));
                newNode->data = data;
                newNode->next = temp->next; //Connects new node with n+1th node
                newNode->prev = temp;       //Connects new node with n-1th node
                temp->next = newNode;       /* Connects n-1th node with new node */

            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", position);

        }
        else{

            printf("Error, Invalid position\n");

        }

    }

}
void displayList()
{
    struct node * temp;
    int n = 1;
    if(head == NULL)
    {
       printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");
        while(temp != NULL)
        {
        printf("DATA of %d node = %d\n", n, temp->data);

           n++;
           /* Moves the current pointer to next node */
           temp = temp->next;
        }
    }
}
