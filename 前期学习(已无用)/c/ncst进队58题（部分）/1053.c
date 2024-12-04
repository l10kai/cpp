#include <stdio.h>
int run(int a){

    if(a%4==0){
       return 1;
    }else{
        return 0;
    }
    
}
int main(){
    int a,b,c;
    int sum=0;
    scanf("%d %d %d",&a,&b,&c);
    if(run(a)==1){
        for(b=b-1;b>0;b--){
            if(b==2){
                sum+=29;
            }
            else if(b==1||b==3||b==5||b==7||b==8||b==10||b==12){
                sum+=31;
            }else{
                sum+=30;
            }
        }
    }

     else if(run(a)==0){
       for(b=b-1;b>0;b--){
            if(b==2){
                sum+=28;
            }
            else if(b==1||b==3||b==5||b==7||b==8||b==10||b==12){
                sum+=31;
            }else{
                sum+=30;
            }
        }
    }
    sum+=c;
    printf("%d",sum);
    return 0;
    }