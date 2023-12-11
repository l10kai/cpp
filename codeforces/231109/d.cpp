#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n,m,k;

LL getsum(LL x,LL y){
if(y==0) return 0;
	if(y>=x-1) return x*(x-1)/2+y-(x-1);
	if(y<x-1) return (x-1+x-y)*y/2;

    return 0;
}

LL check(LL x){
    LL res;
    LL l=k-1,r=n-k;
    res= getsum(x,l)+getsum(x,r)+x;
    return res;
}

int erfen(){
    LL l=1,r=m;
    // while(l<r){
    //     LL mid=l+r+1>>1;

    //     if(check(mid)<=m) l=mid; //该题要用第二个模板

    //     else r=mid-1;
    // }

    while(l<r){
        LL mid =l+r>>1;
        if(check(mid)>=m) r=mid;
        else l=mid+1;
    }
    cout<<check(r)<<" ";
    return r;
}

int main(){

     cin>>n>>m>>k;
     cout<<erfen();                
    return 0;
}