/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <iomanip>
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
using u64 = unsigned long long;
using f128 = long double;

const char &ln = '\n';

struct node {
    double x1, y1, x2, y2;
};

void solve() {
    f128 n, s, t;
    cin >> n >> s >> t;

    vector<node> a(n);
    vector<bool> vis(n, false);

    f128 ans = 0;
    for (auto &[x1, y1, x2, y2] : a) {
        cin >> x1 >> y1 >> x2 >> y2;
        ans += hypotl(x1 - x2, y1 - y2) / t;
    }

    f128 tmp = 1e9;

    function<void(f128, f128, f128, f128)> dfs = [&](i64 x, i64 px, i64 py,
                                                 f128 cot) {
        if (x == n) {
            tmp = min(tmp, cot);
            return;
        }

        for (int i = 0; i < n; i++) {
            auto [x1, y1, x2, y2] = a[i];
            if (!vis[i]) {
                vis[i] = true;
                dfs(x + 1, x1, y1, cot + hypotl(x2 - px, y2 - py));
                dfs(x + 1, x2, y2, cot + hypotl(x1 - px, y1 - py));
                vis[i] = false;
            }
        }
    };

    // for (int i = 0; i < n; i++) {
    //     auto [x1, y1, x2, y2] = a[i];
    //     vis[i] = true;
    //     dfs(1, x1, y1, 0);
    //     dfs(1, x2, y2, 0);
    //     vis[i] = false;
    // }
    dfs(0, 0, 0, 0);

    cout<<fixed << setprecision(8) << ans + tmp / s << ln;
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
