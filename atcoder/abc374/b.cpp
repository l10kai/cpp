#include <bits/stdc++.h>

using namespace std;

signed main() {
    string s, t;
    cin >> s >> t;

    for (int i = 0; i < min(s.size(), t.size()); i++) {
        if (s[i] != t[i]) {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    if (s != t) {
        cout << min(s.size(), t.size()) + 1 << '\n';
    } else {
        cout << 0 << '\n';
    }

    return 0;
}
