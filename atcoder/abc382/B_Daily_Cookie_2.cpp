#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    i64 idx = n - 1;
    while (m--) {
        while (s[idx] == '.')
            idx--;
        s[idx] = '.';
        idx--;
    }

    cout << s << ln;

    return 0;
}
