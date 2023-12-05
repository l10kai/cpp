#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;
int a[N],b[N];

int main(){
    
    int t;cin>>t;
    while(t--){
        
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);

        int n;cin>>n;
        
        for(int i=0;i<n;i++) cin>>a[i];

        int maxx=0;
        for(int i=n-1;i>=0;i--){
            maxx=max(maxx,a[i]);
            if(maxx) b[i]=1,maxx--;
        }
        
        for(int i=0;i<n;i++) cout<<b[i]<<" ";
        puts("");
    }

    return 0;

}