#include<stdio.h>
int main()
{
    int arr[10]= {1,2,5,4,9,6,7,10,8,9};
    int ele;
    // for(int i=0;i<10;i++)
    //    printf("%d ",arr[i]);
    printf("\nEnter element: ");
    scanf("%d",&ele);
    int f=0;
    for(int i=0;i<10;i++)
    {
        if(arr[i]==ele)
        {
            printf("Element %d found on location %d\n",ele,i+1);
            f = 1;
        }
       
    }
    if(f==0)
         printf("Not found\n");
    return 0;
}
