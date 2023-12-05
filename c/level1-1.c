#include <stdio.h>
int main()
{
int a=0;
int b =0;
int c =0;
scanf("%d %d %d",&a,&b,&c);
int d=c;
if(a>b)
{
if(a<c)
{
    while(c>a)
    {
        int e = d-c;
        printf("%d %d 0\n",c,e);
        c=c-1;
    };
    while(c<=a,c>b)
    {
        int e =d-c;
        while(c>=1) 
        printf("%d %d 1\n",c,e);
        c=c-1;
}
if(c==b)
{
    int e=d-c;
    printf("%d %d 0\n",c,e);
}
}
else
{
    while(c<a)
    {
        int e =c-d;
        printf("%d %d 0\n",c,e);
        c=c+1;
    };
    
    while(c<=a,c>b)
  
    {
        int f =2*a-d-c;
        printf("%d %d 1\n",c,f);
        c=c-1;
    }
    if(c==b)
    {
        int f =2*a-d-c;
        printf("%d %d 0\n",c,f);
    }
}
}
else
{
    if(a<c)
{
    while(c>a)
    {
        int e = d-c;
        printf("%d %d 0\n",c,e);
        c=c-1;
    };
    while(c>=a&&c<b)
    {
        int f =d+c-2*a;
        printf("%d %d 1\n",c,f);
        c=c+1;
}
if(c==b)
{
    int f=d+c-2*a;
    printf("%d %d 0\n",c,f);
}
}
else
{
    while(c<a)
    {
        int e =c-d;
        printf("%d %d 0\n",c,e);
        c=c+1;
    };
    
    while(c>=a,c<b)
  
    {
        int f =2*a-d-c;
        printf("%d %d 1\n",c,f);
        c=c-1;
    }
    if(c==b)
    {
        int f =2*a-d-c;
        printf("%d %d 0\n",c,f);
    }
}
}
return 0;
}