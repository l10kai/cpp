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

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<bool> mp(1e6 + 20, 0);

    for (int i = 0; i < n; i++) {
        i64 x;
        cin >> x;
        mp[x] = 1;
    }

    i64 ak, bk;
    ak = k;
    bk = k;

    for (int i = 0; (i <= 1e6 + 10) && (bk || ak); i++) {
        if (!mp[i] && !(i & 1) && bk) {
            mp[i] = 1;
            bk--;
        }
        if (!mp[i] && (i & 1) && ak) {
            mp[i] = 1;
            ak--;
        }
    }

    for (int i = 0; i <= 1e6 + 10; i++) {
        if (!mp[i]) {
            if (i & 1) {
                cout << "Bob" << ln;

            } else {
                cout << "Alice" << ln;
            }
            return;
        }
    }

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
    // fin.close();
    // fout.close();
    return 0;
}
