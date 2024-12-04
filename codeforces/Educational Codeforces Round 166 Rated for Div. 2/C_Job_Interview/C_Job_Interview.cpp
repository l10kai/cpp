/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /
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
#define pii       pair<int, int>
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

struct node {
    i64 x, y, z;
};

void solve() {
    i64 n, m;
    cin >> n >> m;

    // vector<i64> ans(n + m + 1);
    vector<node> a(n + m + 1);

    for (int i = 0; i < n + m + 1; i++) {
        cin >> a[i].x;
    }
    for (int i = 0; i < n + m + 1; i++) {
        cin >> a[i].y;
    }
    i64 tmp_n = n + 1, tmp_m = m + 1;
    i64 sorce = 0;

    for (int i = 0; i < n + m + 1; i++) {
        if (tmp_n && a[i].x > a[i].y) {
            sorce += a[i].x;
            tmp_n--;
            a[i].z = 1;
        } else if (tmp_m) {
            sorce += a[i].y;
            tmp_m--;
            a[i].z = 2;
        } else {
            sorce += a[i].x;
            tmp_n--;
            a[i].z = 1;
        }
    }

    for (int i = 0; i < n + m + 1; i++) {
        if (a[i].z == 1 && tmp_n == 0) {
            cout << sorce - a[i].x;
        }
        if (a[i].z == 1 && tmp_n != 0) {
            cout << sorce - a[i].x - a[n + m].y + a[n + m].x;
        }

        if (a[i].z == 2 && tmp_m == 0) {
            cout << sorce - a[i].y;
        }
        if (a[i].z == 2 && tmp_m != 0) {
            cout << sorce - a[i].y - a[n + m].x + a[n + m].y;
        }
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
