/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <iostream>
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
const int a[] = {1, 2, 2, 3, 3,  4,  4,  5,  5,  1,  6,  6, 7, 7,
                 8, 8, 9, 9, 10, 10, 11, 11, 13, 12, 12, 1, 13};
void solve() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        for (int i = 1; i <= n / 2; i++) {
            cout << i << " " << i << " ";
        }
        cout << ln;
    } else if (n < 27)
        cout << -1 << ln;
    else {
        for (auto i : a)
            cout << i << " ";
        for (int i = 1; i <= (n - 27) / 2; i++) {
            cout << i + 13 << " " << i + 13 << " ";
        }
        cout << ln;
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
