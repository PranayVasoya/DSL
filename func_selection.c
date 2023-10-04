#include <stdio.h>
void selection(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for (int j=i+1;j<n;j++)
        {
            if (arr[j]<arr[min])
            {
                min=j;
            }
        }
        int temp= arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
            
    }
}
int main()
{
    int arr1[]={22,5,3,8};
    int size=sizeof(arr1)/sizeof(arr1[0]);
    selection(arr1, size);
    for (int i=0;i<size;i++)
    {
        printf("%d ", arr1[i]);
    }
}