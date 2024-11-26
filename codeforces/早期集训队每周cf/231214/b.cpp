#include <bits/stdc++.h>

using namespace std;

const int N =10100;

int num[N];

void solve(){
    memset(num,0,sizeof num);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        int t;
        cin >> t;
        num[t]++;
    }
    int res = 0,tmp = 0;
    for(int i =0;i<N;i++){
        if(num[i]) res++;
        if(num[i]>1) tmp += num[i]-1;
    }

    if(tmp % 2==0) cout << res <<endl;
    else cout << res-1 <<endl;

}

int main(){

    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}
