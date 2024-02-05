#include<stdio.h>
int Sum(int num)
{
    if(num == 1)
       return 1;
    else
       return num+Sum(num-1);
}
int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    int sum = Sum(n);
    printf("The sum is %d\n",sum);
    return 0;
}