#include<stdio.h>
void merge(int a[],int low,int mid,int high){
    int i=low;
    int j=mid+1,k=low;
    int b[100];
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++,k++;
        }
        else{
        b[k]=a[j];
        k++,j++;
        }

    }
    while(i<=mid){
        b[k]=a[i];
        i++,k++;
    }
     while(j<=high){
        b[k]=a[j];
        j++,k++;
    }
    for(int i=0;i<=high;i++){
        a[i]=b[i];
    }
}
void mergesort(int a[],int low,int high){
    int mid;
    
    if(low<high){
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }

}
int main(){
    int a[6]={8,5,7,6,4,2};
    
    mergesort(a,0,6);
    for(int i=0;i<6;i++){
        printf("%d ",a[i]);
    }
}
