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

const int N =20;

char a[N][N];

bool check(int num) {
    if (num <= 3) {
        return false;
    }

    int sqrtNum = sqrt(num);
    return sqrtNum * sqrtNum == num;
}

void solve(){
    for(int i = 0;i<N ;i++)
        for(int j = 0;j<N;j++){
            a[i][j] = '0';
        }


    int n;cin >> n;
        int sum=0;
    for(int i = 0;i<n ;i++)
        for(int j = 0;j<n;j++){
            cin >> a[i][j];
            if(a[i][j] == '1') sum ++;
        }

if(!check(sum)){
    cout << "TRIANGLE"<<endl;
    return;
}
 int x = sqrt(sum);
int a1 ,b1;

    for(int i = 0;i<n ;i++)
        for(int j = 0;j<n;j++)
            if(a[i][j] == '1'){
                a1 = i,b1 = j;goto bb;
        }

bb:
   cout <<"a1= "<<a1<<" "<<"b1= "<<b1<<endl;
    for(int i = a1;i<a1+x;i++)
        for(int j =b1;j<b1+x;j++){
            if(a[i][j] =='0'){ cout << "TRIANGLE"<<endl;return;}
        }
 cout<<"SQUARE"<<endl;


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
