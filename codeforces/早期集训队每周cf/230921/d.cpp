#include <bits/stdc++.h>
 
using namespace std;
 
const int N=200010;
 
 
int n,k,t;
 
int main(){
    cin>>t;
    while(t--){
        char a[N];
        int sum=0;
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++){
            if(a[i]=='B'){
                i+=k-1;
                sum++;
            }
        }
       // cout<<a<<endl;
        cout<<sum<<endl;
    }
    return 0;
}