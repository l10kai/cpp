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
#define lowbit(x) x & -x
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

struct node {
    int l, r, id;
};

void solve() {
    i64 n, m;
    cin >> n >> m;
    // arr xor_sum, fenwick, answer
    vector<i64> a(n + 10), s1(n + 10), s2(n + 10), ans(m + 10);
    //queries
    vector<node> q(m);
    map<i64, i64> mp;

    for (i64 i = 1; i <= n; i++) {
        cin >> a[i];
        s1[i] = s1[i - 1] ^ a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }

    sort(all(q), [&](node x, node y) {
        return x.r < y.r;
    });

    auto add = [&](i64 x, i64 y) {
        for (; x <= n; x += lowbit(x)) {
            s2[x] ^= y;
        }
    };

    auto query = [&](i64 x) {
        i64 res = 0;
        for (; x; x -= lowbit(x)) {
            res ^= s2[x];
        }
        return res;
    };

    for (int i = 0, idx = 1; i < m; i++) {
        auto [l, r, pot] = q[i];

        while (idx <= r) {
            if (mp[a[idx]]) {
                add(mp[a[idx]], a[mp[a[idx]]]);
            }
            mp[a[idx]] = idx;
            add(idx, a[idx]);
            idx++;
        }

        ans[pot] = s1[r] ^ s1[l - 1] ^ query(r) ^ query(l - 1);
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << ln;
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
