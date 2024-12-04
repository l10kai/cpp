#include <bits/stdc++.h>

using namespace std;

signed main() {
    string str;
    cin >> str;

    cout << (str.substr(str.size() - 3) == "san" ? "Yes" : "No") << '\n';

    return 0;
}
