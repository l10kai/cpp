#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 10);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = (n - k + 1); i <= n; i++)
        cout << a[i] << ' ';

    for (int i = 1; i <= (n - k); i++)
        cout << a[i] << ' ';
    return 0;
}
