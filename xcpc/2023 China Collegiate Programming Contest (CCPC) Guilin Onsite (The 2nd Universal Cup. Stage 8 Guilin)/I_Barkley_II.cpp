/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <cstring>
#include <unordered_map>
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x)    x.begin(), x.end()
#define rall(v)   v.rbegin(), v.rend()
#define sqr(x)    ((x) * (x))
#define lowbit(x) (x & (-x))
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
using u64 = unsigned long long;
using f128 = long double;

const char &ln = '\n';

template <typename type> inline void read(type &x) {
    x = 0;
    bool flag(0);
    char ch = getchar();
    while (!isdigit(ch))
        flag = ch == '-', ch = getchar();
    while (isdigit(ch))
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    flag ? x = -x : 0;
}

template <typename type>
inline void write(type x, bool mode = 1)  // 0为空格，1为换行
{
    x < 0 ? x = -x, putchar('-') : 0;
    static short Stack[50], top(0);
    do
        Stack[++top] = x % 10, x /= 10;
    while (x);
    while (top)
        putchar(Stack[top--] | 48);
    mode ? putchar('\n') : putchar(' ');
}

struct node {
    i64 l, r, x;
};

const int N = 5e5 + 10;

i64 a[N];
node p[2 * N];

unordered_map<i64, i64> st, mp;
void solve() {
    int n, m;

    read(n);
    read(m);

    i64 p_size = 0;

    for (int i = 1; i <= n; i++) {
        read(a[i]);
        if (st[a[i]] + 1 <= i - 1)
            p[p_size++] = {st[a[i]] + 1, i - 1, a[i]};
        st[a[i]] = i;
    }

    for (int i = 1; i <= m; i++) {
        if (st[i] + 1 <= n)
            p[p_size++] = {st[i] + 1, n, i};
    }

    sort(p, p + p_size, [&](node x, node y) {
        return x.r < y.r;
    });

    vector<i64> s(n + 1, 0);

    auto add = [&](i64 x, i64 y) {
        for (; x <= n; x += lowbit(x)) {
            s[x] += y;
        }
    };

    auto query = [&](i64 x) {
        i64 res = 0;
        for (; x; x -= lowbit(x)) {
            res += s[x];
        }
        return res;
    };

    for (int i = 1; i <= n; i++) {
        if (!mp[a[i]]) {
            add(i, 1);
            mp[a[i]] = i;
        }
    }

    i64 ans = -1e18;
    for (int i = 0, idx = 1; i < p_size; i++) {
        auto [l, r, x] = p[i];

        while (idx <= r) {
            if (mp[a[idx]] != idx) {
                add(mp[a[idx]], -1);
                add(idx, 1);
                mp[a[idx]] = idx;
            }
            idx++;
        }

        ans = max(ans, query(r) - query(l - 1) - x);
    }

    write(ans, 1);
    st.clear();
    mp.clear();
}

signed main() {
    // cout.tie(nullptr);
    int t = 1;
    read(t);

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
