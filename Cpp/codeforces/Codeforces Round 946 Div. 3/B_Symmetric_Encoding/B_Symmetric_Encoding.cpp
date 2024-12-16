/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <iterator>
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x)    x.begin(), x.end()
#define rall(v)   v.rbegin(), v.rend()
#define sqr(x)    ((x) * (x))
#define as        static_cast
#define fi        first
#define se        second
#define pb        push_back
#define ppb       pop_back
#define pii       pair<int, int>
#define pll       pair<i64, i64>

// #define cin fin
// #define cout fout
// std::ifstream fin("E:/Cpp/duipai/in.txt");
// std::ofstream fout("E:/Cpp/duipai/out.txt");

using namespace std;
using i64 = long long;
const char &ln = '\n';

void solve() {
    int n;
    string s;
    set<char> st;
    map<char, char> mp;

    cin >> n;

    cin >> s;
    
    for (int i = 0; i < n; i++) {
        st.emplace(s[i]);
    }

    string str(st.begin(), st.end());

    n = str.size();

    for (int i = 0; i < n >> 1; i++) {
        mp[str[i]] = str[n - i - 1];
        mp[str[n - i - 1]] = str[i];
    }
    for (auto x : s) {
        if (!mp.count(x) && x >= 'a' && x <= 'z') {
            cout << x;
        } else
            cout << mp[x];
    }

    cout << ln;

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
