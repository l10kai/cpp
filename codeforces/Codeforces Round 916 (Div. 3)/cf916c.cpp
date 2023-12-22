#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int  a[N],b[N];

void solve(){

    memset (a,0,sizeof a);
    memset (b,0,sizeof b);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int mx = 0,res = 0,sum = 0;
    for(int i = 0; i < min(n,k); i++){
        sum += a[i];
        mx = max(mx,b[i]);
        res = max(res,sum + mx * (k - i - 1)); //i 从0开始遍历
    }

    cout << res << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
