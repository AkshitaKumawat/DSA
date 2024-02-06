#include<stdio.h>
int s;


int max_num(int arr[])
{
    int max = 0;
    for(int i=1;i<s;i++)
    {
        if(arr[max]<arr[i]) 
            max = i;
    }
    return arr[max];
}

int count_sort(int Oarr[], int pos)
{
    int Carr[10] = {0};
    for(int i=0; i<s; i++)
        ++Carr[(Oarr[i]/pos)%10];

    for(int i=1; i<=9; i++)
        Carr[i] = Carr[i] + Carr[i-1];

    int outputarr[s];   
    for(int i=(s-1); i>=0; i--)
        outputarr[--Carr[(Oarr[i]/pos)%10]] = Oarr[i];

    for(int i=0;i<s;i++)
    {
        Oarr[i] = outputarr[i];
    }
}

int radix_sort(int Oarr[])
{
    int maxnum = max_num(Oarr);
    int pos = 0;
    for(pos=1;maxnum%pos>0;pos*10)
        count_sort(Oarr,pos);
}

int main()
{
    printf("Enter size of an array: ");
    scanf("%d",&s);

    int Oarr[s];
    printf("Enter array elements\n");
    for(int i=0;i<s;i++)
        scanf("%d",&Oarr[i]);

    radix_sort(Oarr);

    printf("Sorted array: \n");
    for(int i=0;i<s;i++)
    {
        printf("%d ",Oarr[i]);
    }
    return 0; 
}