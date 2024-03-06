#include <bits/stdc++.h>

using namespace std;

typedef pair<int ,int > PII;

const int N=13;

int ans=0;
int mp[N][N],d[N][N];
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};

void bfs(int ii,int jj)
    {
    queue<PII> q;

//     memset(d, 0, sizeof d);
   // d[ii][jj] = 1;
    q.push({ii,jj});

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
//int tt=1;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        

        for (int i = 0; i < 4; i ++ )
        {
            int x = t.first + dx[i], y = t.second + dy[i];

            if (mp[x][y]==0 &&x>=0&&y>=0&&x<10&&y<10)
            {
                mp[x][y] =1;
                q.push({x, y});
            }
        }
    }

    return;
}

int main(){
    
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++) cin>>mp[i][j];

        bfs(0,0);
        bfs(9,9);
        bfs(0,9);
        bfs(9,0);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
           if(mp[i][j]==0) ans++;
        }
    }

    cout<<ans;
    return 0;
}