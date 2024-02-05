#include <stdio.h>
#include <ctype.h>
// functions used
int precedence(char);
void push(char);
char pop();
// global variables
int top = -1;
char stack[20];
int main()
{
    char str[] = "(A^b^c-d/e)", x;

    for (int i = 0; str[i] != '\0'; i++)
    {
        // if operand
        if (isalnum(str[i]))
            printf("%c ", str[i]);

        // if opening bracket
        else if (str[i] == '(')
            push(str[i]);

        // if closing bracket
        else if (str[i] == ')')
        {
            while ((x = pop()) != '(')
                printf("%c ", pop());
        }
        // if precedence of operator in stack is greater than equal to precedence of scanned operator
        else
        {
            while (precedence(stack[top]) >= precedence(str[i]) && str[i]!='^')
                printf("%c ", pop());
            push(str[i]);
        }
    }
    // if operator remained in stack
    while (top > -1)
    {
        printf("%c", pop());
    }
    return 0;
}

void push(char item)
{
    stack[++top] = item;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int precedence(char operator)
{
    if (operator== '^')
        return 3;
    else if (operator== '*' || operator== '/')
        return 2;
    else if (operator== '+' || operator== '-')
        return 1;
    else
        return 0;
}