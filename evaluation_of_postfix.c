#include <stdio.h>
#include <ctype.h>
#include <math.h>

void push(int);
int pop();
int evaluate(char, int, int);
int stack[10], top = -1;

int main()
{
    char exp[] = "22*2*";
    char x = '0';
    int a, b, c;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit(exp[i]))
        {
            push(exp[i]-48);
        }
        else
        {
            a = pop();
            b = pop();
            c = evaluate(exp[i], a, b);
            push(c);
        }
    }
    printf("Answer = %d", pop());
    return 0;
}

int evaluate(char op, int op1, int op2)
{
    switch (op)
    {
    case '+':
        return (op2 + op1);
        break;
    case '-':
        return (op2 - op1);
        break;
    case '*':
        return (op2 * op1);
        break;
    case '/':
        return (op2 / op1);
        break;
    case '^':
        return (pow(op2, op1));
        break;
    }
}

int pop()
{
    int x;
    if (top == -1)
        printf("\nUnderflow");
    else
    {
        x = stack[top];
        top--;
        return x;
    }
}

void push(int x)
{
    if (top == 9)
        printf("\nOverflow");
    else
    {
        top++;
        stack[top] = x;
    }
}