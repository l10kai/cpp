#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const char &ln = '\n';

typedef pair<i64, i64> pll;

struct node {
    i64 x1, y1, x2, y2;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(n + 10, vector<char>(m + 10, 0));
    vector<pll> kangaroos;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '.') {
                kangaroos.push_back({i, j});
            }
        }

    for(int i = 0; i < kangaroos.size(); i ++) {
        for(int j = i + 1; j < kangaroos.size(); j ++) {
            
            auto [l, r] = kangaroos[i];
            auto [ll, rr] = kangaroos[j];

        }
    }
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