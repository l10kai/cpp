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

const int N = 1e9 + 10;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<i64> a(k + 1), b(k + 1);  // 距离，时间

    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }

    while (q--) {
        i64 d;  // 距离
        cin >> d;

        i64 idx = lower_bound(all(a), d) - a.begin();

        if (d == a[idx]) {
            cout << b[idx] << " ";
            continue;
        }

        idx--;

        i64 ans =
            (d - a[idx]) * (b[idx + 1] - b[idx]) / (a[idx + 1] - a[idx]) +
            b[idx];
        cout << ans << " ";
    }
    cout << ln;
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
