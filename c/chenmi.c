#include <stdio.h>
int  main(){
    double n,m;
    scanf("%lf %lf",&n,&m);
    double sum=n;
    for(int i=1;i<m;i++){
        n/=2;
        sum+=n*2;
    }
    double ans=n/2;
    printf("%.2lf %.2lf",ans,sum);
    return 0;
}