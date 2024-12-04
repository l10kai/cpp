/*
.______   ____    ____
|   _  \  \   \  /   /
|  |_)  |  \   \/   /
|   _  <    \_    _/
|  |_)  |     |  |
|______/      |__|
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

namespace MATH {
    template <typename T> T gcd(T a, T b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    template <typename T> T lcm(T a, T b) {
        return a / gcd(a, b) * b;
    }
    template <typename T> bool isprime(T n) {
        if (n <= 1)
            return false;
        for (T i = 2; i <= std::sqrt(n); i++)
            if (n % i == 0)
                return false;
        return true;
    }
}

using namespace MATH;
using namespace std;
using i64 = long long;
const char &ln = '\n';

void solve() {}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
