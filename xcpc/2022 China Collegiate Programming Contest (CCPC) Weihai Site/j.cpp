/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
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

    vector<i64> a(n);
    map<i64, i64> mp;
    multiset<i64> st;
    // priority_queue<i64, vector<i64>, greater<i64>> pq;

    // map<i64, i64> mp;

    for (auto &x : a) {
        cin >> x;
    }
    st.insert(0);
    st.insert(1e18);
    // pq.push(0);
    for (int i = 0; i < k; i++) {
        i64 x, y;
        cin >> x >> y;

        if (y == 0)
            // mp[x] = 1;
            st.insert(x + 1);
        // pq.push(x + 1);
        else
            mp[x] = y;
    }

    // sort(all(a));
    i64 sum = 0, y = 0;
    for (auto x : a) {
        // while (!pq.empty() && pq.top() <= x) {
        //     y = pq.top();
        //     pq.pop();
        // }
        auto it = st.upper_bound(x);
        it--;

        i64 y = *it;
        // st.erase(it);
        sum += (x - y);

        mp[y]--;
        if (mp[y] == 0) {
            st.insert(y + 1);
            // pq.push(y + 1);
        }
    }

    cout << (sum & 1 ? "Pico" : "FuuFuu") << ln;
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
