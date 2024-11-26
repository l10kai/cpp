#include <bits/stdc++.h>

using namespace std;

bool isprime(int num){
    if(num<2) return false;
    for(int i=2;i*i<=num;i++) {
        if(num%i==0) return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;

    int a[30001];
    int k=0;
    for(int i=1;i<n;i++){
        if(isprime(i)) a[i]++;
    }

    int res=0;
    for(int i=1;i<=n;i++){
    int t=0,chu;
    for(int j=2;j<i;j++){
        
        if(i%j!=0) continue;

        if(isprime(j)) t++;
    }
    if(t==2) res++;//,cout<<i<<" ";
    }
     cout<<res;
    // cout<<t<<" ";
    // if(t==2) cout<<"yes";
    
    return 0;
}

// int main(){
//     int t=0,chu;
//     for(int j=2;j<21/2;j++){
        
//         if(21%j==0) chu=21/j;
//         else continue;

//         if(isprime(j)) t++,cout<<" j "<< j;
//         if(isprime(chu)&&j!=chu) t++,cout<<" chu "<< chu;
//     }
// }