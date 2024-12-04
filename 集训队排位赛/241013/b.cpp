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
    string str;
    cin >> str;
    if (str[0] == '0') {
        cout << str << ln;
        return;
    }

    else {
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == '0')
                str[i] = '1';
            else
                str[i] = '0';
        }

        for (int i = str.size() - 1; i >= 1; i--) {
            if (str[i] == '0') {
                str[i] = '1';
                for (int j = i + 1; j < str.size(); j++) {
                    str[j] = '0';
                }
                cout << str << ln;
                return;
            }
        }
    }
    cout << "00000000000000000000000000000000" << ln;

    return;
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
