
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
#define lowbit(x) (x & (-x))
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

void solve() {
    int n, q;
    cin >> n >> q;

    vector<i64> a(n + 10);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    string s;
    cin >> s;
    s = " " + s;
    vector<i64> d(n + 10, 0);
    auto add = [&](int l, int r, i64 x) {
        d[l] += x;
        d[r] -= x;
    };

    for (int i = 1; i <= n; i++) {
        i64 l = i, r = a[i];
        if (l > r)
            swap(l, r);
        add(l, r, 1);
    }

    for (int i = 2; i <= n; i++) {
        d[i] += d[i - 1];
    }

    set<i64> bad;
    for (int i = 1; i <= n - 1; i++) {
        if (s[i] == 'L' && s[i + 1] == 'R' && d[i])
            bad.insert(i);
    }

    while (q--) {
        i64 x;
        cin >> x;

        if (s[x] == 'L')
            s[x] = 'R';
        else
            s[x] = 'L';

        if (s[x - 1] == 'L' && s[x] == 'R' && d[x - 1])
            bad.insert(x - 1);
        else
            bad.erase(x - 1);

        if (s[x] == 'L' && s[x + 1] == 'R' && d[x])
            bad.insert(x);
        else
            bad.erase(x);

        if (bad.size())
            cout << "NO" << ln;
        else
            cout << "YES" << ln;
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
