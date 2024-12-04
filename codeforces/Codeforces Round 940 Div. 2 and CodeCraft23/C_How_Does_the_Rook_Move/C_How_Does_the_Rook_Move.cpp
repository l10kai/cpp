/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
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

using namespace std;
using i64 = long long;
const char &ln = '\n';

const i64 mod = 1e9 + 7;

void solve() {
    i64 n, k;
    cin >> n >> k;

    vector<i64> dp(n + 10);

    int num = n;
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        num -= 2 - (l == r);
    }

    dp[0] = dp[1] = 1;
    
    for(int i = 1;i <= num; i ++){
        dp[i] = (dp[i - 1] + 2ll*(i - 1)*dp[i - 2]%mod) %mod;
    }

    cout << dp[num] << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
