#include<stdio.h>
#include<process.h>
#include<stdlib.h>

typedef struct stacknode
{
    int data;
    struct stacknode *prev;     //as we are not pointing towards next node , but we are pointing towards the previous node
}node;

node *top = NULL , *newnode , *temp;

void push()
{
    newnode = (node*)malloc(sizeof(node));
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    newnode->prev = top;
    top = newnode;
}

void display()
{
    if(top == NULL)
        printf("Underflow\n");
    else
    {
        temp = top;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->prev;
        }
        printf("\n");
    }
}

void peek()
{
    if(top == NULL)
        printf("Underflow\n");
    else
        printf("%d\n",top->data);
}

void pop()
{
    if(top == NULL)
        printf("Underflow\n");
    else
    {
        temp = top;
        printf("%d deleted\n",top->data);
        top = temp->prev;
        free(temp);
    }
}

int main()
{
    int n;
    printf("Enter\n1 for push      2 for display       3 for peek      4 for pop      5 for exit\n");
    while(1)
    {
        scanf("%d",&n);
        switch(n)
        {
            case 1:   push();         break;
            case 2:   display();      break;
            case 3:   peek();         break;
            case 4:   pop();          break;
            case 5:   exit(0);        break;
        }
    }
    return 0;
}