#include <stdio.h>
int change(int n,int a[1000],int m){
     int temp[1000];
     for(int i =0;i<n;i++){
       temp[i]=a[(i-m+n)%n];
     }
     for(int i=0;i<n;i++){
        a[i]=temp[i];
     }
}

int main(){
    int n,m,a[1000];
    scanf("%d",&n);
   for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
     }
     scanf("%d",&m);
     change(n,a,m);
       for(int i=0;i<n;i++){
        printf("%d ",a[i]);
     }
     return 0;
}