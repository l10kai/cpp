/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <algorithm>
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
const i64 mod = 1000000007;
i64 fpow(i64 a, i64 x) {
    i64 res = 1;
    while (x) {
        if (x & 1)
            res = res * a % mod;

        a = a * a % mod;
        x >>= 1;
    }

    return res;
}

void solve() {
    i64 n, m;
    cin >> n >> m;

    vector<i64> a(n + 10), s1(n + 10), s2(n + 10);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s1[i] += (a[i] + s1[i - 1]) % mod;
    }

    for (int i = n; i >= 1; i--) {
        s2[i] = (s2[i + 1] + a[i]) % mod;
    }

    i64 sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++) {
        sum1 = (s1[i] + sum1) % mod;
        sum2 = (s2[i] + sum2) % mod;
    }

    i64 ans1 = (sum1 * fpow(2, m) % mod + n * s1[n] % mod * fpow(2, m - 1) %
                                              mod * (fpow(2, m) - 1) % mod) %
               mod;

    // cout << ans1 << ln;

    i64 tmp = (sum2 + sum1 + n * s1[n] % mod) % mod;

    i64 ans2 =
        (tmp * fpow(2, m - 1) % mod +
         n * s1[n] % mod * fpow(2, m) % mod * (fpow(2, m - 1) - 1) % mod) %
        mod;

    cout << max(ans1, ans2) << ln;
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
