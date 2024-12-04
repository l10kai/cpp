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
    int n;
    cin >> n;
    string str;
    cin >> str;

    vector<i64> s_to_i(n), a(n + 10);

    for (int i = 0; i < n; i++) {
        s_to_i[i] = str[i] - '0';
        // cerr << s_to_i[i] << " ";
    }

    auto add = [&](i64 l, i64 r, i64 x) {
        a[l] += x;
        a[r + 1] -= x;
    };

    for (int i = 0; i < n; i++) {
        add(i, n - 1, s_to_i[i] * (i + 1));
    }

    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }
    string ans;
    for (int i = n - 1; i >= 1; i--) {
        a[i - 1] += (a[i] / 10);
        a[i] %= 10;
        ans += a[i] + '0';
    }

    i64 tmp = 0;
    ans += a[0] % 10 + '0';
    tmp = a[0] / 10;

    while (tmp) {
        ans += tmp % 10 + '0';
        tmp /= 10;
    }

    reverse(all(ans));
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
