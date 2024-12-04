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
    i64 n, k;
    cin >> n >> k;

    vector<i64> a(n + 10);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (a[n] >= a[n - 1]) {
        cout << "Python will never be faster than C++" << ln;
        return;
    }

    i64 old = a[n - 1], neww = a[n], cot = 0;

    while (neww >= k) {
        i64 tmp = 2 * neww - old;
        old = neww;
        neww = tmp;
        cot++;
        if (cot >= 1e5 + 100) {
            cout << "Python will never be faster than C++" << ln;
            return;
        }
    }

    cout << "Python 3." << (cot + n) << " will be faster than C++" << ln;
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
