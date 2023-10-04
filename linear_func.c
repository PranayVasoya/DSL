#include <stdio.h>
int search(int arr[],int n,int key)
{
    for (int i=0;i<n;i++)
    {
        if (arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr1[]={2,44,55,66};
    int x=55;
    int size=4;
    int result=search(arr1,size,x);
    if (result==-1)
    {
        printf("Element not found");
    }
    else
    {
        printf("%d found at %d index",x,result);
    }
    return 0;
}