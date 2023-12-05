#include <bits/stdc++.h>

using namespace std;

const int N=510;


int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int a[N];
        for(int i=0;i<n;i++) cin>>a[i];

        int  minn=1e9;
        for(int i=1;i<n;i++){
            int tmp=a[i]-a[i-1];
            if(tmp<0){
                minn=-2;
                break;
            }
            minn=min(tmp,minn);
        }
        cout<<minn/2+1<<endl;
    }
    return 0;
}