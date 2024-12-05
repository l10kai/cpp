#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

typedef pair<i64, i64> pll;
i64 N = 2e5 + 5;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> ans(N, -1);
    i64 idx = N - 5;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        while (t <= idx) {
            ans[idx] = i + 1;
            idx--;
        }
    }

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;

        cout << ans[t] << ln;
    }

    return 0;
}
