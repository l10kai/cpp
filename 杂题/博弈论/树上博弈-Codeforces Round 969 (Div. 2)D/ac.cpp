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

void solve() {
    i64 n;
    cin >> n;

    vector<vector<i64>> a(n + 10);
    vector<char> ch(n + 10);
    for (int i = 0; i < n - 1; i++) {
        int u, v;

        cin >> u >> v;

        a[u].pb(v);
        a[v].pb(u);
    }

    i64 uknown = 0;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (c == '?')
            uknown++;
        ch[i] = c;
    }
    i64 lefe_one = 0, lefe_zero = 0, lefe_uk = 0;

    for (int i = 2; i <= n; i++) {
        if (a[i].size() == 1) {
            lefe_one += (ch[i] == '1');
            lefe_zero += (ch[i] == '0');
            lefe_uk += (ch[i] == '?');
        }
    }

    i64 ans = 0;

    if (ch[1] == '1') {
        ans = lefe_zero;
    } else if (ch[1] == '0') {
        ans = lefe_one;

    }

    else {
        ans = max(lefe_one, lefe_zero);

        i64 un_lefe_uk = uknown - 1 - lefe_uk;

        if (lefe_zero == lefe_one && (un_lefe_uk & 1) && un_lefe_uk > 0)
            lefe_uk++;
        lefe_uk--;
    }

    cout << ans + (lefe_uk + 1) / 2 << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        // Solved()    ;
    }
    // fin.close();
    // fout.close();
    return 0;
}
