#include <stdio.h>
void insertion(int arr[],int n)
{
    for (int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]<key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main()
{
    int a[]={22,5,3,8};
    insertion(a,4);
    for (int i=0;i<4;i++)
    { printf("%d ",a[i]);}
}