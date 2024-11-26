/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
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
#define pii       pair<int, int>
#define pll       pair<i64, i64>

// #define cin fin
// #define cout fout
// std::ifstream fin("E:/Cpp/duipai/in.txt");
// std::ofstream fout("E:/Cpp/duipai/out.txt");

using namespace std;
using f64 = double;
using i64 = long long;
using u64 = unsigned long long;
using f128 = long double;

const char &ln = '\n';

void solve() {
    i64 n;
    cin >> n;

    vector<i64> a(n + 10);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    i64 l = 1, r = n, ll = 1, rr = n;

    while (l <= r) {
        i64 len = r - l + 1;

        ll = max({ll, l - a[l] + 1, r - a[r] + 1});
        rr = min({rr, l + a[l] - 1, r + a[r] - 1});

        if (a[l] >= len && a[r] >= len) {
            l++;
            r--;
        } else if (a[l] >= len) {
            l++;
        } else if (a[r] >= len) {
            r--;
        } else {
            cout << 0 << ln;
            return;
        }
    }

    cout << max(0ll, rr - ll + 1) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
