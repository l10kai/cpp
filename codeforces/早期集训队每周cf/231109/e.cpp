#include <bits/stdc++.h>

using namespace std;

const int N=100010;
int a[N];
int n;

int main(){
    cin>>n;
    int i=n-1;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a[t]++;
    }
bool check=false;
    for(int i=0;i<N;i++)
        if(a[i]%2!=0){
            cout<<"Conan";
            check=true;
            break;
        }

    if(!check) cout<<"Agasa";

    return 0;
    }