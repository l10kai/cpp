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
#define se        seconds
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
    string str;
    cin >> str;
    i64 n = str.size();

    if (n <= 2) {
        cout << "Yes" << ln;
        return;
    }
    i64 cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == ')')
            str[i] = '(';
        if (str[i] == ']')
            str[i] = '[';
    }
    i64 bl1 = 0, bl2 = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '(' && str[i + 1] == '(' && str[i + 2] == '(') {
            cout << "No" << ln;
            return;
        }

        if (str[i] == '[' && str[i + 1] == '[' && str[i + 2] == '[') {
            cout << "No" << ln;
            return;
        }
        if (str[i] == '(' && str[i + 1] == '(')
            bl1++;

        if (str[i] == '[' && str[i + 1] == '[')
            bl2++;
    }

    if (bl1 + bl2 >= 3) {
        cout << "No" << ln;
    } else {
        cout << "Yes" << ln;
    }
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
