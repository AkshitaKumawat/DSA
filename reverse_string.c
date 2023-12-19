#include<stdio.h>
char stack[20];
void push(char);
char pop();
int top=-1;
int main()
{
    char str[20];
    printf("Enter string: \n");
    gets(str);
    //push array elements into stack
    for(int i=0;str[i]!='\0';i++)
    {
        push(str[i]);
    }
    //print reverse string in output
    for(int j=0;top!=-1;j++)
    {
        printf("%c",pop());
    }
    return 0;
}
void push(char n)
{
    stack[++top] = n;
}
char pop()
{
    return stack[top--];
}
