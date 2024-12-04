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
#define pii       pair<int, int>
#define pll       pair<i64, i64>

using namespace std;
using i64 = long long;
const char &ln = '\n';
const i64 mod = 1e9 + 7;

void solve() {
    i64 a, b, n, x;
    cin >> a >> b >> n >> x;

    if (a == 1) {
        cout << (x + n % mod * b % mod) % mod << ln;
        return;
    }

    auto pw = [&](i64 a, i64 b) {
        i64 ans = 1, base = a;
        while (b) {
            if (b & 1) {
                ans = ans * base % mod;
            }
            base = base * base % mod;
            b >>= 1;
        }
        return ans;
    };

    i64 inv = pw(a - 1, mod - 2);
    i64 ans = (x * pw(a, n) % mod + b * (pw(a, n) - 1) % mod * inv % mod) % mod;

    cout << ans << ln;
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
    return 0;
}
