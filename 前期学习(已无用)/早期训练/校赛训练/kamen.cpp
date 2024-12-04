#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;

const int N=1100;

char a[N][N];
int d[N][N];

int n,m,l,r,l2,r2,l3,r3;

int bfs(){
    queue<PII> q;
    
    memset(d, -1, sizeof d);
    
    d[l][r]=0;
    q.push({l,r});
    
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; i ++ )
        {
            int x = t.first + dx[i], y = t.second + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m && a[x][y]!='#' && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
                  }

                   if (x == l2 && y == r2)
                    return d[l2][r2];
        }
    }

    return -1;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            char t;
            cin>>t;
            if(t=='s') l=i,r=j;
            if(t=='t') l2=i,r2=j;
            if(t=='#') l3=i,r3=j;
            a[i][j]=t;
        }
    //  cout<<l3<<r3;
    cout<<bfs();
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     puts("");
    // }
    return 0;
}