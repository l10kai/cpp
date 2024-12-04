#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
typedef long long LL;

typedef pair<LL, LL> PII;
typedef pair<LL, PII> PPII;
const LL N = 1010;

LL n, m, xx, yy;
LL g[N][N];
bool d[N][N];

void bfs() {
  priority_queue<PPII, vector<PPII>, greater<PPII>> p;
  //     LL now,base;
  //     LL add =0;
  //         now =base=g[xx][yy];
  int tot = 0;
  i64 now = g[xx][yy], base = now;
  g[xx][yy] = 0;
  LL dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

  p.push({g[xx][yy], {xx, yy}});
  d[xx][yy] = true;
  while (!p.empty()) {
    auto t = p.top();
    p.pop();
    //         if(now>=g[t.second.first][t.second.second])
    //         now+=g[t.second.first][t.second.second];
    //          else add+= g[t.second.first][t.second.second]-now,now+=add;
    if (now < g[t.second.first][t.second.second]) {
      i64 tmp = tot;
      tot += g[t.second.first][t.second.second] - now;
      now += g[t.second.first][t.second.second] + (tot - tmp);
    } else
      now += g[t.second.first][t.second.second];

    for (LL i = 0; i < 4; i++) {
      LL x = t.second.first + dx[i], y = t.second.second + dy[i];

      if (x >= 1 && x <= n && y >= 1 && y <= m && d[x][y] == false) {
        p.push({g[x][y], {x, y}});
        d[x][y] = true;
      }
    }
  }

  if (tot == 0)
    cout << "No cheating need.";
  else
    cout << base + tot;
}

int main() {
  cin >> n >> m >> xx >> yy;
  for (LL i = 1; i <= n; i++)
    for (LL j = 1; j <= m; j++)
      cin >> g[i][j];

  bfs();

  return 0;
}
