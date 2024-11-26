#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, k, T;
vector<int> g[N];
int fa[N][17], depth[N], lg[N];
void init() {
  for (int i = 1; i <= n; ++i)
    lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
}
void dfs(int cur, int father) {
  fa[cur][0] = father;
  depth[cur] = depth[father] + 1;
  for (int i = 1; i <= lg[depth[cur]]; ++i) {
    fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
  }
  for (auto i : g[cur]) {
    if (i != father)
      dfs(i, cur);
  }
}
int LCA(int x, int y) {
  if (depth[x] < depth[y])
    swap(x, y);               // 不妨假设x深度更大
  while (depth[x] > depth[y]) // 跳到同一深度
  {
    x = fa[x][lg[depth[x] - depth[y]] - 1];
  }
  if (x == y)
    return x;
  for (int k = lg[depth[x]] - 1; k >= 0; --k) // 跳到LCA下边一层
  {
    if (fa[x][k] != fa[y][k]) {
      x = fa[x][k], y = fa[y][k];
    }
  }
  return fa[x][0];
}
int root;
int main() {
  cin >> n >> m >> root;
  init();
  n--;
  while (n--) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(root, 0);
  while (m--) {
    int x, y;
    cin >> x >> y;
    int tmp = LCA(x, y);
    cout << tmp << '\n';
  }
  return 0;
}
