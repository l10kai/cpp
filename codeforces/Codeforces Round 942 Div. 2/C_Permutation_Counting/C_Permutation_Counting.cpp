/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x)    x.begin(), x.end()
#define rall(v)   v.rbegin(), v.rend()
#define sqr(x)    ((x) * (x))
#define as        static_cast
#define fi        first
#define se        second
#define pb        push_back
#define ppb       pop_back
#define pii       pair<int, int>
#define pll       pair<i64, i64>

using namespace std;
using i64 = long long;
const char &ln = '\n';

void solve() {
    i64 n, k;
    cin >> n >> k;
    i64 kk = k;
    vector<i64> a(n);
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
    }

    priority_queue<i64, vector<i64>, greater<i64>> pq;
    
    for (i64 i = 0; i < n; i++) {
        pq.push(a[i]);
    }

    i64 in = 1;
    i64 minn = pq.top();
    pq.pop();

    while (k != 0 && !pq.empty()) {
        i64 x = pq.top();
        pq.pop();

        if (x > minn) {
            if ((x - minn) * in <= k) {
                k -= (x - minn) * in;
                minn = x;
                in++;
            } else {
                i64 tmp = k / in;
                minn += tmp;
               // k -= tmp * in;
                break;
            }
        } else if (x == minn) {
            in++;
        }
    }

    k = kk;
    i64 num = 0;
    for (i64 i = 0; i < n; i++) {
        if (a[i] < minn) {
            //a[i] = minn;
            k -= (minn - a[i]);
        }
        else if (a[i] > minn) {
            num++;
        }
    }

    num += k;

    cout << n * minn - (n - 1) + num << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);

    i64 t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
