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
#include <vector>
#define mem(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(),x.end()
#define rall(v) v.rbegin(),v.rend()
#define sqr(x) ((x)*(x))
#define mod 998244353
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define pii pair<i64,i64>
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

const int N = 200010;

int v[N];

void solve(){

mem(v,0);

    i64 n;
    i64 f,a,b;

    v[0] =0;
    cin >> n >> f >> a >> b;

    for(i64 i = 1;i<= n;i++ ) cin >> v[i];


    for(i64 i =1 ;i<=n;i++){
    f-=min(b,a*(v[i]-v[i-1]));
        if(f<= 0 ){
            cout <<"NO"<<endl;
            return ;
        }
    }

    cout <<"YES"<<endl;

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    i64 t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
