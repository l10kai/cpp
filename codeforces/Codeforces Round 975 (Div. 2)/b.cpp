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
    i64 n, q;
    cin >> n >> q;

    vector<i64> a(n);
    map<i64, i64> mp;

    for (auto &x : a)
        cin >> x;

    i64 lst = 1, nxt = n - 1;
    for (int i = 0; i < n - 1; i++) {
        mp[lst * nxt] += a[i + 1] - a[i] - 1;
        lst++;
        nxt--;
    }
    lst = 0, nxt = n - 1;
    for(int i = 0; i < n; i ++) {
        mp[lst * nxt + lst + nxt] += 1;
        lst ++;
        nxt --;
    }

    while (q--) {
        i64 x;
        cin >> x;
        cout << mp[x] << " ";
    }

    cout << ln;
    return ;
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
