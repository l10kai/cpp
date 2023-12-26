#include <bits/stdc++.h>

using namespace std;

bool b[26];

void solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;

    memset(b,0,sizeof b);
    int res = 0;
    for(int i = 0; i < n; i++){
        if(!b[str[i]-'a']){
            res +=n-i;
        }
        b[str[i]-'a'] =1;
    }
    cout <<res<<endl;
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
