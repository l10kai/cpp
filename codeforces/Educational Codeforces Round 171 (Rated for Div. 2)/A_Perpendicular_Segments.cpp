#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;
        if (x > y) {
            swap(x, y);
        }
        cout << 0 << " " << 0 << " " << x << " " << x << ln;
        cout << 0 << " " << x << " " << x << " " << 0 << ln;
    }
    return 0;
}
