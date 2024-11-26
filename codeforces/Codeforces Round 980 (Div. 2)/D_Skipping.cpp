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
    int n;
    cin >> n;
    vector<i64> a(n + 10), b(n + 10), s(n + 10);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<vector<pll> > v(n + 10);

    for (int i = 1; i <= n; i++) {
        if (i != 1)
            v[i].pb({i - 1, 0});
        v[i].pb({b[i], a[i]});
    }

    vector<i64> dis(n + 10, 1e18);
    auto dijkstra = [&](int s) {
        dis[s] = 0;
        priority_queue<pll, vector<pll>, greater<pll> > q;
        q.push({0, s});

        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();

            if (d != dis[u])
                continue;

            for (auto [v, w] : v[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }
        return;
    };

    dijkstra(1);
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, (s[i] - dis[i]));
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
