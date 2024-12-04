#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;

vector<PII> a,b; //a菜谱，b咖啡
int n,k,q;

int main(){
    cin>>n>>k>>q;
    while(n--){
        int l,r;
        cin>>l>>r;
        a.push_back({l,r});
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        b.push_back({l,r});
    }

    for(auto bb :b){
        int res=0;
        int s[200010]={0};

        for(auto aa :a){
           int l= max(aa.first,bb.first),r= min(aa.second,bb.second);

            for(int i=l;i<=r;i++) s[i]++;
        }

        for(int i=0;i<=200000;i++)
             if(s[i]==k) res++; 
        
        cout<<res<<endl;
    }
return 0;
}