/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x)    x.begin(), x.end()
#define rall(v)   v.rbegin(), v.rend()
#define sqr(x)    ((x) * (x))
#define lowbit(x) (x & (-x))
#define as        static_cast
#define fi        first
#define se        second
#define pb        push_back
#define ppb       pop_back
#define pii       pair<int, int>
#define pll       pair<i64, i64>

// #define cin fin
// #define cout fout
// std::ifstream fin("E:/Cpp/duipai/in.txt");
// std::ofstream fout("E:/Cpp/duipai/out.txt");

using namespace std;
using f64 = double;
using i64 = long long;
using u64 = unsigned long long;
using f128 = long double;

const char &ln = '\n';

void solve() {
    i64 n, m;
    cin >> n >> m;

    vector<vector<i64>> g(n + 10);

    for (int i = 0; i < m; i++) {
        i64 u, v;
        cin >> u >> v;
        g[u].push_back(v);
        // g[v].push_back(u);
    }

    auto bfs = [&](i64 x) {
        vector<i64> dist(n + 10, -1e8);

        queue<i64> q;
        q.push({x});
        dist[x] = 0;
        while (!q.empty()) {
            auto u = q.front();
            q.pop();

            for (auto x : g[u]) {
                if (x == 1) {
                    cout << dist[u] + 1 << ln;
                    return;
                }
            }

            for (auto v : g[u]) {
                if (dist[v] == -1e8) {
                    dist[v] = dist[u] + 1;
                    q.push({v});
                }
            }
        }
        cout << -1 << ln;
        return;
    };

    bfs(1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
