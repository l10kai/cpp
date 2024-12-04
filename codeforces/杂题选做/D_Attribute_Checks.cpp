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
    i64 n, m;
    cin >> n >> m;

    vector<i64> a(n), lazy_sum(m + 10, 0), dp(m + 10, -1e9);
    dp[0] = 0;
    for (auto &x : a) {
        cin >> x;
    }

    auto add = [&](i64 l, i64 r, i64 x) {
        if (l > r)
            return;
        lazy_sum[l] += x;
        lazy_sum[r + 1] -= x;
    };

    i64 idx = 0;
    auto push_and_clear = [&]() {
        for (int i = 0; i <= m; i++) {
            if (i > 0)
                lazy_sum[i] += lazy_sum[i - 1];
            dp[i] += lazy_sum[i];
        }
        fill(all(lazy_sum), 0);
    };

    for (auto x : a) {
        if (x == 0) {
            idx++;
            push_and_clear();

            for (int i = m; i >= 1; i--) {
                dp[i] = max(dp[i], dp[i - 1]);
            }

            continue;
        }

        else if (x > 0) {
            // X -> idx
            add(x, m, 1);
        }

        else {
            // 0 -> idx - x
            add(0, idx + x, 1);
        }
    }

    push_and_clear();
    // cout << idx << ln;
    cout << *max_element(all(dp)) << ln;
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
