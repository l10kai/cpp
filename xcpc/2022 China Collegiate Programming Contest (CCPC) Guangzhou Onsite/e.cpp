/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <vector>
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
    i64 n, m;
    cin >> n >> m;

    vector<i64> p(n + 10), ans(n + 10);
    vector<pll> a(n + 10);

    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }

    sort(a.begin() + 1, a.begin() + n + 1);

    auto add = [&](i64 x, i64 y, vector<i64> &p) {
        for (; x <= n; x += lowbit(x))
            p[x] += y;
    };

    auto query = [&](i64 x, vector<i64> &p) {
        int ans = 0;
        for (; x; x -= lowbit(x))
            ans += p[x];
        return ans;
    };

    i64 sum = 0;

    for (int i = 1; i <= n; i++) {
        ans[a[i].se] = query(a[i].se, p) + (i - 1) * a[i].fi - sum;
        add(a[i].se, 1, p);
        sum += a[i].fi;
    }

    for (int i = 1; i <= n; i++) {
        cout << (ans[i] > (m - 2) ? -1 : ans[i]) << ln;
    }
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
