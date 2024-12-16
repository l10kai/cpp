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

#define cin  fin
#define cout fout
std::ifstream fin("./in.txt");
std::ofstream fout("./out.txt");

using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

void solve() {
    string n;
    cin >> n;

    int f = 1;
    for (auto c : n) {
        int d = c - '0';
        int x = d * d;
        int nf = f << d;
        if (x < 10) {
            nf |= f << x;
        }
        nf |= nf >> 9;
        nf &= (1 << 9) - 1;
        f = nf;
    }

    if (f & 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
    fin.close();
    fout.close();
    return 0;
}
