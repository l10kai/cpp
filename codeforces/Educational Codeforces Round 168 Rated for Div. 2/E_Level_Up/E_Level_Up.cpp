/*
根号分治练习
*/

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const char &ln = '\n';

const i64 N = 2e5 + 10, M = 450;

i64 n, q, p, k, B =448;
i64 a[N];
int sum[N][M];
bool ans[M][N];

inline void init() {
    for (int i = 1; i <= B; i++) {
        i64 lv = 1, ex = 0;
        for (int j = 1; j <= n; j++)
            if (lv <= a[j]) {
                ans[j][i] = true;
                ex++;
                if (ex == i) {
                    lv++;
                    ex = 0;
                }
            }
    }

    for (int j = 1; j <= B; j++) {
        for (int i = 1; i <= n; i++)
            sum[j][i] += sum[j - 1][i] + sum[j][i - 1] - sum[j - 1][i - 1];
    }
}

inline void solve() {
    cin >> p >> k;

    if (k <= B) {
        cout << (ans[p][k] ? "YES" : "NO") << ln;
        return;
    }

    for (int i = 1, lv = 1; i <= n;) {
        i64 l = i, r = n;
        while (l < r) {
            i64 mid = (l + r) >> 1;
            if ((mid - i + 1) - (sum[lv - 1][mid] - sum[lv - 1][i - 1]) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (i <= p && p <= r) {
            if (a[p] >= lv) {
                cout << "YES" << ln;
            } else {
                cout << "NO" << ln;
            }
            return;
        }

        i = l;
        lv++;
    }
    cout << "NO" << ln;
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    init();

    while (q--) {
        solve();
    }

    return 0;
}