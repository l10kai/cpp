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

void solve() {
    i64 n;
    cin >> n;

    vector<i64> a(n), b(n - 1);

    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    sort(all(a));
    auto check = [&](i64 x) {
        auto c = b;
        c.push_back(x);
        sort(all(c));
        for (int i = 0; i < n; i++) {
            if (a[i] > c[i])
                return false;
        }

        return true;
    };

    i64 l = 1, r = 1e9 + 10;
    while (l < r) {
        i64 mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (r == 1e9 + 10)
        r = -1;
    cout << r << ln;
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
