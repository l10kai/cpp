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
#define mem(a, b) memset(a, b, sizeof(a))
#define all(x)    x.begin(), x.end()
#define rall(v)   v.rbegin(), v.rend()
#define lowbit(x) (x & (-x))

#define as  static_cast
#define fi  first
#define se  second
#define pb  push_back
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<i64, i64>

// #define cin fin
// #define cout fout
// std::ifstream fin("E:/Cpp/duipai/in.txt");
// std::ofstream fout("E:/Cpp/duipai/out.txt");

using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

void solve() {
    i64 n, m, L;
    cin >> n >> m >> L;

    vector<pll> blocks(n);
    map<int, vector<int>> add;

    for (auto &[l, r] : blocks) {
        cin >> l >> r;
        l--;
        r--;
    }

    for (int i = 0; i < m; i++) {
        int x, v;
        cin >> x >> v;
        add[x - 1].push_back(v);
    }
    i64 cap = 1, ans = 0;
    auto it = add.begin();
    priority_queue<i64> pq;
    for (auto [l, r] : blocks) {
        // for (int i = idx; i <= l; i++) {
        //     if (add.count(i))
        //         for (auto x : add[i]) {
        //             if (x > 0)
        //                 pq.push(x);
        //         }
        // }

        while (it != add.end() && it->fi <= l) {
            for (auto x : it->se) {
                if (x > 0)
                    pq.push(x);
            }
            it++;
        }

        if (cap >= r - l + 2) {
            continue;
        }

        while (cap < r - l + 2) {
            if (pq.empty()) {
                cout << -1 << ln;
                return;
            }
            cap += pq.top();
            ans++;
            pq.pop();
        }
    }

    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
