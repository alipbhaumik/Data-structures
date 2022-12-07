
#include <stdio.h>
#include <stdlib.h>
struct node {  /* Basic structure of Node */
int data;
struct node * next;
}*head;
void createList(int n)
{
    int i, data;
    struct node *newNode,*temp;
    if(n >= 1)
    {             /* Creates and links the head node */    
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of 1 node: ");
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        head=newNode;
        temp=newNode;
        for(i=2; i<=n; i++){    /* Creates and links rest of the n-1 nodes */
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data of %d node: ", i);
            scanf("%d", &data);
            newNode->data = data; //Links new node with the previous node
            newNode->next = NULL;
            temp->next = newNode; //Links previous node with the new node
            temp=temp->next; //Temp becomes newnode
        }
        printf("\nLINKED LIST CREATED SUCCESSFULLY\n");
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
void deleteMiddleNode(int position);
int main()
{
    int n;
    head = NULL;
    printf("\nEnter the total number of nodes in list: \n");
    scanf("%d", &n);
    createList(n);  // function to create double linked list
    displayList(); // function to display the list
    printf("\nEnter the node to be deleted:\n ");
    scanf("%d",&n);
    deleteMiddleNode(n);
    displayList();
    return 0;
    
}
void deleteMiddleNode(int position)
{
    int i;
    struct node *toDelete,*prevNode;
    if(head==NULL)
    {
        printf("\nList is already empty\n");
    }
    else
    {
        toDelete=head;
        prevNode=head;
        for(i=2;i<=position;i++)
        {
            prevNode=toDelete;//stores n-1th node
            toDelete=toDelete->next;//toDelete is the "i"th node so atlast it will be the nth node 
        
        if(toDelete==NULL)
        break;
        }
    }
    if(toDelete!=NULL)
    {
        if(toDelete==head)//deleting 1st node
        head=head->next;
        //else
        prevNode->next=toDelete->next;//points to n+1th node
        toDelete->next=NULL;//node to be deleted is made to be pointed to null
        free(toDelete);
        printf("\nSuccessfully deleted %d Node from the linked list\n",position);
    }
    else
    {
        printf("\nInvalid position unable to delete\n");
    }
}
