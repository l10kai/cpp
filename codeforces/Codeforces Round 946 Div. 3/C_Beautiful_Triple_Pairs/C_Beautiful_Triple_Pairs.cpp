/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /
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
#define pii       pair<i64, i64>
#define pll       pair<i64, i64>

// #define cin fin
// #define cout fout
// std::ifstream fin("E:/Cpp/duipai/in.txt");
// std::ofstream fout("E:/Cpp/duipai/out.txt");

using namespace std;
using i64 = long long;
const char &ln = '\n';

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);

    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<pair<i64, i64>, i64> mp1, mp2, mp3;
    map<pair<pair<i64, i64>, i64>, i64> mp;

    for (i64 i = 0; i < n - 2; i++) {
        mp1[{a[i], a[i + 1]}]++;
        mp2[{a[i], a[i + 2]}]++;
        mp3[{a[i + 1], a[i + 2]}]++;

        mp[{{a[i], a[i + 1]}, a[i + 2]}]++;
    }
    i64 ans = 0;
    for (i64 i = 0; i < n - 2; i++) {
        i64 a1 = mp1[{a[i], a[i + 1]}] - mp[{{a[i], a[i + 1]}, a[i + 2]}];
        i64 a2 = mp2[{a[i], a[i + 2]}] - mp[{{a[i], a[i + 1]}, a[i + 2]}];
        i64 a3 = mp3[{a[i + 1], a[i + 2]}] - mp[{{a[i], a[i + 1]}, a[i + 2]}];

        ans += a1;ans += a2;ans += a3;
    }
    ans /= 2;
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    i64 t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
