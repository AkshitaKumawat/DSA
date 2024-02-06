#include <stdio.h>


int count_sort(int arr[], int max, int n)
{
    int Carr[max + 1];
    for (int i = 0; i < (max + 1); i++)
    {
        Carr[i] = 0; // intialising count arrary with zeroes
    }

    for (int i = 0; i < n; i++)
        Carr[arr[i]]++; // frequencies

    for (int i = 1; i < (max + 1); i++)
        Carr[i] = Carr[i] + Carr[i - 1]; // cumulative sum of frequencies to find last location of an element

    int Oarr[n];
    for (int i = (n - 1); i >= 0; i--)
    {
        Oarr[--Carr[arr[i]]] = arr[i];
        //Carr[arr[i]]--; //= Carr[arr[i]] -1;
    }
    
    //printing output array
    for (int i = 0; i < n; i++)
        printf("%d ", Oarr[i]);
}

int main()
{
    int s;
    printf("Enter size of array: ");
    scanf("%d", &s);

    int arr[s];
    printf("Input array\n");
    for (int i = 0; i < s; i++)
        scanf("%d", &arr[i]);

    int max;
    printf("Enter maximum no. you entered in array:");
    scanf("%d", &max);

    count_sort(arr, max, s);
    return 0;
}

// int count_sort(int arr[],int max,int s)
// {
//     int Carr[max+1];
//     for(int j=0;j<(max+1);j++)
//     {
//         Carr[j] = 0;    //intialising count arrary with zeroes
//     }

//     for(int k=0;k<(max+1);k++)
//         Carr[arr[k]]++;    //frequencies

//     for(int l=1;l<(max+1);l++)
//         Carr[l] = Carr[l] + Carr[l-1];     //cumulative sum of frequencies

//     int Oarr[s];
//     for(int i=(s-1);i>=0;i--)
//     {
//         Oarr[Carr[arr[i]]-1] = arr[i];
//     }

//     for(int i=0;i<s;i++)
//         printf("%d ",Oarr[i]);
// }