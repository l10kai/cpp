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
const i64 inf = 1e18;
const i64 N = 1e6 + 10;
i64 primes[N], cnt;  // primes[]存储所有素数
bool st[N];          // st[x]存储x是否被筛掉

void get_primes(i64 n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

void solve() {
    i64 n;
    cin >> n;

    vector<i64> a(n);
    for (auto &x : a)
        cin >> x;

    vector<vector<i64>> dp(n, vector<i64>(4, inf));
    /*
    0 不变
    1 变奇
    2 变偶
    3 变1
    */
    dp[0][0] = 0;
    dp[0][1] = dp[0][2] = dp[0][3] = 1;
    for (int i = 1; i < n; i++) {
        // dp[i][0]转移
        if (!st[a[i - 1] + a[i]])
            dp[i][0] = dp[i - 1][0];
        if (a[i] & 1)
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (!(a[i] & 1))
            dp[i][0] = min(dp[i][0], dp[i - 1][2]);
        if (!st[a[i] + 1])
            dp[i][0] = min(dp[i][0], dp[i - 1][3]);

        // dp[i][1] 和dp[i][2]转移
        if (a[i - 1] & 1)
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
        else
            dp[i][2] = min(dp[i][2], dp[i - 1][0] + 1);
        dp[i][1] = min(dp[i][1], dp[i - 1][2] + 1);
        dp[i][1] = min(dp[i][1], dp[i - 1][3] + 1);
        dp[i][2] = min(dp[i][2], dp[i - 1][1] + 1);

        // dp[i][3]转移
        if (!st[a[i - 1] + 1] && a[i] != 1)
            dp[i][3] = min(dp[i][3], dp[i - 1][0] + 1);
        dp[i][3] = min(dp[i][3], dp[i - 1][1] + 1);
        if (a[i - 1] != 1)
            dp[i][3] = min(dp[i][3], dp[i - 1][3] + 1);
    }

    cout << *min_element(all(dp[n - 1])) << ln;
    cerr << st[2] << st[3] <<ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    get_primes(300000);
    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
