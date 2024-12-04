#include <bits/stdc++.h>

using namespace std;
using i64  = long long;
signed main() {
    i64 a, b, c;
    cin >> a >> b >> c;

    i64 ans = b;
    for(int i = 1; i <= a + 2; i ++) ans *= 3;
    //ans = b * powl(3, a + 2);

    if (c == 1) {
        if(ans % 100)
        ans = (ans/100 + 1) * 100;
        cout << ans * 3;
    } else {
        ans *= 4;
        if(ans % 100)
        ans = (ans / 100 + 1) * 100;
        cout << ans;
    }
}
