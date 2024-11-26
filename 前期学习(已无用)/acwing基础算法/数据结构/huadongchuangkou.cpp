//滑动窗口

//首先尝试暴力做法，即考虑普通队列，暴力枚举

#include <bits/stdc++.h>

using namespace std;


const int N=1e6+10;
int a[N],q[N];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];

    int hh,tt=-1;
    for(int i=0;i<n;i++){
        if(hh<=tt&&i-k+1>q[hh]) hh++;
        while(hh<=tt&&a[q[tt]>=a[i]]) tt--;  //队列存下标
        q[++tt]=i;

        if(i>=k-1) cout<<a[q[hh]]<<' ';
    }

puts("");


for(int i=0;i<n;i++){
    if(hh<=tt&&i-k+1>q[hh]) hh++;
    while (hh<=tt&&a[q[tt]]<=a[i]) tt--;
    q[++tt]=i;
    if(i>=k-1) printf("%d",a[q[hh]]);
}
puts("");
return 0;
}
