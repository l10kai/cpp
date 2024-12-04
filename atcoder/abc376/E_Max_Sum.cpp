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
    i64 n, k;
    cin >> n >> k;

    vector<pll> a(n);
    for (auto &[x, _] : a)
        cin >> x;
    for (auto &[_, y] : a)
        cin >> y;

    sort(all(a));

    i64 ans = 1e18;
    i64 sum = 0;
    priority_queue<i64> pq;

    for (int i = 0; i < k - 1; i++) {
        sum += a[i].se;
        pq.push(a[i].se);
    }

    for (int i = k - 1; i < n; i++) {
        pq.push(a[i].se);
        sum += a[i].se;
        ans = min(ans, sum * a[i].fi);
        sum -= pq.top();
        pq.pop();
    }

    cout << ans << ln;
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
