#include <bits/stdc++.h>
#include <ios>
#include <iostream>

using namespace std;

using i64 = int64_t;

const char &ln = '\n';

void solve() {
    i64 l, r, i, k;
    cin >> l >> r >> i >> k;

    auto get = [&](i64 x) {
        if (x % 4 == 0)
            return x;
        if (x % 4 == 1)
            return 1ll;
        if (x % 4 == 2)
            return x + 1;
        return 0ll;
    };

    auto f = [&](i64 l, i64 r) {
        return get(r) ^ get(l - 1);
    };

    i64 ans = f(l, r);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}