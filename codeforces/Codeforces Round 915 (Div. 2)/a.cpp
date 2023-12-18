#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >>m;
        int ans = max(n,m);
        cout << ans <<endl;
    }
    return 0;
}
