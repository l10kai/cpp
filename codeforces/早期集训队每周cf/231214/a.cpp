#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int a[N],s[N];

int solve(){
    memset(a, 0, sizeof a);
    memset(s, 0, sizeof s);

    int n, ss;
    cin >> n >> ss;
    int len = N;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        s[i]=s[i-1]+a[i];
        if(s[i] == ss) len = i;
    }

    if(len == N) return -1;

    if(s[n] == ss) return 0;

    for(int i = 1;i<=n;i++){
        int l =i,r = n;

        while(l<r){

            int mid = l + r + 1 >> 1;
            if(s[mid]-s[i-1] <= ss) l=mid;
            else r =mid -1;

        }
        if(s[r]-s[i-1] == ss)
            len = max(len, r-i+1);
    }
        // for(int j = n;j>=i;j--)
        // if(s[j]-s[i-1] == ss){
        //     len = max(len, j-i+1);
        //     break;
        // }

    return n-len;

}

int main(){

    int t;
    cin >> t;

    while(t--){
        cout << solve() << endl;
    }
    return 0;
}
