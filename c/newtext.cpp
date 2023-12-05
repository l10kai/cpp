#include <stdio.h>
int  main(){
    int a[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }    
  //冒泡循环
    for(int i=0;i<n;i++){
        for(int j=1;j<n-1;j++){
            if(a[i-1]>a[i]){
                int tem=a[i];
                a[i]=a[i-1];
                a[i-1]=tem;   
                //swap(a[i],a[i-1]);
            }
        }
    }
      for(int i=0;i<n;i++) printf("%d ",a[i]);

    return 0;
}