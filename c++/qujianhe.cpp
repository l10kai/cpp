#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef pair<int,int> PII;


//区间合并

void merge(vector<PII>segs)
{
    vector<PII> res;

    sort(segs.begin(),segs.end());

    int st=-2e9,ed=-2e9;
    for(auto seg:segs)
        if(ed<seg.first){
            if(st!=-2e9) res.push_back({st,ed});
            st=seg.first,ed=seg.second;
        }
        else ed=max(ed,seg.second);下·

        if(st!=-2e9) res.push_back({st,ed});
        segs=res;
}

int main(){

    int n;
    scanf("%d",&n);

    vector<PII> segs;
    for(int i=0;i<n;i++){
        int l, r;
        cin>>l>>r;
        segs.push_back({l,r});
    }
    merge(segs);

   // cout<<segs.size()<<endl;
    printf("%d\n",segs.size());

    return 0;
}
