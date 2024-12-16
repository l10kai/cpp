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
constexpr i64 inf = 1e18;

void solve() {
    i64 n, W;
    cin >> n >> W;
    vector<i64> a(13);

    for (int i = 0; i < n; i++) {
        i64 x;
        cin >> x;
        a[--x]++;
    }

    vector<vector<i64>> v(1 << 13);

    for (i64 i = 0; i < 1 << 13; i++) {
        for (i64 j = 0; j < 1 << 13; j++) {
            i64 w = 0;
            bool bl = false;

            for (i64 k = 0; k < 13; k++) {
                i64 ii = i >> k & 1, jj = j >> k & 1;

                if (jj)
                    w += a[k];

                if (!ii && jj) {
                    bl = true;
                    break;
                }
            }
            if (!bl && w <= W)
                v[i].pb(j);
        }
    }

    vector<i64> dp(1 << 13, inf);
    dp[0] = 0;

    for (int i = 0; i < 1 << 13; i++) {
        for (auto j : v[i]) {
            dp[i] = min(dp[i], dp[i ^ j] + 1);
        }
    }
    cout << dp[(1 << 13) - 1] << ln;
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
