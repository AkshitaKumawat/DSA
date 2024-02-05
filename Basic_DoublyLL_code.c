#include <stdio.h>
#include <process.h>
#include<stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;
node *head, *tail, *temp;

void create_doublyLL()
{
    temp = (node *)malloc(sizeof(node));
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void display_forward()
{
    if (head == NULL)
        printf("Underflow");
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf(" %d \n", temp->data);
            temp = temp->next;
        }
    }
}

void display_reverse()
{
    if (tail == NULL)
        printf("Underflow");
    else
    {
        temp = tail;
        while (temp != NULL)
        {
            printf(" %d \n", temp->data);
            temp = temp->prev;
        }
    }
}

int main()
{
    int n;
    printf("Press 1 for createLL    2 for display reverse   3 for display forward   4 for exit\n");
    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            create_doublyLL();
            break;
        case 2:
            display_reverse();
            break;
        case 3:
            display_forward();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Nice Try\n");
            break;
        }
    }
}