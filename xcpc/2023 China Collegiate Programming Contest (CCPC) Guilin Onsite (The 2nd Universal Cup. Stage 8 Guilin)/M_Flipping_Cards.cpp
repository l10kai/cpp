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
    int n;
    cin >> n;

    vector<pll> a(n);

    for (auto &[l, r] : a) {
        cin >> l >> r;
    }

    i64 l = 0, r = 1e9;

    auto check = [&](i64 x) {
        vector<i64> c(n, 0);
        i64 tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp += (a[i].fi >= x);

            if (a[i].fi >= x && a[i].se < x)
                c[i] = -1;
            else if (a[i].fi < x && a[i].se >= x)
                c[i] = 1;
        }

        i64 res = 0, dp = 0;
        for (auto i : c) {
            dp = max(dp + i, i);
            res = max(res, dp);
        }
        res += tmp;

        if (res >= (n + 1) / 2)
            return true;

        return false;
    };

    while (l < r) {
        i64 mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }

    cout << l << ln;
    return;
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
