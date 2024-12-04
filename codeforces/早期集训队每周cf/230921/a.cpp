#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--)
    {
    string a;
    cin>>a;
    if(a=="abc") cout<<"YES"<<endl;
    if(a=="acb") cout<<"YES"<<endl;
    if(a=="bac") cout<<"YES"<<endl;
    if(a=="bca") cout<<"NO"<<endl;
    if(a=="cab") cout<<"NO"<<endl;
    if(a=="cba") cout<<"YES"<<endl;
    }
    return 0;
}