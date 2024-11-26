#include <bits/stdc++.h>
#define cout cout.flush()
using namespace std;

using namespace std;

void solve() {
    int n;
    cin >> n;

    string s(n, '?');
    vector<int> a(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        cout << "? " << 1 << " " << i << endl;
        cin >> a[i];
    }

    if (a[n] == 0) {
        cout << "! IMPOSSIBLE" << endl;
        return;
    }
    int idx = -1;
    for (int i = 2; i <= n; i++) {
        if (a[i] != 0) {
            // cerr << i << " " << a[i] << endl;
            for (int j = 0; j < i - 1 - a[i]; j++)
                s[j] = '1';

            for (int j = i - 1 - a[i]; j < i - 1; j++)
                s[j] = '0';

            s[i - 1] = '1';
            idx = i;
            break;
        }
    }

    // for (int i = 2; i <= n; i++) {
    //     cerr << "i " << i << " a[i] " << a[i] << endl;
    // }

    for (int i = idx + 1; i <= n; i++) {
        if (a[i] > a[i - 1]) {
            s[i - 1] = '1';
        } else {
            s[i - 1] = '0';
        }
    }

    cout << "! " << s << endl;
}

signed main() {
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}