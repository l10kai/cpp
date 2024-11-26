#include <bits/stdc++.h>
using namespace std;

const char &ln = '\n';

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(n + 1, vector<char>(m + 1));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int ans = 0;
    for (int i = 1; i <= min(n, m) / 2; i++) {
        string s;

        for (int j = i; j <= m - i; j++)
            s += a[i][j];
        // cerr << "1: " << s << ln;
        for (int j = i; j <= n - i; j++)
            s += a[j][m - i + 1];

        for (int j = m - i + 1; j >= i + 1; j--)
            s += a[n - i + 1][j];

        for (int j = n - i + 1; j >= i + 1; j--)
            s += a[j][i];

        s += s;
        int cot = 0;
        // cerr << s << ln;
        for (int j = 0; j < s.size(); j++) {
            cot += s.substr(j, 4) == "1543";
        }
        ans += ceil(cot * 1.0 / 2.0);
    }

    cout << ans << ln;
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