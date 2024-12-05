#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

const int N = 200005;
int n, q;
int a[N];
int st[N][20];

void build(int n) {
    for (int i = 1; i < n; ++i)
        st[i][0] = abs(a[i + 1] - a[i]);

    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 1; i + (1 << j) - 1 < n; ++i)
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
    int k = log2(r - l + 1);
    return gcd(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        if (n > 1)
            build(n);

        while (q--) {
            int l, r;
            cin >> l >> r;
            if (l == r) {
                cout << 0 << " ";
            } else {
                int gcd = query(l, r - 1);
                cout << gcd << " ";
            }
        }
        cout << ln;
    }
    return 0;
}