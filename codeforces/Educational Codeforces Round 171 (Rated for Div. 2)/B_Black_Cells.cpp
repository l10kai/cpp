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

    vector<i64> a(n);

    for (auto &x : a) {
        cin >> x;
    }
    i64 ans = 1e18;
    if (n & 1) {
        for (int i = 0; i < n; i += 2) {
            i64 res = 0;
            for (int j = 0; j < n -1; j += 2) {
                if (i == j) {
                    j--;
                    continue;
                }
                res = max(res, a[j + 1] - a[j]);
            }
            ans = min(ans, res);
        }
    }

    else {
        i64 res = 0;
        for (int i = 1; i < n; i += 2) {
            res = max(res, a[i] - a[i - 1]);
        }
        ans = res;
    }

    cout << max(ans, 1ll) << ln;
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
