#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const char &ln = '\n';

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n;
    cin >> n;

    vector<i64> a(n + 10);
    vector<vector<i64>> dp(n + 10, vector<i64>(3));
    dp[0][0] = -1e18;
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        dp[i][0] = max(dp[i - 1][1] + a[i], dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][0] + 2 * a[i], dp[i - 1][1]);
    }
    cout << max(dp[n][1], dp[n][0]) << ln;
    return 0;
}
