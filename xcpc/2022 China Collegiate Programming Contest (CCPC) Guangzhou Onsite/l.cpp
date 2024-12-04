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
#define int       long long
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

constexpr i64 mod = 998244353;

i64 fpow(i64 a, i64 x) {
    i64 res = 1;
    while (x) {
        if (x & 1)
            res = res * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return res % mod;
}

const i64 M = 1e5;
i64 fac[M + 10], fnv[M + 10];

i64 C(i64 n, i64 m) {
    if (m < 0 || m > n)
        return 0;
    return fac[n] * fnv[m] % mod * fnv[n - m] % mod;
}  // c(n,m)
i64 A(i64 n, i64 m) {
    if (m < 0 || m > n)
        return 0;
    return fac[n] * fnv[m] % mod;
}  // a(n,m);


void solve() {
    i64 n, m;
    cin >> n >> m;
    // for (int i = c(n + 2, m - 1); i >= 1; i--)
    cout << C(n - 1, m - 1) * A(n, 1) % mod << ln;
    // cout << aa(5, 1) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    int t = 1;
    cin >> t;
    fac[0] = 1;
    for (int i = 1; i <= M; i++)
        fac[i] = fac[i - 1] * i % mod;
    fnv[M] = fpow(fac[M], mod - 2);
    for (int i = M; i >= 1; i--)
        fnv[i - 1] = fnv[i] * i % mod;
    assert(fnv[1] == 1);
    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
