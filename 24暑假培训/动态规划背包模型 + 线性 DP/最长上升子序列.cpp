#include <bits/stdc++.h>
#include <climits>

using namespace std;

const char &ln = '\n';

signed main() {
    int n;
    cin >> n;

    vector<int> a(n + 10), f(n + 10, 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    /*
    o(N^2) 版
    */

    // for (int i = 1; i <= n; i++) {

    //     for (int j = 1; j <= i - 1; j++) {
    //         if (a[j] < a[i])

    //             f[i] = max(f[i], f[j] + 1);
    //     }
    // }
    // int maxx = 0;
    // for(int i = 0; i <n ; i ++) maxx = max(maxx, f[i]);










    vector<int> b(n + 10);
    b[0] = INT32_MIN;

    int len = 0;
    for (int i = 1; i <= n; i++) {


        int l = 0, r = len;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (b[mid] < a[i])
                l = mid;
            else
                r = mid - 1;
        }


        len = max(len, r + 1);
        b[r + 1] = a[i];
    }

    cout << len << ln;

    return 0;
}
