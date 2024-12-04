#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const char &ln = '\n';

typedef pair<i64, i64> pll;

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<i64> a(n), pre_min_idx(n);
    for (auto &x: a) {
        cin >> x;
    }

    pre_min_idx[0] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] <= a[pre_min_idx[i - 1]]) {
            pre_min_idx[i] = i;
        } else {
            pre_min_idx[i] = pre_min_idx[i - 1];
        }
    }
    vector<pll> b(m);
    i64 precent_min_idx = 0;
    for (int i = 0; i < m; i++) {
        i64 r, x;
        cin >> r >> x;
        r--;

        b[i] = {r, x};
    }

    sort(b.begin(), b.end());

    for (auto [r, x]: b) {
        if (a[precent_min_idx] <= a[pre_min_idx[r]])
            a[precent_min_idx] -= x;
        else {
            a[pre_min_idx[r]] -= x;
            precent_min_idx = pre_min_idx[r];
        }
    }

    sort(a.begin(), a.end());

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i];
        cout << ans << " ";
    }
    cout << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
