#include <stdio.h>
void quick_sort(int a[],int low,int high)
{ 
    if (low < high)
    { 
        int pivot=low;
        int i=low;
        int j=high;
        while(i<j)
        {
            while(a[i] <= a[pivot] && i<=high)
            {
                i++;
            }
            while(a[j] > a[pivot] && j>=low)
            {
                j--;
            }
            if (i<j)
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        int temp = a[j];
        a[j]=a[pivot];
        a[pivot]=temp;
        quick_sort(a,low,j-1);
        quick_sort(a,j+1,high);
    }
}
int main()
{
    int arr[30], size,i;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    printf("Enter the elements: ");
    for (i=0;i<size;i++)
    { 
        scanf("%d",&arr[i]);
    }
    quick_sort(arr,0,size-1);
    printf("After sorting: ");
    for(i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}