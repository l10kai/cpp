#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const char &ln = '\n';

void solve() {
    int n;
    cin >> n;

    map<i64, i64> mp;

    for (int i = 0; i < n; i++) {
        i64 x;
        cin >> x;
        mp[x]++;
    } 

    cout << n - max_element(mp.begin(), mp.end(),
                        [](const auto &a, const auto &b) {
                            return a.second < b.second;
                        })
                ->second
         << ln;
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}