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
using f128 = long double;

const char &ln = '\n';

void solve() {
    i64 n;
    cin >> n;

    vector<i64> a(n);

    for (int i = 0; i < n - 1; i++)
        cin >> a[i];

    if (n == 2) {
        cout << a[0] << " " << 2e30 << ln;
        return;
    }

    i64 cont = 0;
    for (int i = 0; i < n - 1; i++) {
        if ((a[i] & a[i + 1])) {
            cont++;
            cout << a[i] << " " << a[i + 1] << " " << (a[i] & a[i + 1]) << ln;
        }
    }

    cout << "count = " << cont << ln;
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
