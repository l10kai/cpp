#include <bits/stdc++.h>
#include <cstring>

using namespace std;

const int N =100010;

int u[N];

int solve(){

    memset(u, 0, sizeof u);

    int n;
    cin >> n;

    n -= 1;
    while(n--){
        int a,b;
        cin >> a >> b;

        u[a]++,u[b]++;
    }
    int num = 0;
    for(int i = 0; i < N; i++){
        if(u[i] == 1) num ++;
    }

    return (num + 1) / 2;
}
int main(){

    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
    return 0;
}
