#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a(4);

    for (int i = 0; i < 4; i++) {
        int t;
        cin >> t;
        t--;
        a[t]++;
    }
    int ans = 0;
    for (auto x : a) {
        ans += x / 2;
    }

    cout << ans << ln;

    return 0;
}
