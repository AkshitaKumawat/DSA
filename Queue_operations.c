#include <stdio.h>
#include <process.h>
void enqueue();
void dequeue();
void display();
int queue[5];
int front = -1, rear = -1;
int main()
{
    int n;

    while (1)
    {
        printf("1 for enqueue   2 for dequeue   3 for display   4 for exit\n");
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
void enqueue()
{
    if (rear == 4)
        printf("Overflow\n");
    else
    {
        if (rear == -1)
        {
            front++;
            rear++;
        }
        else
            rear++;
        printf("Enter element\n");
        scanf("%d", &queue[rear]);
    }
}
void dequeue()
{
    if (front == -1 || front > rear)
        printf("Underflow\n");
    else
    {
        printf("%d is deleted\n", queue[front]);
        front++;
    }
}
void display()
{
    if (front == -1)
        printf("Underflow\n");
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d \n", queue[i]);
        }
    }
}