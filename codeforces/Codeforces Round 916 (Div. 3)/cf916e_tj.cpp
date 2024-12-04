#include <bits/stdc++.h>

using namespace std;

using i64 = long long ;
#define ALL(x) x.begin(), x.end()

struct node {i64 a, b, c, x;}; //a,b为数组,c为和,x为下标

bool cmp(node n1, node n2) {
    return n1.c > n2.c;
}

void Solved() {
    i64 n; cin >> n;
    vector<node> a(n);
    i64 res = 0;

    for(auto &i : a) cin >> i.a;
    for(auto &i : a) cin >> i.b;
    for(i64 i = 0; i < n; i ++ ) {
        a[i].c = a[i].a + a[i].b;
        a[i].x = i;
    }
    sort(ALL(a), cmp);

    for(i64 i = 0; i < n; i ++ ) {
        if((i + 1) & 1) {
            res += --a[i].a;

        } else {
            res -= --a[i].b;
        }
    }
//位运算写出来真好看
    // for(int i = 0; i < n; i++){
    //     (i + 1) & 1 ? res +=a[i].a,:res -= a[i].b;
    // }

    cout << res << endl;
}

int main() {
    i64 t;
    cin >> t;
    while(t--){
        Solved();
    }
    return 0;
}
