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
    string str;
    cin >> str;

    i64 n = str.size();

    if (str.size() == 1) {
        if (str[0] == 'a') {
            str += 'b';

        } else {
            str = "a" + str;
        }

        cout << str << ln;
        return;
    }
    string tmp;

    for (int i = 1; i < n; i++) {
        if (str[i] == str[i - 1] && str[i] == 'a') {
            tmp = str.substr(0, i) + 'b' + str.substr(i);
            cout << tmp <<ln;
            return;
        }

        if (str[i] == str[i - 1]) {
            tmp = str.substr(0, i) + 'a' + str.substr(i);
            cout << tmp << ln;
            return;
        }
    }

    // if (str[0] == str[1]) {
    //     if (str[0] == 'a') {
    //         tmp = string(1, str[0]) + 'b' + str.substr(1);
    //     } else {
    //         tmp = string(1, str[0]) + 'a' + str.substr(1);
    //     }
    // }

    // else {
    if (str[0] == 'a')
        tmp = "b" + str;

    else
        tmp = "a" + str;

    cout << tmp << ln;
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
