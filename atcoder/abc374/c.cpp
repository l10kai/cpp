#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

signed main() {
    i64 n;
    cin >> n;
    i64 sum = 0;
    vector<i64> a(n);
    for (auto &x : a) {
        cin >> x;
        sum += x;
    }
    i64 ans = 1e18;
    vector<bool> vis(n);
    function<void(i64, i64)> dfs = [&](i64 x, i64 cot) {
        if (x == n) {
            ans = min(ans, max(cot, sum - cot));
            return;
        }

        dfs(x + 1, cot + a[x]);
        dfs(x + 1, cot);
    };
    dfs(0, 0);

    cout << ans << '\n';
}
