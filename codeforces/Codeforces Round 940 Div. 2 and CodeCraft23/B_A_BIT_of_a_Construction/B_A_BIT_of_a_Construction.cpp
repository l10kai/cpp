/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <iostream>
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


int counts(int num) {
    int count = 0;
    while (num != 0) {
        if (num & 1) {
            count++;
        }
        num >>= 1;
    }
    return count;
}


int cbits(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num >>= 1;
    }
    return count;
}
int maxx(int bits) {
    int x = (1 << bits) - 1;
    return x;
}
void solve() {
    int n, k;
    cin >> k >> n;

    if(k == 1) {
        cout << n << ln;
        return ;
    }
    k --;
    int num = cbits(n);

    if(n != maxx(num)) {
        cout << maxx(num - 1) << " ";
        cout << n - maxx(num - 1) << " ";
        k--;
        while(k --) cout << 0 << " ";
    } else {
        cout << n << " ";
        
        while(k --) cout << 0 << " ";
    }


    cout << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
