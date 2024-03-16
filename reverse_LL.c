#include<stdio.h>
#include<stdlib.h>

typedef struct linknode
{
    int data;
    struct linknode *next;
}node;
node *head,*newnode,*temp;

void create_LL()
{
    newnode = (node *)malloc(sizeof(node));
    printf("Enter value\n");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}
 
node *prev,*curr,*ne; 
void reverse_LL()
{
    curr = head;
    prev = NULL;
    ne = NULL;
    while(curr != NULL)
    {
        ne = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ne;
    }
    
    temp = prev;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void display_LL()
{
    if (head == NULL)
        printf("Underflow\n");
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
  

int main()
{
    int n;
    printf("Enter 1 for create   2 for display   3 for reverse  4 for exit:\n");
    while(1)
    {
        scanf("%d",&n);
        switch(n)
        {
            case 1:    create_LL();             break;
            case 2:    display_LL();            break;
            case 3:    reverse_LL();            break;
            case 4:    exit(0);                 break;
            default:   printf("Try again\n");   break;
        }
    }
    return 0;
}
