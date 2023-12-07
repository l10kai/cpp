#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;

        int a[25],maxx=0;

        memset(a,0, sizeof a);
        for(int i=0;i<n;i++) a[s[i]-'a']++;

        for(int i=0;i<25;i++) maxx=max(maxx,a[i]);

        if(maxx>n/2) cout<<(maxx-(n-maxx))<<endl;
        else if(n%2==0) cout<<"0"<<endl;
        else cout<<"1"<<endl;

    }

    return 0;
}
