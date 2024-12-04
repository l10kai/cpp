/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
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

int findCycleLength(const vector<int64_t> &b) {
    int n = b.size();
    vector<int> pi(n, 0);  // 前缀函数数组

    // 计算从b[1]开始的前缀函数
    for (int i = 2; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && b[j + 1] != b[i]) {
            j = pi[j];
        }
        if (b[j + 1] == b[i]) {
            j++;
        }
        pi[i] = j;
    }

    // 计算周期长度
    int cycleLength = n - pi[n - 1];  // 最小周期长度
    if (n % cycleLength == 0) {       // 检查是否存在完整周期
        return cycleLength;
    } else {
        return n;  // 否则返回数组长度，表示无完整周期
    }
}

void solve() {
    i64 x, n;
    // cin >> x >> n;
    cin >> x;
    const i64 C1 = pow(2, ceil(log2(x)));
    vector<i64> b(3e6 + 10);

    for (int i = 1; i <= 1e6 + 10; i++)
        b[i] = gcd(x, x ^ (x * i));

    auto get_c = [&]() {
        for (int i = 2; i <= 1e6 + 10; i++) {
            if (b[i] == b[1]) {
                i64 t = i, idx = 1;
                bool bl = false;

                while (idx < i) {
                    if (b[idx++] != b[t++]) {
                        bl = true;
                        break;
                    }
                }

                if (!bl) {
                    return i - 1;
                }
end:
            }
        }
        return -1;
    };
    i64 C = findCycleLength(b);

    vector<i64> a(C + 10);

    cout << "AC " << C1 << "wa " << C << ln;

    for (int i = 1; i <= C; i++) {
        a[i] += (b[i] == 1);
        a[i] += a[i - 1];
        // cout << gcd(x, x ^ (x * i)) << ln;
    }

    // for (int i = 1; i <= 3 * C; i++)
    //     cout <<gcd(x,( x ^ (x * i))) << ln;
    // cout << "C: " << C << ln;

    auto cal = [&](i64 x) {
        return (x / C) * a[C] + a[x % C];
    };

    while (n--) {
        i64 l, r;
        cin >> l >> r;

        cout << cal(r) - cal(l - 1) << ln;
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
