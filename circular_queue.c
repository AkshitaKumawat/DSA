#include<stdio.h>
#include<process.h>
void enqueue();
void dequeue();
void display();
int queue[5];
int front=-1,rear=-1;
int main()
{
    int n;
    printf("Queue size is 5\n");
    while(1)
    {
        printf("1 for enqueue   2 for dequeue   3 for display   4 for exit\n");
        scanf("%d",&n);

        switch(n)
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
void enqueue()
{
    if((front==0 && rear==4) || ((rear+1)==front))
         printf("Overflow\n");
    else
    {
        if(front == -1)
            front = 0;
        printf("Enter element\n");
        rear = (rear+1)%5;
        scanf("%d",&queue[rear]);
    }
}
void dequeue()
{
    if(front==-1 && rear==-1)
        printf("Underflow\n");
    else
    {
        printf("%d is deleted\n",queue[front]);
        front = (front+1)%5;
    }
}
void display()
{
    if(front==-1)
        printf("Underflow\n");
    else
    {
        for(int i=front;i!=rear;i=(i+1)%5)
        {
            printf("%d\n",queue[i]);
        }
        printf("%d\n",queue[rear]);
    }
}