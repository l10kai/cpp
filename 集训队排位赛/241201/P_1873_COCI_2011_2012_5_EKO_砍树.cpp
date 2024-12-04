/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <cstdio>
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
    int n, m;
    cin >> n >> m;

    vector<int> a(n);

    for (auto &x : a) {
        cin >> x;
    }

    i64 l = 0, r = 1e9;

    auto check = [&](i64 mid) {
        i64 sum = 0;
        for (auto x : a) {
            if (x > mid) {
                sum += x - mid;
            }
        }
        return sum >= m;
    };

    while (l < r) {
        i64 mid = l + r + 1 >> 1;

        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l << ln;
}

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
