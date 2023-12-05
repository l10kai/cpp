#include <stdio.h>
//a表示某一层的等待人数 f表示以某一层为目的的人数 c表示电梯所在层数 e表示电梯运行时间 b表示电梯内人数
int main()
{
   int a[11];
   int f[11];
   int i,b,e,c,g,h;
for (i=1;i<=10;i++)
{
   printf("From F%d?\n",i);
   scanf("%d",&a[i]);
}//输入等待乘客位置并储存
do
{
for(c=1;c<10;c++,e++)
{
         b=b-f[c];
         f[c]=0;//抵达目的地乘客出电梯     
   if(b+a[c]<=4)
   {
      b=b+a[c];
      h=h+a[c];
      a[c]=0;     
      for(h=h;h>0;h--)
      {
         printf("To F");
         scanf("%d",&g);
         f[g]++;
      }   //乘客输入目的楼层并储存     
      printf("%d %d %d\n",c,e,b);      
   }//电梯不超载可以满足乘坐需求
   else
   {
      a[c]=a[c]+b-4;
      h=h+4-b;
      b=4;
      
      for(h=h;h>0;h--)
      {
         printf("To F");
         scanf("%d",&g);
         f[g]++;
      }
      printf("%d %d %d\n",c,e,b);      
   }//电梯无法满足乘客需求
}
for (i=1;i<=10;i++)
{
   printf("From F%d?\n",i);
   scanf("%d",&a[i]);
}//输入等待乘客位置并储存
for(c=10;c>1;c--&e++)
{
         b=b-f[c];
         f[c]=0;//抵达目的地乘客出电梯     
   if(b+a[c]<=4)
   {
      b=b+a[c];
      h=h+a[c];
      a[c]=0;     
      for(h=h;h>0;h--)
      {
         printf("To F");
         scanf("%d",&g);
         f[g]++;
      }   //乘客输入目的楼层并储存     
      printf("%d %d %d\n",c,e,b);      
   }//电梯不超载可以满足乘坐需求
   else
   {
      a[c]=a[c]+b-4;
      h=h+4-b;
      b=4;     
      for(h=h;h>0;h--)  
      {
         printf("To F");   
         scanf("%d",&g);
         f[g]++;
      }
      printf("%d %d %d\n",c,e,b);      
   }//电梯无法满足乘客需求
}
}
while(a[1]!=0&a[2]!=0&a[3]!=0&a[4]!=0&a[5]!=0&a[6]!=0&a[7]!=0&a[8]!=0&a[9]!=0&a[10]!=0);
}
