#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    int n;cin>>n;
    vector<int> a(n);
    for(auto &it:a)cin>>it;
    int p=0,f=0;
    for(int i=0;i<n;++i){
        if(a[i]>a[(i+1)%n]){
            f++;
            p=i+1;
        }
    }

    int ans=1e9+10;
    if(f==0){
        ans=0;
    }else if(f==1){
        ans=min(p+2,n-p);
    }
    p=0,f=0;
    for(int i=0;i<n;++i){
        if(a[i]<a[(i+1)%n]){
            f++;
            p=i+1;
        }
    }
    if(f==0){
        ans=0;
    }else if(f==1){
        ans=min(ans,min(p+1,n-p+1));
    }
    if(ans==1e9+10)cout<<"-1\n";
    else
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
