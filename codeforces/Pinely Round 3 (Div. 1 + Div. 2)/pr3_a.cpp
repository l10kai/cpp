#include <bits/stdc++.h>
#include <fstream>
#include <iterator>
#include <vector>
using namespace std;

#ifdef __linux__
using fout = cout;
using fin = cin;
#else
ifstream fin("a.in");
ofstream fout()

using PII = pair<int, int>;
using i64 = long long;
bool solve(){
    int n, m, p, k, t = (cin >> n >> m >> p >> k, 1);
    vector arr(n, 'a');
    for(int i = 0; i < arr.size(); ++i)
        cout << arr[i] << ' ';
    for(auto &&i : arr)
        cout << i << ' ';
    copy(arr.rbegin(), arr.rend(), ostream_iterator<int>(cout, " "));
    vector<PII> v(n),v2(n);


    for(int i = 0; i < n; i++){
        int l,r;
        cin >> l >> r;
        v[i] = {l,r};
        v2[i] = {r,l};
    }

    sort(v.begin(),v.end());
    if(v[0].first>=0) return true;
     if(v[n-1].first<=0) return true;

     sort(v2.begin(),v2.end());
    if(v2[0].first>=0) return true;
     if(v2[n-1].first<=0) return true;

     return false;
    // for(int i = 1; i< n; i++){
    //     if(v[i].second>v[i-1].second) return false;
    // }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve() ? cout<<"yes"<<endl:cout<<"No"<<endl;
    }
    return 0;
}
