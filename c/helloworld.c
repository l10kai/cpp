
#include <stdio.h>
#include <stdlib.h>

int main()
{
  long long A,B;
  int c;
  scanf("%d %lld %lld",&c,&A,&B);
  long long  A10=0,B10=0;
  int x=1;
  while(A>0){
    int n=A%10;2
    A10+=n*x;
    x*=c;
    A/=10;
  }
  int y =1;
  while(B>0){
    int n=B%10;
    B10+=n*y;
    y*=c;
    B/=10;
  }
printf("%lld",A10*B10);
printf("\n %d %d",A10,B10);

  return 0;
}