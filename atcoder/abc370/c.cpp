#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const char &ln = '\n';

signed main() {
    i64 n;
    cin >> n;

    vector<i64> a(n + 10);
    i64 t = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        i64 times = a[i] / 5;
        t += times * 3;
        a[i] -= times * 5;

        while (a[i] > 0) {
            t++;
            if (t % 3 == 0)
                a[i] -= 3;
            else
                a[i]--;
        }
    }

    cout << t << ln;

    return 0;
}
