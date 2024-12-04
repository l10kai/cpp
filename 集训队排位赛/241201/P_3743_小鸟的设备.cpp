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
#define pff pair<f64, f64>
// #define cin fin
// #define cout fout
// std::ifstream fin("E:/Cpp/duipai/in.txt");
// std::ofstream fout("E:/Cpp/duipai/out.txt");

using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = double;
const char &ln = '\n';

void solve() {
    f64 n, p;
    cin >> n >> p;

    vector<pff> a(n);
    f64 sum = 0;
    for (auto &[x, y] : a) {
        cin >> x >> y;
        sum += x;
    }

    if (sum <= p) {
        cout << -1 << ln;
        return;
    }
    f64 l = 0, r = 1e12;

    auto check = [&](f64 mid) {
        f64 tmp = 0;
        for (auto &[x, y] : a) {
            if (mid * x > y)
                tmp += mid * x - y;
        }
        return tmp <= p * mid;
    };

    while (r - l > 0.000001) {
        f64 mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }

    cout << fixed << setprecision(8) << l << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
