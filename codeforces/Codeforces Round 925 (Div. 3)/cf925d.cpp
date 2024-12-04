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
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e5+10;
map<PII,int>mp;
int a[N];
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        ll x,y;cin>>x>>y;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            mp[{a[i]%x,a[i]%y}]++;
        }
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            mp[{a[i]%x,a[i]%y}]--;
            ans+=mp[{(x-a[i]%x)%x,a[i]%y}];
        }
        cout<<ans<<endl;
    }
    return 0;
}
