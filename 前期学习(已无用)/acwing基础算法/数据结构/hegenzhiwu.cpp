//并查集

#include <bits/stdc++.h>

using namespace std;

const int N=1000010;

int a[N],t[N];

int find(int x){
    if(a[x]!=x) a[x]=find(a[x]);

    return a[x];
}

int main(){

    int m,n;
    cin>>m>>n;
    for(int i=1;i<=n*m;i++) a[i]=i;
    int res=m*n;;
    int k;
    cin>>k;
    while(k--){
        int l,r;
        cin>>l>>r;
        if(find(l)!=find(r)){
        res--;
        a[find(l)]=find(r);
        }
    }

    cout<<res;
    return 0;

}
