#include <bits./stdc++.h>

using namespace std;

const int N=200010;

int n,k,q;

int a[N],s[N];

int main(){

    cin>>n>>k>>q;
    
    while(n--){
        int l,r;
        cin>>l>>r;
        a[l]++;
        a[r+1]--;
    }

    for(int i=0;i<=N-10;i++) a[i]+=a[i-1];

    for(int i=0;i<=N-10;i++){
        if(a[i]>=k) a[i]=a[i-1]+1;
        else a[i]=a[i-1];
    }

    while(q--){
        int l,r;
        cin>>l>>r;

        cout<<a[r]-a[l-1]<<endl;
    }
    return 0;
}