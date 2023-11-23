#include<stdio.h>
void TOH(int n,char A,char B,char C)
{
    if(n>0)
    {
        TOH((n-1),A,C,B);  //A to B using C
        printf("%c --> %c\n",A,C);
        TOH((n-1),B,A,C);   //B to C using A
    }
}
int main()
{
    int num;  //num is for number of disks
    printf("value of num: ");
    scanf("%d",&num);
    char A='A',B='B',C='C';
    TOH(num,A,B,C);
}