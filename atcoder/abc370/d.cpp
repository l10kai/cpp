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

void solve() {
    i64 n, m, q;
    cin >> n >> m >> q;

    set<i64> row[n + 10], col[m + 10];

    auto del = [&](i64 x, i64 y) {
        row[x].erase(y);
        col[y].erase(x);
    };

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            row[i].insert(j);
            col[j].insert(i);
        }

    while (q--) {
        i64 x, y;
        cin >> x >> y;

        if (row[x].count(y)) {
            del(x, y);
            continue;
        }

        if (!row[x].empty()) {
            auto it = row[x].upper_bound(y);

            if (it != row[x].end())
                del(x, *it);

            if (!row[x].empty()) {
                it = row[x].upper_bound(y);
                if (it != row[x].begin()) {
                    it--;
                    del(x, *it);
                }
            }
        }

        if (!col[y].empty()) {
            auto it = col[y].upper_bound(x);

            if (it != col[y].end()) {
                del(*it, y);
            }
            if (!col[y].empty()) {
                it = col[y].upper_bound(x);
                if (it != col[y].begin()) {
                    it--;
                    del(*it, y);
                }
            }
        }
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += row[i].size();
    }
    cout << ans << ln;
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
