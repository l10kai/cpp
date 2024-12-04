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
    int n;
    cin >> n;

    string s;
    cin >> s;
    bool ok = false;
    char cnt1 = '0', cnt2 = 'a';

    for (int i = 0; i < n; i++) {
        
        if (s[i] >= '1' && s[i] <= '9') {
            if (ok) {
                cout << "NO" << ln;
                return;
            }

            if (cnt1 > s[i]) {
                cout << "NO" << ln;
                return;
            }
            cnt1 = s[i];
        }

        if (s[i] >= 'a' && s[i] <= 'z') {
            ok = true;

            if (cnt2 > s[i]) {
                cout << "NO" << ln;
                return;
            }
            cnt2 = s[i];
        }
    }

    cout << "YES" << ln;
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
