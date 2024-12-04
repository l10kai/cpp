#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10, M = 30010;

int dp[N], a[20];

void solve() {

    int n, W;
    cin >> n >> W;
    int len = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x - 1]++;
        len = max(len, x);
    }

    vector<vector<int>> v(1 << len);
    
    for (int i = 0; i < 1 << len; i++) {
        for (int j = 1; j < 1 << len; j++) {
            int temp = 0;
            int k = 0;
            for (k = 0; k < len; k++) {
                int x = (i >> k) & 1, y = (j >> k) & 1;
                if (y)
                    temp = temp + a[k];
                if (!x && y)
                    break;
            }
            if (k == len && temp <= W)
                v[i].push_back(j);
        }
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 0; i < 1 << len; i++) {
        for (auto j : v[i]) {
            dp[i] = min(dp[i], dp[i ^ j] + 1);
        }
    }
    cout << dp[(1 << len) - 1] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}