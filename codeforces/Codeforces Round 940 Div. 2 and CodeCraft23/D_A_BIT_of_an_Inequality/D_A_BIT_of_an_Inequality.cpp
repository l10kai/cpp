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

const i64 W = 30, N = 100010;

i64 pre[N][W][2];

i64 max_bits(i64 x) {
    for (i64 i = W; i >= 0; i--) {
        if ((x >> i) & 1)
            return i;
    }
    return -1;
}

void solve() {
    i64 n;
    cin >> n;

    vector<i64> a(n);

    for (auto &x : a)
        cin >> x;
    i64 xxor = 0;
    for (i64 i = 1; i <= n; i++) {
        xxor = xxor ^ a[i - 1];
        for (i64 j = 0; j <= 30; j ++) {
            pre[i][j][1] = pre[i - 1][j][1];
            pre[i][j][0] = pre[i - 1][j][0];
            if ((xxor >> j) & 1)
                pre[i][j][1] = pre[i][j][1] + 1;
            else
                pre[i][j][0] = pre[i][j][0] + 1;
        }
    }

    i64 ans = 0;

    for (i64 i = 1; i <= n; i++) {
        i64 x = max_bits(a[i - 1]);
        i64 left0, left1, right0, right1;

        left1 = pre[i - 1][x][1];
        left0 = pre[i - 1][x][0] + 1;
        right1 = pre[n][x][1] - left1;
        right0 = pre[n][x][0] - left0 + 1; // n - i + 1 -right1;

        
        ans += (left1 * right1 + left0 * right0);

    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);

    i64 t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
