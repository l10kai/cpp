#include <bits/stdc++.h>

using namespace std;

const int N=10;

int a[N];
int t,n;
int sum;

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];

    sort(a,a+n);

    a[0]++;
    sum=1;
    for(int i=0;i<n;i++) sum*=a[i];

    cout<<sum<<endl;
    }
}