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
        string str;
        cin >> str;

        vector<int> a(str.size());

        for (int i = 0; i < str.size(); i++) {
            a[i] = str[i] - '0';
        }

        for (int i = 1; i < a.size(); i++) {
            if (a[i] == 0)
                continue;
            int now_idx = i, pre_idx = i - 1;
            while (pre_idx >= 0 && a[now_idx] > a[pre_idx] + 1 &&
                   a[now_idx] > 0) {
                a[now_idx]--;
                swap(a[pre_idx], a[now_idx]);
                now_idx = pre_idx;
                pre_idx--;
            }
        }
        for (auto x : a) {
            cout << x;
        }
        cout << ln;
    }

    return 0;
}
