#include <bits/stdc++.h>

using namespace std;

const char &ln = '\n';

const int N = 1010;
int f[N][N];

int main() {
    int n, m;
    string a, b;
    cin >> n >> m;
    cin >> a >> b;

    a = " " + a;
    b = " " + b;
    // adasdfasdfasd
    //012345
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j])
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }

    cout << f[n][m] << ln;

    return 0;
}
