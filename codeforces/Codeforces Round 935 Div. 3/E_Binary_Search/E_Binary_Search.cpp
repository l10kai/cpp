#include <bits/stdc++.h>

using namespace std;

// const int N = 200010;

// int a[N];

void sovle(){

    //memset(a, 0, sizeof a);

    int n, x, idx;
    cin >> n >> x;

    vector<int> a(n);

    for(int i = 0; i < n; i ++ ){
        cin >> a[i];
        if(a[i] == x) idx = i;
    }

    int l = 0, r = n;
    while(r - l != 1){
        int mid = l + r >> 1;

        if(a[mid] <= x) l = mid;
        else r = mid;
    }

    cout << "1" <<endl;
    cout << idx + 1 << " " << l + 1 <<endl;
}

int main(){
    bool bl{};
    int t;
    cin >> t;
    while(t --){
        sovle();
    }

    return 0;
}