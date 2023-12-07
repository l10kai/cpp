#include <bits/stdc++.h>

using namespace std;

typedef pair<int ,int > PII;

// bool check(int x,vector<PII> v){
//     int l =0,r=0;

//     for(int i=0;i<v.size();i++){
//         if(l>v[i].second||r+x<v[i].second )return false;
//         else{
//             l=max(l,v[i].first),r=min(v[i].second,r+x);
//         }
//     }
//     return true;
// }

bool check(int k,vector<PII> v){
    int mn = 0, mx = 0;
    for(int i = 0; i < v.size(); i ++){
        mn = max(v[i].first, mn - k);
        mx = min(v[i].second, mx + k);
        if(mn > mx) return false;
    }
    return true;
}

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<PII> v;
        int rmax=0;
        for(int i=0;i<n;i++){
            int l,r;
            rmax=max(r,rmax);
            cin>>l>>r;
            v.push_back({l,r});
        }

        int l=0,r=1e9;
        while(l<r){
            int mid=l+r>>1;
            if(check(mid,v)) r=mid;
            else l=mid+1;
        }

        cout<<r<<endl;

    }

    return 0;
}
