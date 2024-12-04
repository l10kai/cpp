#include <bits/stdc++.h>

using namespace std;

const int N=10010;

int a[N];
int n;

int find(int x){
    if(a[x]!=x) a[x]=find(a[x]);
    return a[x];
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=i;
    int res=n;

    for(int i=1;i<=n;i++){
        int t;cin>>t;

        if(find(i)!=find(t)) a[find(i)]=find(t),res--;
    } 

    cout<<res;
    return 0;
}