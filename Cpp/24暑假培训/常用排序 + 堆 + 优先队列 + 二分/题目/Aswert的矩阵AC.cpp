#include <bits/stdc++.h>
using namespace std;
#define maxn 550
#define inf 1000000007
struct edge {
  int ti;
  int wi;
  int ri;
};
int m, n;
queue<int> q;
vector<edge> ed[maxn];
int dis[maxn] = {0};
int s = 511, t = 512;
int xx[maxn][maxn] = {{0}};
void addedge(int ss, int tt, int ww) {
  edge ee;
  ee.ti = tt;
  ee.wi = ww;
  ee.ri = ed[tt].size();
  ed[ss].push_back(ee);
  ee.ri = ed[ss].size() - 1;
  ee.ti = ss;
  ee.wi = 0;
  ed[tt].push_back(ee);
  return;
}
void bfs() {
  int i, j;
  for (i = 0; i < maxn; i++)
    dis[i] = inf;

  dis[s] = 0;
  q.push(s);
  while (1) {
    if (q.size() == 0)
      break;
    i = q.front();
    q.pop();
    for (j = 0; j < ed[i].size(); j++) {
      if (ed[i][j].wi > 0 && dis[i] + 1 < dis[ed[i][j].ti]) {
        dis[ed[i][j].ti] = dis[i] + 1;
        q.push(ed[i][j].ti);
      }
    }
  }
}

int find(int x, int low) {
  int i, j, k;
  int tt, rr, ww;

  if (x == t || low == 0)
    return low;

  for (i = 0; i < ed[x].size(); i++) {
    tt = ed[x][i].ti;
    rr = ed[x][i].ri;
    ww = ed[x][i].wi;
    if (ww > 0 && dis[tt] == dis[x] + 1) {
      j = find(tt, min(ww, low));
      if (j > 0) {
        ed[x][i].wi -= j;
        ed[tt][rr].wi += j;
        return j;
      }
    }
  }
  return 0;
}
int dinic() {
  int ans = 0, a;
  while (1) {
    bfs();
    if (dis[t] == inf)
      break;
    while (a = find(s, inf))
      ans += a;
  }
  return ans;
}
int main() {
  int a, b, c, i, j, k;
  scanf("%d%d%d", &n, &m, &k);
  for (a = 1; a <= n; a++)
    for (b = 1; b <= m; b++)
      scanf("%d", &xx[a][b]);
  int l = 1, r = inf, mid;
  while (l < r) {
    mid = (l + r) / 2;
    for (i = 0; i < maxn; i++)
      ed[i].clear();
    for (a = 1; a <= n; a++)
      addedge(s, a, 1);
    for (b = 1; b <= m; b++)
      addedge(b + 250, t, 1);
    for (a = 1; a <= n; a++)
      for (b = 1; b <= m; b++)
        if (xx[a][b] <= mid)
          addedge(a, b + 250, 1);
    if (dinic() >= n - k + 1)
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}
