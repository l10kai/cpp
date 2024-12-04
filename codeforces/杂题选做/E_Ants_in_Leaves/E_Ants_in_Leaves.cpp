/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <functional>
#include <unordered_map>
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x)    x.begin(), x.end()
#define rall(v)   v.rbegin(), v.rend()
#define sqr(x)    ((x) * (x))
#define as        static_cast
#define fi        first
#define se        second
#define pb        push_back
#define ppb       pop_back
#define pii       pair<int, int>
#define pll       pair<i64, i64>

using namespace std;
using i64 = long long;
const char &ln = '\n';

void solve() {
    i64 n, cnt = 0, ans = 0;
    cin >> n;

    vector<vector<i64>> e(2 * n + 1);
    vector<i64> a(2 * n + 1);
    
    for (int i = 1; i < n; i++) {
        int from, to;
        cin >> from >> to;
        e[from].pb(to);
        e[to].pb(from);
    }

    function<void(int, int, int)> dfs = [&](int x, int f, int dep) {
        bool flg = true;
        for (int i = 0; i < e[x].size(); i++) {
            if (e[x][i] == f)
                continue;
            dfs(e[x][i], x, dep + 1);
            flg = false;
        }
        if (flg)
            a[++cnt] = dep;
    };

    for (auto &i : e[1]) {
        cnt = 0;
        dfs(i, 1, 1);
        sort(a.begin() + 1, a.begin() + 1 + cnt);

        for (int j = 2; j <= cnt; j++)
            a[j] = max(a[j], a[j - 1] + 1);

        ans = max(ans, a[cnt]);
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
