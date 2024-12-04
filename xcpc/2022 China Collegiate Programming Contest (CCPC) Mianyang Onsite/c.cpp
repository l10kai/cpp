#include <bits/stdc++.h>
#include <cstdint>
#include <functional>

using namespace std;

using i64 = int64_t;

constexpr char ln = '\n';

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;

    vector<vector<i64>> a(n + 10);

    for (i64 i = 0; i < n - 1; i++) {
        i64 u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        a[u].push_back(v);
        // a[v].push_back(u);
    }

    i64 deep, ans = 0;

    function<void(i64, i64)> dfs = [&](i64 u, i64 fa) {
        deep = max(deep, fa);
        if (a[u].empty())
            return;
        for (auto v : a[u]) {
            dfs(v, fa + 1);
        }
        return;
    };

    for (auto u : a[1]) {
        deep = 0;
        dfs(u, 1);
        ans += deep;
    }

    cout << ans << ln;

    return 0;
}
