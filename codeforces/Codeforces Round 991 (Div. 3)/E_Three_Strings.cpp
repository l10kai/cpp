/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <iostream>
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

const i64 inf = 1e9;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;

    int n = a.size(), m = b.size();
    a = " " + a;
    b = " " + b;
    c = " " + c;
    vector<vector<i64> > dp(a.size() + 10, vector<i64>(b.size() + 10, inf));

    dp[0][0] = 0ll;
    dp[1][0] = (a[1] != c[1]);
    dp[0][1] = (b[1] != c[1]);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (i == 0) {
                dp[i][j] = dp[i][j - 1] + (b[j] != c[i + j]);
                continue;
            }
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + (a[i] != c[i + j]);
                continue;
            }

            dp[i][j] = min(dp[i - 1][j] + (a[i] != c[i + j]),
                           dp[i][j - 1] + (b[j] != c[i + j]));
        }
    }

    cout << dp[n][m] << ln;
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
