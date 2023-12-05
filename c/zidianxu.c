#include <stdio.h>
#include <string.h>

int main(){
    char a[3][1000];
   
    for( int i=0;i<3;i++){
        scanf("%s",a[i]);
    }

    for(int i =0;i<2;i++){
        for(int j=0;j<2-i;j++){
            if(strcmp(a[j],a[j+1])>0){
                char temp[1000];
                strcpy(temp,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],temp);
            }

        }
    }

for(int i=0;i<3;i++){
        printf("%s\n",a[i]);
    }

    return 0;
}