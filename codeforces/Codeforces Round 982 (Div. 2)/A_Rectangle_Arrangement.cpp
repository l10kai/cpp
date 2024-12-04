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
        int n;
        cin >> n;

        int max_1 = -1, max_2 =-1;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;

            max_1 = max(max_1, a);
            max_2 = max(max_2, b);
        }

        cout << 2 * (max_1 + max_2) << ln;
    }

    return 0;
}
