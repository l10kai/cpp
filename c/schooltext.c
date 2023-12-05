#include <stdio.h>

int main() {
    int n;
    while(1){
        scanf("%d",&n);
        if(n==0){
            break ;
        }
        int sum= 0;
        int num;
        while(n--){
            scanf("%d",&num);
            sum+=num;
        }
        printf("%d\n",sum);
    }

    return 0;
}
