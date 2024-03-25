#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, m;
int g[N][N]; // 稠密图，用临界矩阵写
int dist[N]; // 每个点到源点的最短路
bool st[N];  // 每个点的最短路是否已经确定

int dijkstra() {

  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;

  for (int i = 1; i <= n; i++) {
    int t = -1;

    for (int j = 1; j <= n; j++)
      if (!st[j] && (t == -1 || dist[t] > dist[j]))
        t = j;

    st[t] = true;

    for (int j = 1; j <= n; j++)
      dist[j] = min(dist[j], dist[t] + g[t][j]);
  }
  if (dist[n] == 0x3f3f3f)
    return -1;
  return dist[n];
}

int main() {

  cin >> n >> m;

  memset(g, 0x3f, sizeof g);

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a][b] = min(g[a][b], c); // 对于重边和自环，排除自环，保留最短的边
  }

  cout << dijkstra() << endl;

  return 0;
}
