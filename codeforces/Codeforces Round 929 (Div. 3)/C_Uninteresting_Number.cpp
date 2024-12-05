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

    i64 sum = 0;
    i64 add_2 = 0, add_6 = 0;
    for (auto &x : str) {
        sum += x - '0';

        if (x == '2')
            add_2++;
        if (x == '3')
            add_6++;
    }

    if (sum % 9 == 0) {
        cout << "YES" << ln;
        return;
    }
    auto check = [&](int x, int y, int z) {
        int rem = (9 - z % 9) % 9;

        for (int b = 0; b <= min(y, 8); ++b) {
            int a = (5 * rem - 3 * b + 9) % 9;
            if (a >= 0 && a <= x) {
                return true;
            }
        }
        return false;
    };

    if (check(add_2, add_6, sum)) {
        cout << "YES" << ln;
    } else {
        cout << "NO" << ln;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
