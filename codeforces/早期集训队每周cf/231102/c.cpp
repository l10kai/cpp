#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string col="ROYGBIV";
    string col2="GBIV";
    cout<<col;
    n-=7;
    for(int i=0;n>0;i++){
        cout<<col2[i%4];
        n--;
    } 
    return 0;
}
