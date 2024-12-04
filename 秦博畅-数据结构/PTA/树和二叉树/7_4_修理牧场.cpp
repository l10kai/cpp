#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        pq.push(x);
    }
    i64 ans = 0;
    while (pq.size() > 1) {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();

        ans += x + y;
        pq.push(x + y);
    }
    cout << ans << ln;
    return 0;
}
