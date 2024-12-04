#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

vector<pair<int, int>> num_move(int n, int from, int to, int ng) {
    vector<pair<int, int>> res;
    if (to != ng) {
        if (min(from, to) < ng and ng < max(from, to)) {
            res.emplace_back(n - abs(from - to), ng);
        } else {
            res.emplace_back(abs(from - to), ng);
        }
    }
    if (from < ng) {
        if (from < to and to <= ng) {
            res.emplace_back(n - (to - from) + (ng - to + 1), to - 1);
        }
        if (to < from or ng <= to) {
            res.emplace_back((to - from + n) % n + (to - ng + n) % n + 1,
                             (to + 1) % n);
        }
    } else {
        if (ng <= to and to < from) {
            res.emplace_back(n - (from - to) + (to - ng + 1), to + 1);
        }
        if (to <= ng or from < to) {
            res.emplace_back((from - to + n) % n + (ng - to + n) % n + 1,
                             (to - 1 + n) % n);
        }
    }
    return res;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector dp(q + 1, vector<int>(n, inf));
    int ph = 0, pt = 0;
    dp[0][1] = 0;
    for (int i = 0; i < q; i++) {
        char hc;
        int t;
        cin >> hc >> t;
        --t;
        int h = (hc == 'L' ? 0 : 1);
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == inf)
                continue;
            vector<int> pos(2);
            pos[ph] = pt;
            pos[ph ^ 1] = j;
            for (auto [num, npos] : num_move(n, pos[h], t, pos[h ^ 1])) {
                dp[i + 1][npos] = min(dp[i + 1][npos], dp[i][j] + num);
            }
        }
        ph = h, pt = t;
    }
    int ans = inf;
    for (int i = 0; i < n; i++)
        ans = min(ans, dp[q][i]);
    cout << ans << endl;
}
