/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
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
    i64 n, m;
    cin >> n >> m;

    vector<pll> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i].fi;

    for (int i = 0; i < m; i++) {
        cin >> b[i].se;
    }

    // for(auto [l, r] : b) {
    //     cerr << l << " " << r << ln;
    // }

    // sort(all(b));
    if (b[0].fi != 1) {
        cout << -1 << ln;
        return;
    }

    i64 ans = 0;
    for (int i = 0; i < m; i++) {
        auto &[now_x, now_y] = b[i];
        i64 next_x = i == m - 1 ? n + 1 : b[i + 1].fi;

        if (next_x - now_x > now_y) {
            cerr << i << ln;
            cerr << next_x << " " << now_x << " " << now_y << ln;
            cout << -1 << ln;
            return;
        }

        // (now_y - 1) + ... + (now_y - (next_x - now_x ))
        // (2*now_y - (next_x - now_x + 1)) * (next_x - now_x) / 2
        ans += (2 * now_y - (next_x - now_x + 1)) * (next_x - now_x) / 2;

        if (i != m - 1) {
            b[i + 1].se += (now_y - (next_x - now_x));
        } else {
            if (now_y - (next_x - now_x)) {
                cout << -1 << ln;
                return;
            }
        }
        // cerr << ans<< ln;
    }
    cout << ans << ln;
}

//   4 0 1 0 0
//   1 3 1 0 0 3
//   1 1 3 0 0   2
//   1 1 1 2 0   2
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
