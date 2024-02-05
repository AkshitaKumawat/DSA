#include<stdio.h>
#include<stdlib.h>
#include<process.h>

typedef struct queuenode
{
    int data;
    struct queuenode *next;
}node;

node *front=NULL , *rear=NULL , *newnode , *temp;

void enqueue()
{
    newnode = (node*)malloc(sizeof(node));
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    if(front == NULL && rear == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void display()
{
    if(front == NULL && rear == NULL)
        printf("Underflow\n");
    else
    {
        temp = front;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void dequeue()
{
    if(front == NULL && rear == NULL)
        printf("Underflow\n");
    else
    {
        temp = front;
        printf("%d is deleted\n",front->data);
        front = temp->next;
        free(temp);
    }
}

int main()
{
    int n;

    printf("1 for enqueue   2 for dequeue   3 for display   4 for exit\n");
    while (1)
    {
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Nice Try\n");
            break;
        }
    }
    return 0;
}