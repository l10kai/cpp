//深度优先搜索
//算法奇怪，空间要求高

//俗称暴搜，考虑顺序！
#include <bits/stdc++.h>

using namespace std;

const int N=10;

int n;
int path[N];
bool st[N];

void dfs(int u){
    if(u==n){
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
        cin>>n;
        dfs(0);
        return 0;
    }