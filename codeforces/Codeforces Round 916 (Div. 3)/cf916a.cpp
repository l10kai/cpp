#include <bits/stdc++.h>
#include <cstring>

using namespace std;

const int N = 27;

int a[N];

void solve(){
    memset(a,0,sizeof a);

    int n;
    string str;

    cin >> n >> str;
    int ans = 0;

    for(int i =0 ;str[i];i++){
        a[str[i]-'A'] ++;
    }
    for(int i=0;i<n;i++){
        if(a[i]>= i + 1) ans ++;
    }

    cout << ans <<endl;
}



int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
