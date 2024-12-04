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
#define se        seconds
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

    vector<i64> a(n + 10), sorted_a(n + 10);
    vector<pll> ans;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sorted_a[i] = a[i];
    }

    sort(sorted_a.begin() + 1, sorted_a.begin() + n + 1);

    if (sorted_a == a) {
        cout << 0 << ln;
        return;
    }
    while (a != sorted_a)
        for (int i = 1; i <= n; i++) {
            i64 idx = -1;

            for (int j = i + 1; j <= n; j++) {
                if (a[j] < a[i])
                    idx = j;
            }

            if (idx == -1)
                continue;

            ans.push_back({i, idx});
            sort(a.begin() + i, a.begin() + idx + 1);

            if (sorted_a == a)
                break;

            // i = idx;
        }

    cout << ans.size() << ln;
    for (auto [x, y] : ans)
        cout << x << " " << y << ln;
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

// i64 minn = 1e18, min_idx = -1;
// for (int j = idx + 1; j <= n; j++) {
//     if (a[j] < minn) {
//         minn = a[j];
//         min_idx = j;
//     }
// }

// i64 t_idx = -1;
// for (int j = 1; j <= idx; j++) {
//     if (a[j] > minn) {
//         t_idx = j;
//         break;
//     }
// }

// if (t_idx != -1) {
//     i = min(t_idx, idx + 1);
// }
