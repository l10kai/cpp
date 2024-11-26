#include <stdio.h>

int scan10(int a[10]){
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
}

int change(int a[10]){
    int min=100,max=0,minn,maxn;
    for(int i=0;i<10;i++){
        if(a[i]<min){
            min=a[i];
            minn=i;
        }
        if(a[i]>max){
            max=a[i];
            maxn=i;
        }
    }
    int temp1=a[0];
    a[0]=a[minn];
    a[minn]=temp1;

     int temp2=a[9];
    a[9]=a[maxn];
    a[maxn]=temp2;
}

int print(int a[10]){
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
}

int main(){
    int a[10];
    scan10(a);
    change(a);
    print(a);
    return 0;
}