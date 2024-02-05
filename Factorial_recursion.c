#include<stdio.h>
int Factorial(int num)
{
    if(num == 1)
       return 1;
    else
       return num*Factorial(num-1);
}
int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    int fact = Factorial(n);
    printf("The sum is %d\n",fact);
    return 0;
}