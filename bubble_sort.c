#include <stdio.h>
int main()
{ 
    int n=5;
    int arr[]={5,4,7,8,6};
    int flag;
    for (int i=0;i<n-1;i++)
    { 
      flag=0;
      for(int j=0;j<n-i-1;j++)
      {
        flag++;
        if (arr[j]>arr[j+1])
        {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
      }
      if (flag==0)
      {
        break;
      }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    
}






