
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6+10;


int b[N][30];

void solve1()
{
    int n, ans = 0;
    cin >> n;
    string a;
    cin >> a;
    set<char> st;
    for (int i = 0; i < n; i++)
    {
        if (st.count(a[i])) continue;
        ans += n - i; st.insert(a[i]);
    }
    cout << ans << '\n';
}

void solve2()
{
    int n, ans = 0;
    cin >> n;
    string a;
    cin >> a;
    set<char> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
        ans += (int) st.size();
    }
    cout << ans << '\n';
}

void solve3(){
    int n;
    string a;
     cin>>n>>a;
        a='1'+a;

        memset(b,0,sizeof b);

        for(int i=1;i<=n;i++){
            b[i][a[i]-'a']++;
            for(int j=0;j<=26;j++){
                b[i][j]+=b[i-1][j];
            }
        }
        ll ans=0;
        for(int i=n;i>=1;i--){
            for(int j=0;j<=26;j++){
                ans+=(b[i][j]?1:0);
            }
        }
        cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        solve();
    }

    return 0;

}
