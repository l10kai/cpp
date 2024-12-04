/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
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
using f64 = double;
using i64 = long long;
using f128 = long double;

const char &ln = '\n';

struct node {
    char x;
    i64 y;
    i64 z;
};

void solve() {
    string str;
    cin >> str;
    i64 n = str.size();

    vector<node> a(n);
    i64 num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            a[i].x = '(';
            num1++;
            a[i].y = num1;
            a[i].z = num2;
        } else {
            a[i].x = ')';
            num2++;
            a[i].y = num1;
            a[i].z = num2;
        }
    }
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].x == '(' && a[i].y != 1 && a[i].y != num1) {
            ans += 
        }

        if (a[i].x == ')' && a[i].z != 1 && a[i].z != num2) {}
    }
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
