//深度优先搜索
//算法奇怪，空间要求高

//俗称暴搜，考虑顺序！
#include <bits/stdc++.h>

using namespace std;

const int N=10;

mp[N][N];

int path[N];
bool st[N];
int dx[8]={1,1,-1,-1,1,0,-1,0},
        dy[8]={1,1,-1,-1,0,1,0,-1};

void dfs(int u){
    if(u==3){
        for(int i=0;i<n;i++) printf("%d ",path[i]);
        puts("");
        return ;
    }
    for(int i=1;i<=n;i++)
		if(!st[i]){
        path[u]=i;
        st[i]=true;
        dfs(u+1);
        st[i]=false;
    }
} 


int main(){
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3;j++) cin >> mp[i][j];
        dfs(0);
        return 0;
    }
