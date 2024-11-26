#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

// bool check(long long x){
    
// }

LL gcd(LL a,LL b) {
    return b== 0?a:gcd(b,a%b);
}

int main(){
    LL a,b,x,y;
    cin>>a>>b>>x>>y;

    // int l= x*y,r = a*b;
    // while(l<r){
    //     int mid=l+r>>1;
    //     if(mid%(x*y)==0) l=mid;
    //     else r=   
    // }

    LL gcdd=gcd(x,y);
    x/=gcdd;
    y/=gcdd;

    LL aa=a/x;
    LL bb=b/y;

    LL minn=min(aa,bb);

    x*=minn;
    y*=minn; 

    cout<<x<<" "<<y;
}