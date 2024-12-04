#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const char &ln = '\n';

typedef pair<i64, i64> pll;

void solve() {
    i64 n, W;   
    cin >> n >> W;

    vector<i64> a(13);

    for(int i = 0; i < n; i ++ ) {
        i64 x;
        cin >> x;
        a[-- x] ++;
    }
}

int main() {
    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
