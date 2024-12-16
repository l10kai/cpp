//离散化去重

// vector<int> alls;
// sort(alls.begin(),alls.end());
// alls.erase(unique(alls.begin(),alls.end()),alls.end());



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;

const int N=3e5+10;

int a[N],s[N]; 
int n,m;

vector<int>alls;//all函数存下标 
vector<PII> add,query;  //add函数存添加的数组

//查下标
int find (int x){

    int l=0,r=alls.size()-1;
    while (l<r){
        int mid =l+r>>1;
        if(alls[mid]>=x) r=mid;
        else l=mid+1;
    }
    return r+1;
}

int main(){

    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x,c;
        cin>>x,c;
        add.push_back({x,c});  

        alls.push_back(x);
    }

    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        query.push_back({l,r});

        alls.push_back(l);
        alls.push_back(r);
    }

//alls去重
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());

    for(auto item:add){
        int x=find(item.first);
        a[x]+=item.second;  //注意！有可能某一个下标被多次运用，即某一个坐标可能多次加C;
    }

    for(int i=1;i<=alls.size();i++) s[i]=s[i-1]+a[i];

    for(auto item:query){
        int l=find (item.first),r=find(item.second);
        cout<<s[r]-s[l-1]<<endl;
    }

    return 0;


}