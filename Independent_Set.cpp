#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

const i64 mod = 1e9 + 7;
const i64 inf = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int> > g(n);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<i64> > dp(n, vector<i64>(2, -inf));

    function<void(int, int)> dfs = [&](int u, int p) {
        dp[u][0] = 0;
        dp[u][1] = 1;

        for (int v : g[u]) {
            if (v == p)
                continue;
            dfs(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    };

    dfs(0, -1);

    for (int i = 0; i < n; i++) {
        cout << max(dp[i][0], dp[i][1]) << " ";
    }

    return 0;
}
