#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        int a[110];
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>a[i];

        int tem=1;
        for(int i=0;i<n;i++)
            if(k==a[i]){
                puts("Yes");
                tem=0;
                break;
            }
        if(tem) puts("No");
    }
    return 0;
}