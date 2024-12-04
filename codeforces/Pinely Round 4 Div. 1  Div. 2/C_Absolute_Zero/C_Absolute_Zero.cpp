/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <queue>
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

    for (auto &x : a)
        cin >> x;

    //sort(rall(a));

    if (a.size() == 1 && a[0] == 0) {
        cout << ln;
        return;
    }

    if (a.size() == 1) {
        cout << 1 << ln;
        cout << a[0] << ln;
        return;
    }

    vector<i64> ans;
    i64 tmp = 0, de = 0;

    for (int i = 0; i < n - 1; i++) {
        a[i] = abs(a[i] - tmp);

        for (auto &x : ans) {
            a[i + 1] = abs(a[i + 1] - x);
        }

        if ((a[i] + a[i + 1]) % 2 != 0) {
            cout << -1 << ln;
            return;
        }

        tmp = (a[i] + a[i + 1]) / 2;
        // cout  <<"de: " << de << " "<< "tmp: " << tmp << ln << "a[i]: " <<
        // a[i]
        //      << " a[i + 1]: " << a[i + 1] << ln;
        de += tmp;
        if (tmp != 0)
            ans.pb(tmp);

        if (i == n - 2) {
            a[i + 1] = abs(a[i + 1] - tmp);
            if (a[i + 1] != 0)
                ans.pb(a[i + 1]);
        }
    }
    if(ans.size() > 40) {
        cout << -1 << ln;
        return;
    }
    cout << ans.size() << ln;
    for (auto x : ans)
        cout << x << " ";
    cout << ln;
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
