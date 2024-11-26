#include <bits/stdc++.h>

using namespace std;

const int N  =510;

int a[N][N];
int dp[N][N];

int main(){

    //memset(dp,0xbf,sizeof dp);

    int n;cin >> n;

    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=i;j++)
            cin >> a[i][j];

    for(int i = n;i>=0;i--)
        for(int j = 0;j<=i;j++)
            dp[i][j]= max(dp[i+1][j+1],dp[i+1][j])+a[i][j];

    cout <<dp[1][1];

}
