#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const char &ln = '\n';

typedef pair<i64, i64> pll;

void solve() {
    i64 n, k;
    cin >> n >> k;

    bool flag = false;
    i64 x = 1, y = 1;

    map<pll, i64> mp;
    cout << 1 << " " << 1 << ln;
    mp[{1, 1}]++;
    for (int i = 1; i <= 2 * n - 2; i++) {
        if (flag == false) {
            x++;
            flag = true;
        } else {
            y++;
            flag = false;
        }
        mp[{x, y}]++;
        cout << x << " " << y << ln;
    }
    cout << 1 << " " << n << ln;
    mp[{1, n}]++;

    i64 cot = 2 * n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (cot == k) return;
            if (!mp[{i, j}]) {
                cout << i << " " << j << ln;
                cot++;
            }
        }
}

int main() {
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
