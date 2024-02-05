#include<stdio.h>
int swap(int*,int*);
int s;

int bubble(int arr[])
{ 

    int flag;
    for(int i=0;i<s;i++)
    {  
        flag = 0;
        for(int j=0;j<(s-i-1);j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
           break;
    }
    
    for(int k=0 ; k<s; k++)
    {
        printf("%d ",arr[k]);
    }
}

int main()
{
    printf("Enter size of array: ");
    scanf("%d",&s);
    int arr[s];
    printf("Enter array elements: ");
    for(int i = 0;i<s;i++)
        scanf("%d",&arr[i]);
    bubble(arr);
    return 0;
}
int swap(int* a,int* b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

