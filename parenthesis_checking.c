#include<stdio.h>
void push(char);
char pop();
char stack[20];
int top = -1;
int f=1;
int main()
{
    char t;
    int i;
    char s[20];
    printf("Enter string: ");
    gets(s);
    for(i=0 ; s[i] !='\0' ; i++)
    {
        if(s[i]=='[' || s[i]=='{' || s[i]=='(')
            push(s[i]);
        else if(s[i]==']' || s[i]=='}' || s[i]==')')
        {
            if(top==-1)
                f=0;     //Underflow
            else
            {
                t = pop();
                if(s[i] == ']' && (t=='(' || t=='{'))
                   f=0;
                if(s[i] == '}' && (t=='[' || t=='('))
                   f=0;
                if(s[i] == ')' && (t=='[' || t=='{'))
                   f=0;
            }
        }
    }

    if(top>=0)
        f=0;
    if(f==1)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;

}
void push(char n)
{
        //  ++top;
        stack[++top] = n;
}
char pop()
{
        // n=top;
        return stack[top--] ;
        // --top;
    // return stack[top] ;
}