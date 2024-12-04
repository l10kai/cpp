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
#define lowbit(x) (x & (-x))
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
    string s, t;
    cin >> s >> t;

    s = " " + s;
    t = " " + t;

    bool bl = false;
    i64 idx = -1;
    for (int i = 1, j = 1; i < s.size(); i++, j++) {
        if (s[i] != t[j] && idx == -1) {
            idx = i;
            j++;
            continue;
        }
        if (s[i] != t[j] && idx != -1) {
            // cerr << i << " " << j << ln;
            cout << 0 << ln;
            return;
        }
    }

    // string ss = s.substr(1, idx - 1) + t[idx] + s.substr(idx);
    // i64 ii = -1;
    //  cout << ss << ln;
    // for (int i = idx - 1; i > 0; i--) {
    //     if (ss[i] != ss[idx - 1]) {
    //         break;
    //     } else {
    //         ii = i;
    //     }
    // }
    // // cout << idx << ii << ln;
    // cout << idx - ii << ln;

    // for (int i = ii; i < idx; i++) {
    //     cout << i << " " << ss[i] << ln;
    // }'
    if(idx == -1) idx = s.size();


    char c = t[idx];
    i64 ii = idx - 1;
    while (s[ii] == c && ii > 0) {
        ii--;
    }

    cout << idx - ii << ln;
    for (int i = ii; i < idx; i++) {
        cout << i << " " << c << ln;
    }
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
