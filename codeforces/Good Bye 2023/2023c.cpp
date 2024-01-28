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
}

using namespace MATH;
using namespace std;
using i64 = long long;

const int N =100010;

int a[N],s[N],j[N],o[N];

void solve(){
    mem(a,0);
    mem(s,0);
    mem(j,0);
    mem(o,0);

    int n;
    cin >> n;

    for(int i = 1;i<=n;i++){
        cin >>a[i],s[i]=a[i]+s[i-1];
        if(a[i]%2) j[i]=j[i-1]+1,o[i]=o[i-1];
        else o[i]=o[i-1]+1,j[i]=j[i-1] ;
        }
        cout<<s[1]<<" ";
    for(int i = 2;i<=n;i++){
        if(j[i]%4==0) cout<<s[i]-2*(j[i]/4)<<" ";
        else if(s[i]%2) cout<<s[i]-1<<" ";
        else cout<<s[i]<<" ";
    }
    cout<<endl;
}

int main(){

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
