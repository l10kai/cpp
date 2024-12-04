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
    vector<i64> a(n + 10), s(n + 10), b(n + 10), ss(n + 10), sss(n + 10),
        s0(n + 10);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        ss[i] = ss[i - 1] + s[i];
        sss[i] = sss[i - 1] + ss[i];
        s0[i] += (n - i) * s[i] + s0[i - 1];
    }

    i64 q;
    cin >> q;

    auto query = [&](i64 x) {
        i64 l = 0, r = n;
        while (l < r) {
            i64 mid = (l + r + 1) >> 1;
            // (n + n - (x - 1)) * x /2
            if (mid * (2 * n - mid + 1) / 2 <= x)
                l = mid;
            else
                r = mid - 1;
        }

        i64 res = 0;

        // for (int i = 1; i <= r; i++) {
        //     res += ss[n] - ss[i - 1];
        //     res -= (n - i + 1) * s[i - 1];
        // }
        if (r >= 1) {
            res += ss[n] * r;
            res -= sss[r - 1];
            res -= s0[r - 1];
        }
        x -= (2 * n - r + 1) * r / 2;
        //
        res += ss[x + r] - ss[r];
        res -= x * s[r];
        // cerr << "x = " << x << " l = " << l << ln;
        return res;
    };

    while (q--) {
        i64 l, r;
        cin >> l >> r;

        cout << query(r) - query(l - 1) << ln;
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
