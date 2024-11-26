#include <bits/stdc++.h>

using namespace std;

int main(){
    string a,res;
    cin>>a;
    for(auto aa:a){
        auto loww =tolower(aa);

        if(loww!='a'&&loww!='e'&&loww!='i'&&loww!='o'&&loww!='u'&&loww!='y'){
            res+='.';
            res+=loww;
        }
    }
    cout<<res;
    return 0;
}