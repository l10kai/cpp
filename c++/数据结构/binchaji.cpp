//特点：短 考察思维，比赛常用

//路径压缩yes，按秩合并no

//难点：要额外维护什么信息，如何维护？ //距离或长度 



#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int n,m;
int p[N]; //父节点

//返回x的根节点 （使用路径压缩优化）

//模板

int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

int main(){
    


}