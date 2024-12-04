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
}

using namespace MATH;
using namespace std;
using i64 = long long;

void solve(){
    int n,k,sum =1;
    cin >> n>> k;
    for(int i =0;i<n;i++){
        int t;
        cin >> t;
        sum*=t;
    }

    if(2023%sum!=0||sum>2023||sum == 0) cout <<"NO"<<endl;

    else{
        cout <<"YES"<<endl;

if(sum == 1){
 for(int i = 1;i<k;i++) cout << 1<<" ";
    cout <<"2023";
}
if(sum == 7){
 for(int i = 1;i<k;i++) cout << 1<<" ";
    cout <<"289";
}
if(sum ==17){
  for(int i = 1;i<k;i++) cout << 1<<" ";
    cout <<"119";
}
if(sum == 119){
 for(int i = 1;i<k;i++) cout << 1<<" ";
    cout <<"17";
}
if(sum ==289){
    for(int i = 1;i<k;i++) cout << 1<<" ";
    cout <<"7";
}
if(sum == 2023){
    for(int i = 0;i<k;i++) cout << 1<<" ";
    }
cout<<endl;
}

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
