#include<stdio.h>
int swap(int* , int*);
int selection_sort(int arr[],int n)
{
    int small;
    for(int i=0;i<(n-1);i++)
    {
         small = arr[i];
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            { 
                small = arr[j];
                swap(&arr[i],&arr[j]);
            }
        }
    }
    //printf("value of small %d\n",small);
    for(int k=0;k<n;k++)
    {
        printf("%d ",arr[k]);
    }
}
int swap(int* a,int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int size;
    printf("Define size of an array: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter array elements\n");
    for(int l=0;l<size;l++)
    {
        scanf("%d",&arr[l]);
    }
    selection_sort(arr,size);
    return 0;
}