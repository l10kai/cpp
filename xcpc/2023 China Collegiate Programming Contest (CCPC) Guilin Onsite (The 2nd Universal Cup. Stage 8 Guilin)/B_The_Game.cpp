/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <numeric>
#include <ranges>
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
    i64 n, m;
    cin >> n >> m;

    vector<i64> a(n), b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;

    sort(all(a));
    sort(all(b));
    i64 cot = 0;
    
    for (int i = 0; i < m; i++) {
        if (b[i] < a[n - m + i]) {
            cout << -1 << ln;
            return;
        }
        cot += b[i] - a[n - m + i];
    }

    priority_queue<i64, vector<i64>, greater<i64>> pq1, pq2;

    for (int i = 0; i < n - m; i++) {
        pq1.push(a[i]);
    }
    for (int i = n - m; i < n; i++) {
        pq2.push(a[i]);
    }
    vector<i64> ans;

    while (pq1.size() > cot && !pq1.empty()) {
        auto x = pq1.top();
        pq1.pop();
        ans.push_back(x);

        if (x + 1 > b[0]) {
            cout << -1 << ln;
            return;
        }

        if (pq1.empty()) {
            if (x + 1 > pq2.top()) {
                cot -= x + 1 - pq2.top();
                pq1.push(pq2.top());
                pq2.pop();
                pq2.push(x + 1);
                pq1.pop();
                continue;
            } else {
                continue;
            }
        }

        if (x + 1 > pq2.top()) {
            cot -= x + 1 - pq2.top();
            pq1.push(pq2.top());
            pq2.pop();
            pq2.push(x + 1);
            pq1.pop();

        } else {
            if (x + 1 <= pq1.top())
                continue;
            else {
                pq1.pop();
                pq1.push(x + 1);
                continue;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        auto x = pq2.top();
        pq2.pop();
        if (x > b[i]) {
            cout << -1 << ln;
            return;
        }

        for (int j = x; j < b[i]; j++) {
            ans.push_back(j);
            if (pq1.empty()) {
                cout << -1 << ln;
                return;
            }

            if (j >= pq1.top()) {
                pq1.pop();
            } else {
                cout << -1 << ln;
                return;
            }
        }
    }
    if (!pq1.empty()) {
        cout << -1 << ln;
        return;
    }
    cout << ans.size() << ln;
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << ln;
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
