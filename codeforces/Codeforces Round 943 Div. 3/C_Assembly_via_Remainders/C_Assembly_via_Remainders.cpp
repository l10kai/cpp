/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x)    x.begin(), x.end()
#define rall(v)   v.rbegin(), v.rend()
#define sqr(x)    ((x) * (x))
#define as        static_cast
#define fi        first
#define se        second
#define pb        push_back
#define ppb       pop_back
#define pii       pair<i64, i64>
#define pll       pair<i64, i64>

using namespace std;
using i64 = long long;
const char &ln = '\n';



void solve() {
    i64 x;
    cin >> x;
    vector<i64> a(x - 1);
    i64 maxx = 0;
    for (auto &&c : a) {
        cin >> c;
        maxx = max(maxx, c);
    }
    vector<i64> b;
    b.pb(max(maxx + 1, 2ll));

    for (i64 i = 0; i < x - 1; i++) {
        b.pb(b.back() + a[i]);
    }
    for (auto x : b)
        cout << x << " ";
    cout << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    i64 t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
