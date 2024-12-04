#include<stdio.h>
void tong(char *word){
    int zimu=0;
    int shuzi=0;
    int kongge=0;
    int others=0;
    for(int i=0;word[i]!='\0';i++){
        if((word[i]>='a'&&word[i]<='z')||(word[i]>='A'&&word[i]<='Z')){
            zimu++;
        }
       else if(word[i]>='0' && word[i]<='9'){
            shuzi++;
        }
        else if(word[i]==' '){
            kongge++;
        }
        else{
            others++;
        }
    }
    printf("%d %d %d %d",zimu,shuzi,kongge,others);

}

int main(){
    char word[500];
    scanf("%[^\n]",word);
    tong(word);
    return 0;
}