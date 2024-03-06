#include<cstdio>
using namespace std;
int head,tail,n,m,state[10001][3],c,s,x,y,qx,qy;
bool ok[101][101],a[101][101];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};//拓展方向
void bfs()
{
	head=0;
	tail=1;
	do
	{
		head++;//出队
		for (int i=0;i<4;i++)//4个方向
		{
			x=state[head][0];y=state[head][1];
			int j=1;
			while (!a[x+dx[i]*j][y+dy[i]*j] && x+dx[i]*j<=n && y+dy[i]*j<=m && x+dx[i]*j>0 && y+dy[i]*j>0)
			//如果碰到墙或边缘就结束拓展
			{
			  if (!ok[x+dx[i]*j][y+dy[i]*j])
			  //如果已经走过的路线就不入队
			  {
			  	tail++;//入队
			  	state[tail][0]=x+dx[i]*j;
			  	state[tail][1]=y+dy[i]*j;//储存位置
			  	state[tail][2]=state[head][2]+1;//储存转弯数
			  	ok[x+dx[i]*j][y+dy[i]*j]=true;//已经走过该地
			  	if (x+dx[i]*j==qx && y+dy[i]*j==qy)//结束判断
			  	{
			  		s=state[tail][2];
			  		return;
			  	}
			  }
			  j++;//下一个拓展
			}
		}
	}
	while(head<tail);//空队退出
}
int main()
{
	scanf("%d%d\n",&n,&m);		
	for (int i=1;i<=n;i++)
	{
	  for (int j=1;j<=m;j++)
	  {
	  	scanf("%d",&c);
	  	if (c!=0) a[i][j]=true;
	  }
	}
	scanf("%d%d%d%d",&state[1][0],&state[1][1],&qx,&qy);
	//输入不解释
	bfs();//函数不解释
	printf("%d",s-1);//输出不解释
}
