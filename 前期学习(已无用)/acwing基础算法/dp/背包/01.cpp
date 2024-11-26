#include <bits/stdc++.h>

using namespace std;

const int N=1010;

int n,m;
int v[N],w[N];
// int f[N][N];
int f[N];
int main(){
    cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];

    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         f[i][j]=f[i-1][j];
    //         if(j>=v[i]) f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
    //     }
    // }

  //  优化版本

    for(int i=1;i<n;i++)
        for(int j=v[i];j<=m;j++)
            f[j]=max(f[j],f[j-v[i]]+w[i]);//前i轮已经决策的物品且背包容量 j下的最大价值。


    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
          //  cout<<"i="<<i<<"j="<<j<<" f[j]="<<f[j]<<" ";
            cout<<f[j]<<" ";
        }
        puts("");
    }
  //  cout<<f[n][m]<<endl;
    return 0;
}