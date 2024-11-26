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

    vector<i64> a(n + 10);

    for (i64 i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<i64>> b(n + 10);

    for (i64 i = 2; i <= n; i++) {
        i64 x;
        cin >> x;
        b[x].pb(i);
    }

    function<i64(i64)> get_max = [&](i64 x) {
        if (b[x].empty()) {
            return a[x];
        }

        i64 minn = LLONG_MAX;
        for (auto &i : b[x]) {
            minn = min(minn, get_max(i));
        }
        if (a[x] >= minn)
            return minn;
        return (minn + a[x]) / 2;
    };
b
    i64 minn = LLONG_MAX;
    for (auto &x : b[1]) {
        minn = min(minn, get_max(x));
    }

    cout << minn + a[1] << ln;
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
