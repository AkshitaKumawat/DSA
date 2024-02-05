#include<stdio.h>
#include<ctype.h>
#include<string.h>
int top = -1;
char stack[30];
int precedence(char);
void push(char);
char pop();
int main()
{
    char str[] = "(((A+B^G)*D)^(E+F-H))"  ,x;
    strrev(str);
    char rev[strlen(str)];
    int j = 0;
    for(int i=0;str[i] != '\0';i++)
    {
        if(isalpha(str[i]))
        {
            rev[j]=str[i];
            j++;
        }
        else if(str[i]==')')
            push(str[i]);
        else if(str[i]=='(')
        {
            while((x=pop())!=')')
            {
                rev[j]=x;
                j++;
            }
        } 
        else
        {
            while(precedence(stack[top]) >= precedence(str[i]) && str[i]!='^')
            {
                rev[j] = pop();
                j++;
            }
            push(str[i]);
        }    
    }
    while(top!=-1)
    {
        rev[j] = pop();
        j++;
    }
    printf("%s",strrev(rev));
    return 0;
}

int precedence(char symbol)
{
    if(symbol == '^')
        return 3;
    else if(symbol == '*' || symbol == '/')
        return 2;
    else if(symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;   
}
void push(char ele)
{
    stack[++top] = ele;
}
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}