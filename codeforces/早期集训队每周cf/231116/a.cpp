#include <bits/stdc++.h>

using namespace std;


char t[26];
int main(){
    string a,b,c;
    cin>>a>>b>>c;
    
    for(int i=0;a[i];i++){
        t[a[i]-'A']++;
    }
    for(int i=0;b[i];i++){
        t[b[i]-'A']++;
    }
    for(int i=0;c[i];i++){
        t[c[i]-'A']--;
    }
    bool check=false;
    for(int i=0;i<26;i++){
        if(t[i]!=0){
            cout<<"NO"<<endl;
            check= true;
            break;
        }
    }
    if(!check) cout<<"YES"<<endl;

    return 0;
}