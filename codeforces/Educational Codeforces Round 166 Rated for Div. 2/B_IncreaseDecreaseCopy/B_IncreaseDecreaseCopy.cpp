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
// std::ifstream fin("E:/Cpp/duipai/in.txt");
// std::ofstream fout("E:/Cpp/duipai/out.txt");

using namespace std;
using f64 = double;
using i64 = long long;
using f128 = long double;

const char &ln = '\n';

void solve() {
    i64 n;
    cin >> n;

    vector<i64> a(n), b(n + 1);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i <= n; i++)
        cin >> b[i];

    i64 maxx = 0x3f3f3f3f;
    i64 sum = 1;
    for (i64 i = 0; i < n; i++) {
        sum += abs(a[i] - b[i]);

        i64 tmp = max(a[i], b[i]), minn = min(a[i], b[i]);

        if (b[n] >= minn && b[n] <= tmp) {
            maxx = 0;
        } else if (b[n] > tmp) {
            maxx = min(maxx, abs(b[n] - tmp));
        } else {
            maxx = min(maxx, abs(minn - b[n]));
        }
    }

    cout << sum + maxx << ln;
    return;
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
