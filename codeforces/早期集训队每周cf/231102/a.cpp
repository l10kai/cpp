#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

typedef pair<LL,LL> PLL;
const LL N =1e9+10;



int main(){
    int n;
    cin>>n;
     LL l,r;
    while(n--){
        int p;
        vector<PLL> a;
        cin>>p;
        LL ws,we;
        for(int i=0;i<p;i++){
           
            cin>>l>>r;
            a.push_back({l,r});
            if(i==0) ws=l,we=r;
        }
        int t=0;
        for(auto ite:a){
          
            if (t&&(ite.first>=ws)&&(ite.second>=we)){
                cout<<"-1"<<endl;
                goto lk;
            } 
           t++;
            
        }
        cout<<ws<<endl;
       // cout<<ws<<" "<<we<<endl;
   
        // for(auto ite:a){
        //     cout<<ite.first<<" "<<ite.second<<endl;
        // } 
        lk:;
    }
   
    return 0;
}