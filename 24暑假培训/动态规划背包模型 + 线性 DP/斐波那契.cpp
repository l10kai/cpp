 #include <bits/stdc++.h>

using namespace std;

const char &ln = '\n';

signed main() {
    int n;
    cin >> n;


    //爬楼梯问题：
    //有n阶楼梯，每次可以爬一层或两层，问： 一共有多少不同的爬法

    vector<int> f(n + 10);

    f[1] = 1;
    f[2] = 2;

    for(int i = 3; i <= n; i ++)
        f[i] = f[i - 1] + f[i - 2];

    cout << f[n] << ln;

    return 0;
}
