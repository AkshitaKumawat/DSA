#include <stdio.h>
#include <stdlib.h>

typedef struct linknode
{
    int data;
    struct linknode *next;
} node;
node *head, *newnode, *temp;
int count = 0;

void input()
{
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter value : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
}

void create_list()
{
    input();
    if (head == NULL)
    {
        head = newnode;
        temp = head;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}

void display()
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

void insert_at_beginning()
{
    input();
    newnode->next = head;
    head = newnode;
}

void insert_at_end()
{
    input();
    newnode->next = NULL;
    temp = head;
    while(temp->next != NULL)
         temp = temp->next;
    temp->next = newnode;
}

void insert_in_between()
{
    int pos, i=1;
    printf("Enter the position after which you want to insert : ");
    scanf("%d",&pos);
    if(pos > count)
        printf("Invalid position\n");
    else
    {
        temp = head;
        while(i<pos)
        {
            temp = temp->next;
            i++;
        }
        input();
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void delete_at_beg()
{
    node *ptr;
    ptr = head;
    head = head->next;
    printf("%d is deleted",ptr->data);
    free(ptr);
}

void delete_at_end()
{
    node *prevnode;
    temp = head;
    while(temp->next != NULL)
    {
        prevnode = temp;
        temp = temp->next;
    }
    if(temp == head)
        head = NULL;
    else
        prevnode->next = NULL;
    free(temp);
}

void delete_at_pos()
{
    int pos, i=1;
    node *nextnode;
    printf("Enter the position at which you want to delete : ");
    scanf("%d",&pos);
    if(pos > count)
        printf("Invalid position\n");
    else
    {
        temp = head;
        while(i<(pos-1))
        {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
    }
}

int main()
{
    int n;
    printf("Enter\n 1 for create list     2 for display elements     3 insert at beginning of list    4 for insert at the end    5 for inserting in between    6 for delete from beginning    7 for delete at end    8 for delete at position    9 for exit");
    while (1)
    {
        printf("\nEnter Choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            create_list();      count++;        break;
        case 2:
            display();                  break;
        case 3:
            insert_at_beginning();      break;
        case 4:
            insert_at_end();            break;
        case 5:
            insert_in_between();        break;
        case 6:
            delete_at_beg();            break;
        case 7:
            delete_at_end();            break;
        case 8:
            delete_at_pos();            break;
        case 9:
            exit(0);                    break;
        default:
            printf("Nice Try\n");       break;
        }
    }
    return 0;
}
