#include <stdio.h>


void quicksort(int a[],int left,int right){
    if(left>=right){
       return;
    }

    int key = a[left];
    int l = left;
    int r = right;
    while(l!=r){
        while(a[r]>=key && l<r){
            r--;
        }
        while(a[l]<=key&&l<r){
            l++;
        }   
        if(l!=r){
            int temp=a[l];
            a[l]=a[r];
            a[r]=temp;
        }
    }
    a[left]=a[l];
    a[l]=key;

    quicksort(a,left,l-1);
    quicksort(a,l+1,right);
}
int main(){
    int n;
    scanf("%d",&n);

    int a[n];
    int end=sizeof(a)/sizeof(a[0]);
    for(int i =0;i<n;i++){
        scanf("%d",&a[i]);
    }
    quicksort(a,0,end-1);
    for(int i=end-1;i>=0;i--){
        printf("%d ",a[i]);
    }
    
    return 0;
}