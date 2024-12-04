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
    vector<i64> a(4);
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;

        if (s.size() == 1) {
            if (s[0] == 'A') {
                a[i] = 1;
            } else if (s[0] == 'J') {
                a[i] = 11;
            } else if (s[0] == 'Q') {
                a[i] = 12;
            } else if (s[0] == 'K') {
                a[i] = 13;
            } else {
                a[i] = s[0] - '0';
            }
        } else {
            a[i] = 10;
        }
    }

    sort(all(a));

    do {
        
    } while (next_permutation(all(a)));
    // for (int i = 0; i < 4; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << ln;
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
