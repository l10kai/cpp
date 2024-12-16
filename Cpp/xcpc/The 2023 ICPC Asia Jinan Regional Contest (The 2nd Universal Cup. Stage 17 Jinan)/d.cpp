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
#define se        seconds
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

i64 cal(i64 x) {
    i64 res = 0;
    while (x) {
        i64 mod = x % 10;
        res = max(mod, res);
        x /= 10;
    }
    return res;
}
void solve() {
    i64 la, ra, lb, rb;
    cin >> la >> ra >> lb >> rb;

    if (ra - la + rb - lb > 10) {
        cout << 9 << ln;
    } else {
        i64 ans = 0;

        for (int i = la; i <= ra; i++)
            for (int j = lb; j <= rb; j++)
                ans = max(ans, cal(j + i));

        cout << ans << ln;
    }
   // cout << "OK" <<ln;
    return;
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
