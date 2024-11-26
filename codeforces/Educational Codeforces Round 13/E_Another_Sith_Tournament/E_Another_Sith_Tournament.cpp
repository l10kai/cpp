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

const int N = 20;
int n;
double p[N][N];
double dp[1 << N][N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> p[i][j];
    dp[1][0] = 1;
    for (int i = 2; i < (1 << n); i++) {
        for (int k = 0; k < n; k++) {
            if (!(i & (1 << k)))
                continue;
            for (int j = 0; j < n; j++) {
                if (!(i & (1 << j)))
                    continue;
                if (j == k)
                    continue;
                dp[i][k] = max(dp[i][k], dp[i - (1 << j)][k] * p[k][j] +
                                             dp[i - (1 << k)][j] * p[j][k]);
            }
        }
    }
    double ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[(1 << n) - 1][i]);
    cout << fixed << setprecision(10) << ans << ln;
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
    return 0;
}
