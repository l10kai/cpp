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
    int n, m;
    cin >> n >> m;
    vector<i64> v(n + 10), w(n + 10);
    vector<vector<i64>> dp(m + 10, vector<i64>(20, -1e18));
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
        w[i] %= 16;
    }
    // dp[j][k],dp[j - v[i]][(k + w[i] % 16) % 16
    // 饱食度，幸福度
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            for (int k = 0; k < 16; k++)
                dp[j][k] = max(dp[j][k], dp[j - v[i]][(k + w[i]) % 16] + 1);

    i64 maxx = 0;
    for (int i = 0; i <= m; i++)
        maxx = max(maxx, dp[i][0]);
    cout << maxx << ln;
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
