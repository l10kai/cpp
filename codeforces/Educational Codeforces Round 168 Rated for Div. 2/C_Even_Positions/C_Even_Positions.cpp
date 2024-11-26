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
#define pii       pair<i64, i64>
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

i64 cal(const string &str) {
    stack<i64> s;
    i64 tot = 0;

    for (i64 i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            s.push(i);
        } else if (str[i] == ')') {
            if (!s.empty()) {
                i64 leftIndex = s.top();
                s.pop();
                tot += (i - leftIndex);
            }
        }
    }

    return tot;
}

void solve() {
    i64 n;
    cin >> n;
    vector<pll> cot(n);
    string str;
    cin >> str;

    // for (i64 i = 0; i < n; i++) {
    //     if (str[i] == '(')
    //         cot[i].first++;
    //     if (str[i] == ')')
    //         cot[i].second++;

    //     if (i != 0) {
    //         cot[i].first += cot[i - 1].first;
    //         cot[i].second += cot[i - 1].second;
    //     }
    // }
    i64 tmp = 1;
    str[0] = '(';
    for (i64 i = 1; i < n; i++) {
        if (str[i] == '(')
            tmp++;
        if (str[i] == ')')
            tmp--;
        if (str[i] == '_') {
            if (tmp > 0) {
                tmp--;
                str[i] = ')';
            } else {
                str[i] = '(';
                tmp++;
            }
        }
    }

    cout << cal(str) << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    i64 t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
