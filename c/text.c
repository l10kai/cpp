#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int N;
  scanf("%d",&N);
  int min=1000000;
  int max=0;
  int sum=0;
  int maxcount=1,mincount=1;
  while(N--){
    int i; 
    scanf("%d",&i);
 
    sum+=i;
    if(i==max){
      maxcount++;
    }
    if(i==min){
        mincount++;
    }
     if(i>max){
      max =i;
      maxcount =1;
    }
    if(i<min){
      min = i;
      mincount =1;
    }
     
   

  }
  printf("%d\n",sum-min*mincount-max*maxcount);
  printf("%d %d %d %d %d",sum,max,min,maxcount,mincount);
  
  return 0;
}