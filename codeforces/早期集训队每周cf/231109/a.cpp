#include<bits/stdc++.h>

using namespace std;

int check(string a,string b){

    if(a==b) return 0;
    
    else if(a.size()==b.size()){
        for(int i=0;i<a.size();i++){
            if(a[i]<b[i]) return -1;
            if(a[i]>b[i]) return 1;
        }
    }

    else{
        for(int i=0;i<a.size()||i<b.size();i++){
            if(a[i]<b[i]) return -1;
            if(a[i]>b[i]) return 1;
        }
    }

}

int main(){
    string a,b,c;

    cin>>a;
    cin>>b;
    for(int i=0;a[i];i++){
        if(a[i]>='A'&&a[i]<='Z') a[i]+=32;
    }
    for(int i=0;b[i];i++){
        if(b[i]>='A'&&b[i]<='Z') b[i]+=32;
    }

    cout<<check(a,b);
    return 0;
}