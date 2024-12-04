#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
// 邻接矩阵
int n, m;
bool g[N][N];
bool st[N];
// 深度优先遍历
void dfs(int x) {
    cout << x << ' ';  // 输出遍历的节点
    for (int i = 0; i < n; i++) {
        if (g[x][i] && !st[i]) {
            st[i] = true;
            dfs(i);
        }
    }
}
// 广度优先遍历
void bfs(int x) {
    queue<int> q;
    q.push(x);
    st[x] = true;
    while (q.size()) {
        int t = q.front();
        q.pop();
        cout << t << ' ';  // 输出遍历的节点
        for (int i = 0; i < n; i++) {
            if (g[t][i] && !st[i]) {
                q.push(i);
                st[i] = true;
            }
        }
    }
}

signed main() {
    cin >> n >> m;  // n为节点数，m为边数

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;  // a到b有边
        g[a][b] = g[b][a] = 1;
    }
    // dfs(1);
    // bfs(1);
    return 0;
}