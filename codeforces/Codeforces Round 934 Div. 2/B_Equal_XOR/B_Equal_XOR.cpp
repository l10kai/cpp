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
#define pp pop_back
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

const int N = 200010;

int a[N];
bool bl[N];

void solve(){

    mem(a,false);

    int n, k;
    cin >> n >> k;

    vector<int> v1(n), v2(n), c, d, e;
    
    for(int i = 0; i < 2*n; i ++ ) cin >> a[i];

    for(int i  = 0, j = n; i < n; i ++ , j ++ ) v1[i] = a[i], v2[i]= a[j];

    sort(all(v1)),sort(all(v2));

    for(int i  = 0; i < n-1; i ++ ){
        if(v1[i] == v1[i + 1]){ c.pb(v1[i]),bl[v1[i]] = true;}
        if(v2[i] == v2[i + 1]){ d.pb(v2[i]),bl[v2[i]] = true;}
    }
    //cout << c.size()<<endl;

    if(2*c.size() >= 2*k){
        int t1 = 2*k, t2 = 2*k;
        for(auto &&v : c){
             if(t1){cout << v << " " << v <<" " ; t1-=2;}
             }
        cout << endl;
        for(auto &&v : d){
             if(t2){cout << v << " " << v <<" ";t2-=2;}
             }
        cout << endl; 
     }else
    {
        int num = 2*k - 2*c.size();

        for(int i = 1; i <= n; i ++ ){
            if(num && !bl[i]) e.pb(i),num--;
        }

        for(auto &&v : c){
             cout << v << " " << v <<" ";
             }
        for(auto &&ee : e) cout << ee <<" ";

        cout <<endl;

        for(auto &&v : d){
             cout << v << " " << v <<" ";
             }
        for(auto &&ee : e) cout << ee <<" ";

        cout <<endl;
    }
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


