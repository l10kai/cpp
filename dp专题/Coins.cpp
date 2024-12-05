#include <bits/stdc++.h>
#include <iomanip>
#define double long double
using namespace std;

using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<double> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<double>> dp(n + 1, vector<double>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] * (1 - a[i]);
    }
    dp[1][1] = a[1];

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j] * (1 - a[i]) + dp[i - 1][j - 1] * a[i];
        }
    }
    double ans = 0;
    for (int i = 0; i <= n; i++) {
        if (i > n / 2) {
            ans += dp[n][i];
        }
    }
    cout << fixed << setprecision(12) << ans << ln;
    return 0;
}
