
#include <bits/stdc++.h>

using namespace std;

void solve(){
string str;cin >> str;

int a = 0;
for(int i = 0;str[i];i++){
    if(str[i] == 'A') a++;
}

if(a>=3) cout <<"A"<<endl;
else cout<< "B"<<endl;
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
