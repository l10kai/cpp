#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    vector<int> a(n);
    for (auto &&i : a)
        cin >> i;
    sort(a.begin(), a.end());
    a.insert(a.begin(), 0);
    auto index{(long long)(ceil(n / 2.0))};
    cout << distance(a.begin() + index, upper_bound(a.begin(), a.end(), a[index])) << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}