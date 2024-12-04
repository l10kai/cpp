/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <cstdio>
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
    i64 n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<i64> suffix_sum(n);
    suffix_sum[n - 1] = s[n - 1] == '1' ? 1 : -1;
    for (i64 i = n - 2; i >= 0; i--) {
        suffix_sum[i] = suffix_sum[i + 1] + (s[i] == '1' ? 1 : -1);
    }
    suffix_sum.erase(suffix_sum.begin());
    sort(rall(suffix_sum));
    i64 sum = 0;
    for (int i = 1; i < n; i++) {
        sum += suffix_sum[i - 1];
        if (sum >= k) {
            cout << i + 1 << ln;
            return;
        }
    }

    cout << -1 << ln;
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
