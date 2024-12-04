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
#define mem(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(),x.end()
#define rall(v) v.rbegin(),v.rend()
#define sqr(x) ((x)*(x))
#define mod 998244353
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define pii pair<int,int>
#define pll pair<i64,i64>

namespace MATH {
    template <typename T>
    T gcd(T a, T b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    template <typename T>
    T lcm(T a, T b) {
        return a / gcd(a, b) * b;
    }
    template <typename T>
    bool isprime(T n) {
        if (n <= 1) return false;
        for (T i = 2; i <= std::sqrt(n); i++)
        if (n % i == 0) return false;
        return true;
    }
}

using namespace MATH;
using namespace std;
using i64 = long long;

vector<i64> pre(i64 n) {
    vector<i64> dig(n + 1, 0);

    for (i64 i = 1; i <= n; ++i) {
        dig[i] = dig[i / 10] + i % 10;
    }

    return dig;
}

i64 res(i64 n, const vector<i64>& dig) {
    i64 result = 0;
    for (i64 i = 1; i <= n; ++i) {
        result += dig[i];
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    i64 t;
    cin >> t;

    vector<i64> a(t);
    i64 max_a = 0;

    for (i64 i = 0; i < t; ++i) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }

    vector<i64> dig = pre(max_a);

    for (i64 i = 0; i < t; ++i) {
        cout << res(a[i], dig) << endl;
    }

    return 0;
}
