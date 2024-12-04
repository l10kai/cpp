#include <bits/stdc++.h>

using namespace std;

int gcd_times(int a, int b) {
    int times = 0;
    while (b) {
        times += a / b;
        a %= b;
        swap(a, b);
    }
    return times;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    {
        int a, b;
        cin >> a >> b;
        cout << (gcd_times(a, b) & 1 ? "Stan wins" : "Ollie wins") << '\n';
    }
    return 0;
}