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
#define lowbit(x) (x & (-x))
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

pll exgcd(i64 a, i64 b) {
    if (!b)
        return {1, 0};
    pll res = exgcd(b, a % b);
    return {res.se, res.fi - a / b * res.se};
}

void solve() {
    i64 x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    i64 x = x2 - x1, y = y2 - y1;
    bool bl1 = false, bl2 = false;
    if (x < 0) {
        x = -x;
        bl1 = true;
    }

    if (y < 0) {
        y = -y;
        bl2 = true;
    }

    auto [a, b] = exgcd(x, y);

    cout << a * (bl1 ? -1 : 1) + x1 << " " << -b * (bl1 ? -1 : 1) + y1 << ln;
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
