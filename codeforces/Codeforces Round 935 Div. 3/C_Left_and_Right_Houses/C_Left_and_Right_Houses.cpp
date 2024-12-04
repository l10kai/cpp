/*
.______   ____    ____
|   _  \  \   \  /   /
|  |_)  |  \   \/   /
|   _  <    \_    _/
|  |_)  |     |  |
|______/      |__|
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#define mem(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(),x.end()
#define rall(v) v.rbegin(),v.rend()
#define sqa(x) ((x)*(x))
#define as static_cast
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define pii pair<int,int>
#define pll pair<i64,i64>

namespace MATH {
    template <typename T>
    T gcd(T a, T b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    template <typename T>
    T lcm(T a, T b) {
        return a / gcd(a, b) * b;
    }
    template <typename T>
    bool isprime(T n) {
        if (n <= 1) return false;
        for (T i = 2; i <= std::sqrt(n); i++)
        if (n % i == 0) return false;
        return true;
    }
}

using namespace MATH;
using namespace std;
using i64 = long long;

const int N = 300010;

int zero[N], one[N];

void solve(){   
    mem(zero ,0);
    mem(one, 0);

    i64 n;
    cin >> n;

    string str;
    cin >> str;
    
    str = " " + str;

    zero[0] = 0;
    one[0] =0;

    for(int i = 1; i <= n; i ++ ){
        if(str[i] == '0') zero[i] = zero[i - 1] + 1;
        else zero[i] = zero[i -1];

        if(str[i] == '1') one[i] = one[i - 1] + 1;
        else one[i] = one[i -1];

    }


    // int l = 0, r = n -1;
    // while(l < r){
    //     int mid = l + r + 1>> 1;
    //     if(i >=     ) l = mid;
    //     else r = mid - 1;
    // }
    i64 res = 0, sum  = 0x3f3f3f3f;
    for(int i = 0; i <= n; i ++ )
        if(2 * zero[i] >= i && 2 * (one[n] - one[i]) >= n - i){
            i64 tmp = llabs(n - 2 * i);
            if(tmp < sum){
                sum = tmp;
                res = i;
            }
    }

    // 左0右1

    //for(int i = 1;i<=n;i++) cout << We[i] <<" ";
    cout << res <<endl;
    //puts("");

}

signed main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
