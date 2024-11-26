#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n,c;

LL cal(LL c){
    return c*(3*c+1)/2;
}

int main(){
    LL res=0;
    cin>>n;
    for(LL i=1;cal(i)<=n;i++){
        if((n-cal(i))%3==0) res++;
    }

    cout<<res;
    return 0;
}