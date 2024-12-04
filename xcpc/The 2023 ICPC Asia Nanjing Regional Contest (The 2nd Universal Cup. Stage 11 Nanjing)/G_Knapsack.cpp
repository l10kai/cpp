#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const char &ln = '\n';

typedef pair<i64, i64> pll;

void solve() {
    i64 n, W, k;
    cin >> n >> W >> k;

    vector<pll> a(n);

    for (auto &[w, v] : a)
        cin >> w >> v;

    sort(a.begin(), a.end());

    priority_queue<i64, vector<i64>, greater<i64>> pq;
    vector<i64> free_zone(n + 1);
    i64 sum_v = 0;
    for (int i = n - 1; i > 0; i--) {
        sum_v += a[i].second;
        pq.push(a[i].second);
        while (pq.size() > k) {
            sum_v -= pq.top();
            pq.pop();
        }

        free_zone[i] = sum_v;
    }
    free_zone[n] = 0;
    vector<i64> dp(W + 10, 0);
    i64 ans = 0;
    for (auto i = 0; i < n; i++)
        for (auto j = W; j >= a[i].first; j--) {
            dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);
            ans = max(ans, dp[j] + free_zone[i + 1]);
        }


    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}