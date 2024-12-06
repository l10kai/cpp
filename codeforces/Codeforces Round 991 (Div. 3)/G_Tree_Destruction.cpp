/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
#define all(x)    x.begin(), x.end()
#define rall(v)   v.rbegin(), v.rend()
#define lowbit(x) (x & (-x))

#define as  static_cast
#define fi  first
#define se  second
#define pb  push_back
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<i64, i64>

// #define cin fin
// #define cout fout
// std::ifstream fin("E:/Cpp/duipai/in.txt");
// std::ofstream fout("E:/Cpp/duipai/out.txt");

using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

const i64 inf = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<vector<i64> > g(n);
    vector<i64> deg(n, -2);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++;
        deg[v]++;
    }

    vector<bool> vis(n, false);

    i64 A = -1, maxx = -inf;
    function<void(i64, i64)> dfs1 = [&](i64 from, i64 cot) {
        if (cot >= maxx) {
            maxx = cot;
            A = from;
        }

        for (auto to : g[from]) {
            if (!vis[to]) {
                vis[to] = true;
                dfs1(to, cot + deg[to]);
                vis[to] = false;
            }
        }
    };
    vis[0] = true;
    dfs1(0, deg[0]);
    vis.assign(n, false);

    vis[A] = true;
    maxx = -inf;
    dfs1(A, deg[A]);

    cout << maxx + 2 << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
