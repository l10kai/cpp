
#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define fi     first
#define se     second
#define pb     push_back
#define pll    pair<i64, i64>

using namespace std;
using i64 = long long;
const char &ln = '\n';

void solve() {
    i64 n, m, q;
    cin >> n >> m >> q;

    vector<pll> a(q), mp;
    vector<i64> dp(q + 10), path(q + 10);

    for (int i = 1; i <= q + 2; i++) {
        path[i] = i;
    }

    for (auto &[l, r] : a)
        cin >> l >> r;
    a.pb({1, 1});
    a.pb({n, m});
    sort(all(a));

    i64 len = 0, lst = -1;
    for (int i = 0; i < a.size(); i++) {
        auto [la, ra] = a[i];
        i64 l = 0, r = len;

        while (l < r) {
            i64 mid = (l + r + 1) >> 1;
            if (a[dp[mid]].se <= ra)
                l = mid;
            else
                r = mid - 1;
        }
        path[i] = dp[r];

        if (r + 1 >= len) {
            lst = i;
        }
        len = max(len, r + 1);
        dp[r + 1] = i;
    }
    cout << len - 2 << ln;
    i64 tmp = len;
    while (tmp--) {
        mp.pb(a[lst]);
        lst = path[lst];
    }
    reverse(all(mp));

    for (auto i = 0ull; i < mp.size() - 1; i++) {
        auto [l1, r1] = mp[i];
        auto [l2, r2] = mp[i + 1];

        cout << string(l2 - l1, 'D') << string(r2 - r1, 'R');
    }

    return;
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
