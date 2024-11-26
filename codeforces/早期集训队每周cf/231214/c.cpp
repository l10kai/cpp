#include <bits/stdc++.h>

using namespace std;

const int N =10;

char mp[N][N];

void solve(){
    getchar();
    //memset(mp,-1,sizeof mp);

    for(int i = 0;i<8 ;i++)
        for(int j = 0;j < 8; j++) cin >> mp[i][j];

    for(int i = 0;i<8 ;i++)
        for(int j = 0;j < 8; j++){
            if(mp[i+1][j+1]=='#' && mp[i-1][j-1]=='#' && mp[i+1][j-1]=='#' && mp[i-1][j+1]=='#'){
                cout << i+1 <<' '<<j+1 <<endl;
            }
        }
}
int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
