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
    double x1, y1, x2, y2;
};

void solve() {
    double n, s, t;
    cin >> n >> s >> t;

    vector<node> a(n);
    vector<i64> b(n);
    vector<i64> vis(n, false);

    f128 ans = 0;
    for (int i = 0; i < n; i++) {
        b[i] = i;
    }
    for (auto &[x1, y1, x2, y2] : a) {
        cin >> x1 >> y1 >> x2 >> y2;
        ans += hypotl(x1 - x2, y1 - y2) / s;
    }
    do {
        
    } while (next_permutation(all(b)));
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