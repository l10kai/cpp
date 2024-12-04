/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <vector>
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

using namespace std;
using i64 = long long;
const char &ln = '\n';

const int N = 1e5 + 10;

void solve() {

    int n;
    cin >> n;

    vector<vector<int>> bits(n + 10,vector<int>(20));

    vector<int> a(n + 10);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < 20; j++) {
            bits[i + 1][j] = bits[i][j] + ((a[i] >> j) & 1);
        }
    }

    auto check_bits = [&](int a[], int b[]) {
        for (int i = 0; i < 20; i++) {
            if ((a[i] == 0 && b[i] != 0) || (a[i] != 0 && b[i] == 0)) {
                return false;
            }
        }
        return true;
    };

    auto check = [&](int len) {
        if(len == n) return true;

        for (int i = 1; i <= n - len; i++) {
            int b[20], c[20];
            for (int j = 0; j < 20; j++) {
                b[j] = bits[i + len][j] - bits[i][j];
            }
            for (int j = 0; j < 20; j++) {
                c[j] = bits[i + len + 1][j] - bits[i + 1][j];
            }

            if (!check_bits(b, c)) {
                return false;
            }
        }

        return true;
    };

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;

        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << r << ln;
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
    return 0;
}
