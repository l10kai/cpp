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

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<pll> a(n);

    for (int i = 0; i < n; i++) {
        i64 c, w, f;
        cin >> c >> w >> f;

        a[i] = {c * w, f};
    }

    sort(all(a), [](const pll &x, const pll &y) {
        return x.se > y.se;
    });

    i64 ans = 0, now_f = a[0].se, sum_w = 0;

    for (auto [w, f] : a) {
        sum_w += w;

        if (sum_w > k) {
            sum_w -= k;
            ans += now_f;

            now_f = f;

            i64 times = (sum_w - 1) / k;
            ans += times * now_f;
            sum_w -= times * k;
        }
    }
    ans += now_f;
    cout << ans << ln;
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
