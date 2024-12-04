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



void solve(){
    int n;cin>> n;

    vector<int> a(n+10);

    for(int i = 0;i<n;i++) cin>> a[i];


    bool check = true;
    for(int i = 1;i<n;i++){
        if(a[i] != a[i-1]) {check =false;break;}
    }
    if(check){ cout <<"0"<<endl;return ;}

    int cot1=0,cot2=0;
    for(int i = 0;i<n;i++){
        if(a[i] != a[0]) break;
        ++cot1;
    }
    for(int i = n-1;i>=0;i--){
        if(a[i] != a[n-1]) break;
        ++cot2;
    }

    if(a[0]==a[n-1]) cot1+=cot2;
    else cot1 = max(cot1,cot2);

    cout<<n-cot1<<endl;
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
