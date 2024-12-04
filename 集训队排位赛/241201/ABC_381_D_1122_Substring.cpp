#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1), f(n + 1);
    map<int, int> mp;
    for (auto &x : a) {
        cin >> x;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[i + 1]) {
            f[i + 1] = min(f[i - 1] + 2, i + 1 - mp[a[i]]);
        }
        mp[a[i]] = i;
        ans = max(ans, f[i + 1]);
    }
    cout << ans << ln;
    return 0;
}
