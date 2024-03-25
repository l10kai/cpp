#include <bits/stdc++.h>

using namespace std;

const int N = 40010;

int p[N];
int n, m;

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int get(int x, int y){
    return x*n +y;
}

int main(){

    cin >> n >> m;

    for(int i = 0; i < n*n ; i ++ ) p[i] = i;

    for(int i = 1; i <= m; i ++ ){
        int l, r;
        char c;
        cin >> l >> r >> c;

        l -- , r -- ;

        int x = get(l,r);
        int y;
        if(c == 'D') y = get(l + 1, y);
        else y = get(l, y + 1);

        int px = find(x), py = find(y);

        if(px == py){
            cout << i <<endl;
            return 0;
        }

        p[px] = py;
    }

    cout << "draw" << endl;

    return 0;
}
