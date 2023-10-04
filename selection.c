#include <stdio.h>
int main()
{
    int n=5,min;
    int i,j,arr[5]={44,3,55,1,9};
    for(i=0;i<n-1;i++)
    {   
        min=i;
        for(j=i+1;j<n;j++)
        {  
            if (arr[j]<arr[min])
            {
                int temp=arr[j];
                arr[j]=arr[min];
                arr[min]=temp;
            }
        }
    }
for (i=0;i<n;i++)
{
    printf("%d ",arr[i]);
}
return 0;
}