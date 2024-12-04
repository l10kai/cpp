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
    string s;
    cin >> s;

    auto check = [&](string &s, i64 i) {
        if (i + 3 >= s.size() || i < 0)
            return false;
        return s.substr(i, 4) == "1100";
    };
    i64 cnt = 0;
    for (int i = 0; i < s.size() - 3; i++) {
        if (check(s, i))
            cnt++;
    }

    i64 q;
    cin >> q;
    while (q--) {
        i64 idx;
        char ch;
        cin >> idx >> ch;
        idx--;

        string old_s = s;
        s[idx] = ch;

        i64 old_range_cnt = 0, now_range_cnt = 0;
        for (int i = idx - 3; i <= idx; i++) {
            old_range_cnt += check(old_s, i);
            now_range_cnt += check(s, i);
        }

        cnt += now_range_cnt - old_range_cnt;

        cout << (cnt > 0 ? "YES" : "NO") << ln;
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
