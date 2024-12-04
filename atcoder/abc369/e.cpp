/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <tuple>
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

// #define cin fin
// #define cout fout
// std::ifstream fin("E:/Cpp/duipai/in.txt");
// std::ofstream fout("E:/Cpp/duipai/out.txt");

using namespace std;
using f64 = double;
using i64 = long long;
using f128 = long double;

const char &ln = '\n';

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<i64>> d(n + 10, vector<i64>(n + 10));
    vector<tuple<i64, i64, i64>> names(m + 10);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = 1e18;

    for (int i = 1; i <= m; i++) {
        i64 l, r, v;
        cin >> l >> r >> v;
        d[l][r] = d[r][l] = min({d[l][r], v, d[r][l]});
        names[i] = {l, r, v};
    }

    auto floyd = [&]() {
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    };
    floyd();

    i64 q;
    cin >> q;

    while (q--) {
        i64 k;
        cin >> k;
        vector<i64> b;

        i64 ans = 1e18;

        for (int i = 0; i < k; i++) {
            int t;
            cin >> t;
            b.push_back(t);
        }

        sort(all(b));
        i64 tmp = 1e18;

        function<void(i64, i64, i64)> dfs = [&](i64 x, i64 ans, i64 point) {
            if (ans >= tmp)
                return;
            if (x < k) {
                auto [l, r, v] = names[b[x]];
                dfs(x + 1, ans + d[point][l] + v, r);
                dfs(x + 1, ans + d[point][r] + v, l);
            }

            if (x >= k) {
                tmp = min(tmp, ans + d[point][n]);
                return;
            }
        };

        if (b.empty()) {
            cout << d[1][n] << ln;
            return;
        }

        do {
            dfs(0, 0, 1);
        } while (next_permutation(all(b)));
        cout << tmp << ln;
    }
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
