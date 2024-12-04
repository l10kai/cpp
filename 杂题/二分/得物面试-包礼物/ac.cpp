#include <bits/stdc++.h>
#include <set>

using namespace std;

using i64 = long long;

const char &ln = '\n';

typedef pair<i64, i64> pll;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pll> a(n), b(n);

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    for (int i = 0; i < n; i++) {
        i64 x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        a[i] = {x1, y1};
        b[i] = {x2, y2};
    }

    auto check = [&](i64 x) {
        multiset<i64> ms;

        for (int i = 0, j = 0; i < n; i++) {
            auto [x1, y1] = a[i];
            while (j < n && b[j].first * x >= x1) {
                ms.insert(b[j].second * x);
                j++;
            }

            if (ms.empty() || ms.lower_bound(y1) == ms.end()) {
                return false;
            }

            ms.erase(ms.lower_bound(y1));
        }

        return true;
    };

    i64 l = 0, r = 1e9;

    while (l < r) {
        i64 mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << r << ln;

    return 0;
}
