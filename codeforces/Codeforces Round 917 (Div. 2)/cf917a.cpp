#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve(){
    int n;
    cin >> n;
    vector<i64> v(n);
    for(int i = 0;i<n;i++) cin >> v[i];

    i64 sum = 1, minn =0x3f3f3f3f,iminn;

    for(int i = 0;i < n;i++){
        if(!v[i]) sum*=0;
        if(v[i]<0)sum *=-1;
        if(v[i]<minn) minn =v[i],iminn = i;
    }

    if(sum<=0) cout<<"0"<<endl;
    else{
        cout<<"1"<<endl<<iminn+1<<" 0"<<endl;
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
