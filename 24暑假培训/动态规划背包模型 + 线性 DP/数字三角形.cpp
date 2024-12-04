#include <bits/stdc++.h>

using namespace std;

const char &ln = '\n';
const int N = 510;
int f[N][N];
int n;
/*
7
3 8
8 1 0
. . . .
. . . . .


*/

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> f[i][j];
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + f[i][j];
        }
    }
    cout << f[1][1] << ln;
}
