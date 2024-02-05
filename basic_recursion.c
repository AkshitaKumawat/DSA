#include<stdio.h>
void print(int);

int main()
{
    int n;
    printf("Enter number less than 10\n");
    scanf("%d",&n);
    printf("recursive function works\n");
    print(n);
}

void print(int num)
{
    if(num == 10){
        printf("%d",num);
        return;
    }
    printf("%d ",num);
    return print(num + 1);
}