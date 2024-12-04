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

    for(int i = 1; i <= n; i ++) {
        i64 num;
        cin >> num;
        for(int j = 0; j < num; j ++) {
            i64 t;
            cin >> t;
            a[i].push_back(t);
        }
    }
    i64 m;
    cin >> m;

    function<i64(i64)> dfs = [&](i64 idx) {
        i64 res = 0;
        if(a[idx].empty()) {
            return 1;
        }
        // if(cot == m) {
        //     cout << idx << ln;
        //     return ;
        // }
        // cout << x << " " << idx << " " << cot << ln;

        for(auto &i : a[idx]) {
            res += dfs(i);
        }
        res += 1;
        return res;
    };

    cout << dfs(n);

    return ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
