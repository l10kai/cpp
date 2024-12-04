/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <iterator>
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
    int n;
    cin >> n;

    vector<i64> a(n), b;
    for (auto &x : a)
        cin >> x;

    stack<i64> sta;

    for (auto x : a) {
        while (!sta.empty() && x < sta.top()) {
            b.pb(sta.top() + 1);
            sta.pop();
        }
        sta.push(x);
    }

    sort(all(b));

    while (!b.empty() && sta.top() > b[0]) {
        b.pb(sta.top() + 1);
        sta.pop();
    }

    vector<i64> ans;
    for (auto x : b) {
        ans.pb(x);
    }
    while (!sta.empty()) {
        ans.pb(sta.top());
        sta.pop();
    }
    sort(all(ans));
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << ln;
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
