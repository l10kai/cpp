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
using f128 = long double;

const char &ln = '\n';

void solve() {
    i64 n;
    cin >> n;

    vector<i64> a(n + 10), b(n + 10);

    i64 tmp = 1e18, count = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        b[i] = a[i] - a[i - 1];

        if (tmp == b[i]) {
            count++;
        } else {
            ans += count * (count + 1) / 2;
            count = 1;
            tmp = b[i];
        }
    }

    if (count) {
       // cout << count << ln;
        ans += count * (count + 1) / 2;
    }
    cout << ans + n << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
