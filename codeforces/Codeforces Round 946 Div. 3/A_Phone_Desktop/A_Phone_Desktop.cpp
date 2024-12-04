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
#define pii       pair<int, int>
#define pll       pair<i64, i64>

// #define cin fin
// #define cout fout
//std::ifstream fin("E:/Cpp/duipai/in.txt");
//std::ofstream fout("E:/Cpp/duipai/out.txt");

using namespace std;
using i64 = long long;
const char &ln = '\n';

void solve() {
    double x, y;
    cin >> x >> y;

    double ans = 0;

    i64 tmp = y/2, mod = (i64)y%2;
    ans += tmp + mod;
    
    if(ceil(((double)x -( tmp * 7 + mod * 11))/15) > 0) {
    ans += ceil((x - ( tmp * 7 + mod * 11))/15);
    }
    cout << ans << ln;
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
