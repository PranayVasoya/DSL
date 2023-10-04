#include <stdio.h>
void bubble(int arr[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    int arr1[]={22,5,3,8};
    int size= sizeof(arr1)/sizeof(arr1[0]);
    printf("sorting is: ");
    bubble(arr1,size);
    for (int i=0;i<size;i++)
    {
        printf("%d ",arr1[i]);
    }
}