#include<stdio.h>
// int f=0;
int binarySearch(int arr[],int size,int element)
{
    int low,mid,high;
    low = 0;
    high = size-1;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid] == element)
            return mid;
        if(element > arr[mid])
            low = mid+1;
        else
            high = mid-1;
    }
    
}
int main()
{
    int s;
    printf("Enter size of array: ");
    scanf("%d",&s);
    int arr[s];
    printf("Enter sorted array :\n");
    for(int i=0;i<s;i++)
    {
        scanf("%d",&arr[i]);
    }
    // int size = sizeof (arr)/sizeof(int);
    int ele;
    printf("\nEnter element: ");
    scanf("%d",&ele);
    int searchIndex = binarySearch(arr,s,ele);
    printf("Element %d found on index %d\n",ele,searchIndex);
    // if(f==1)
    //     printf("Element %d found on index %d\n",ele,searchIndex);
    // else
    //     printf("Not found\n");
    return 0;
}
