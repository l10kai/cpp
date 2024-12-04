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

bool onSegment(pll q, pll p1, pll p2) {
    auto [a, b] = q;
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    if ((a - x1) * (y2 - y1) == (x2 - x1) * (b - y1)  // 叉乘
                                                      // 保证Q点坐标在pi,pj之间
        && min(x1, x2) <= a && a <= max(x1, x2) && min(y1, y2) <= b &&
        b <= max(y1, y2))
        return true;
    else
        return false;
}

bool point_in_straight_line(pll q, pll p1, pll p2) {
    auto [a, b] = q;
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    if ((a - x1) * (y2 - y1) == (x2 - x1) * (b - y1))
        return true;
    else
        return false;
}

void solve() {
    i64 n;
    cin >> n;

    vector<pll> a(n), ans;

    for (auto &[l, r] : a)
        cin >> l >> r;

    if (n < 5) {
        cout << "NO" << ln;
        return;
    }

    ans.pb(a[0]);
    ans.pb(a[1]);
    pll m_point;
    bool bl = false;
    for (int i = 2; i < n; i++) {
        if (point_in_straight_line(a[i], ans[0], ans[1]) && !bl) {
            bl = true;
            m_point = a[i];
            continue;
        } else if (ans.size() < 4) {
            ans.pb(a[i]);
        }
    }
    if (bl)
        ans.pb(m_point);

    if (ans.size() < 5 || !bl) {
        cout << "1NO" << ln;
        return;
    }

    auto check = [&](i64 x) {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) {
                if (i != x && j != x && !onSegment(ans[x], ans[i], ans[j]))
                    return false;
            }

        return true;
    };

    for (int i = 0; i < ans.size(); i++) {
        if (check(i)) {
            cout << "YES" << ln;
            cout << ans[i].fi << " " << ans[i].se << ln;
            for (int j = 0; j < 5; j++) {
                if (j != i) {
                    cout << ans[j].fi << " " << ans[j].se << ln;
                }
            }

            return;
        }
    }

    cout << "NO" << ln;
    return;
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
    // cout << onSegment(7, 0, 0, 0, 10, 0) << ln;

    // fin.close();
    // fout.close();
    return 0;
}
