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
    string str , str1;
    cin >> str;
    str1 = str;
    sort(str1.begin(), str1.end());

    if(str == str1){
        cout << "0" << ln;
        return;
    }

    i64 cnt = 0;

    i64 idx = 0;
    int n = str.size();

    while(str[idx] == '0' && idx < n) idx ++;
    //if(str[idx] != '0') idx --;

    i64 cot = 0;
    for(i64 i = idx; i < n; i ++ ) {
        if(str[i] == '0') {
            cot += i - idx + 1;
            idx ++;
        }
    }

    cout << cot << ln;

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
