/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
#define all(x)    x.begin(), x.end()
#define rall(v)   v.rbegin(), v.rend()
#define lowbit(x) (x & (-x))

#define as  static_cast
#define fi  first
#define se  second
#define pb  push_back
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<i64, i64>

// #define cin fin
// #define cout fout
// std::ifstream fin("E:/Cpp/duipai/in.txt");
// std::ofstream fout("E:/Cpp/duipai/out.txt");

using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

void solve() {
    string str;
    cin >> str;
    vector<int> v;
    for (auto ch : str) {
        if (ch != '-') {
            if (ch == 'X') {
                v.push_back(10);
            } else {
                v.push_back(ch - '0');
            }
        }
    }
    i64 sum = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        sum += (v[i]) * (i + 1);
    }

    if (sum % 11 == v.back()) {
        cout << "Right" << ln;
    } else {
        if (sum % 11 == 10) {
            str.back() = 'X';
        } else {
            str.back() = sum % 11 + '0';
        }
        cout << str << ln;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
