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
    i64 cnt1 = 0, cnt2 = 0;

    for (int i = 1; i <= n; i++) {
        i64 x;
        cin >> x;
        if (i & 1)
            cnt1 += x;
        else
            cnt2 += x;
    }

    if (n & 1) {
        if (cnt1 % (n / 2 + 1) != 0) {
            cout << "NO" << ln;
            return;
        }
        cnt1 /= (n / 2 + 1);
    } else {
        if (cnt1 % (n / 2) != 0) {
            cout << "NO" << ln;
            return;
        }
        cnt1 /= (n * 1 / 2);
    }

    if (cnt2 % (n / 2) != 0) {
        cout << "NO" << ln;
        return;
    }
    cnt2 /= (n / 2);

    if (cnt1 == cnt2) {
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
