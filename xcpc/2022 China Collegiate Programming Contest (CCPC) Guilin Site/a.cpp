/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <functional>
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
    map<string, i64> mp;
    for (int i = 0; i < 5 * n; i++) {
        string str;
        cin >> str;

        mp[str]++;
    }

    i64 m;
    cin >> m;
    vector<i64> a(7), b(7);
    for (int i = 0; i < m; i++) {
        string str;
        i64 t;
        cin >> str >> t;
        b[t]++;
        a[t] += mp.count(str);
    }

    i64 cp_sum = 0, minn = 1e18;
    for (int i = 1; i <= 5; i++) {
        cp_sum += a[i];
        minn = min(b[i], minn);
    }

    cout << min(minn, cp_sum) << ln;
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
